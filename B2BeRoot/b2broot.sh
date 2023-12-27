#!/bin/bash
function loading() {
    echo -n "Progress: ["
    for ((i = 1; i <= 10; i++)); do
        echo -n "#"
        sleep 0.1
    done
    echo -e "] 100%\n"
}

function undo_setup() {
    local username=$1
    local monitoring=$2

    if [ "$monitoring" == "yes" ]; then
        # Kullanıcıdan şifre almadan sudo yetkisini geri al
        sudo sed -i "/$username ALL=(ALL) NOPASSWD: \/usr\/local\/bin\/monitoring.sh/d" /etc/sudoers
        # monitoring.sh'yi kaldır
        sudo rm /usr/local/bin/monitoring.sh
        # crontab stop
        sudo service cron stop > /dev/null
    else
        echo "There is no ufw"
    fi
    # Password policy değişikliklerini geri al
    sudo sed -i '/pam_pwquality.so/d' /etc/pam.d/common-password
    sudo sed -i '/PASS_MAX_DAYS 30/d' /etc/login.defs
    sudo sed -i '/PASS_MIN_DAYS 2/d' /etc/login.defs
    # SSH konfigürasyon değişikliklerini geri al
    sudo sed -i 's/^Port 4242/#Port 22/' /etc/ssh/sshd_config
    sudo sed -i 's/^PermitRootLogin no/#PermitRootLogin prohibit-password/' /etc/ssh/sshd_config
    sudo service ssh restart
    # UFW konfigürasyonunu geri al
    sudo ufw delete allow 4242
    sudo ufw disable
    # Sudo'yu kaldır
    sudo apt remove --purge -y sudo
    # SSH'yi ve UFW'yi kaldır
    sudo apt remove --purge -y openssh-server ufw
    # Oluşturulan dosyaları sil
    sudo rm -rf /var/log/sudo

}


# Sudo paket kurulumu ve konfigürasyon
function sudo_command() {
    local username=$1
    echo "Installing sudo for $username..."
    if apt install -y sudo > /dev/null; then
        sudo usermod -aG sudo "$username" > /dev/null
        sed -i "45a\\ $username ALL=(ALL) ALL" /etc/sudoers > /dev/null
        mkdir -p /var/log/sudo && touch /var/log/sudo/sudo.log > /dev/null
        sed -i '14a\Defaults\tlogfile="/var/log/sudo/sudo.log"' /etc/sudoers > /dev/null
        sed -i '14a\Defaults\tbadpass_message="Password is wrong, please try again!"' /etc/sudoers > /dev/null
        sed -i '14a\Defaults\tpasswd_tries=3' /etc/sudoers > /dev/null
        sed -i '14a\Defaults log_input, log_output' /etc/sudoers > /dev/null
        sed -i '14a\Defaults requiretty' /etc/sudoers > /dev/null
        loading
        echo "Sudo installed for $username.\n"
    else
        echo "Error: Sudo installation failed."
        exit 1
    fi
}
#ssh paket kurulumu ve konfigürasyon
function ssh_command() {
    echo "Installing SSH...\n"
    if apt install -y openssh-server > /dev/null; then
        sed -i 's/^#Port 22/Port 4242/' /etc/ssh/sshd_config > /dev/null
        sed -i 's/^#PermitRootLogin prohibit-password/PermitRootLogin no/' /etc/ssh/sshd_config > /dev/null
        sudo service ssh restart > /dev/null
        loading
        echo "SSH installed.\n"
    else
        echo "Error: SSH installation failed."
        exit 1
    fi
}

#ufw paket kurulumu ve konfigürasyon
function ufw_command() {
    echo "Configuring UFW...\n"
    if apt install -y ufw > /dev/null; then
        sudo ufw enable > /dev/null
        sudo ufw allow 4242 > /dev/null
        loading
        echo "UFW configured.\n"
    else
        echo "Error: UFW configuration failed."
        exit 1
    fi
}

#şifre politikaları konfigürasyon
function set_passpolicy() {
    echo "Setting password policy...\n"
    if apt install -y libpam-pwquality > /dev/null; then
        sed -i 's/^password	requisite	pam_deny.so/password requisite pam_pwquality.so retry=3 minlen=10 ucredit=-1 lcredit=-1 dcredit=-1 maxrepeat=3 reject_username difok=7 enforce_for_root/' /etc/pam.d/common-password > /dev/null
        sed -i 's/^PASS_MAX_DAYS 9999/PASS_MAX_DAYS 30/' /etc/login.defs > /dev/null
        sed -i 's/^PASS_MIN_DAYS 0/PASS_MIN_DAYS 2/' /etc/login.defs > /dev/null
        loading
        echo "Password policy set.\n"
    else
        echo "Error: Password policy setup failed."
        exit 1
    fi
}

#monitoring sh kurulumu
function monitoring() {
    local username=$1
    output_file="/usr/local/bin/monitoring.sh"
    sudo service cron start > /dev/null
    cat <<EOF > "$output_file"
#!/bin/bash
arc=\$(uname -a)
pcpu=\$(grep "physical id" /proc/cpuinfo | sort | uniq | wc -l)
vcpu=\$(grep "^processor" /proc/cpuinfo | wc -l)
fram=\$(free -m | awk '\$1 == "Mem:" {print \$2}')
uram=\$(free -m | awk '\$1 == "Mem:" {print \$3}')
pram=\$(free | awk '\$1 == "Mem:" {printf("%.2f"), \$3/\$2*100}')
fdisk=\$(df -BG | grep '^/dev/' | grep -v '/boot$' | awk '{ft += \$2} END {print ft}')
udisk=\$(df -BM | grep '^/dev/' | grep -v '/boot$' | awk '{ut += \$3} END {print ut}')
pdisk=\$(df -BM | grep '^/dev/' | grep -v '/boot$' | awk '{ut += \$3} {ft+= \$2} END {printf("%d"), ut/ft*100}')
cpul=\$(top -bn1 | grep '^%Cpu' | cut -c 9- | xargs | awk '{printf("%.1f%%"), \$1 + \$3}')
lb=\$(who -b | awk '\$1 == "system" {print \$3 " " \$4}')
lvmu=\$(if [ \$(lsblk | grep "lvm" | wc -l) -eq 0 ]; then echo no; else echo yes; fi)
ctcp=\$(ss -neopt state established | wc -l)
ulog=\$(users | wc -w)
ip=\$(hostname -I)
mac=\$(ip link show | grep "ether" | awk '{print \$2}')
cmds=\$(journalctl _COMM=sudo | grep COMMAND | wc -l)
wall "    #Architecture: \$arc
    #CPU physical: \$pcpu
    #vCPU: \$vcpu
    #Memory Usage: \$uram/\${fram}MB (\$pram%)
    #Disk Usage: \$udisk/\${fdisk}Gb (\$pdisk%)
    #CPU load: \$cpul
    #Last boot: \$lb
    #LVM use: \$lvmu
    #Connections TCP: \$ctcp ESTABLISHED
    #User log: \$ulog
    #Network: IP \$ip (\$mac)
    #Sudo: \$cmds cmd"
EOF

    chmod 777 "$output_file"
    sed -i "45a\\ $username ALL=(ALL) NOPASSWD: /usr/local/bin/monitoring.sh" /etc/sudoers
    crontab -l | { cat; echo "*/10 * * * * /usr/local/bin/monitoring.sh"; } | crontab -

}

read -p "Do you want install/uninstall: " name
read -p "Take your username: " username
read -p "Do you want monitoring.ssh yes/no: " monitoring

if [ "$name" == "install" ]; then
    echo "Hello $username"
    sudo_command "$username"
    ssh_command
    ufw_command
    set_passpolicy
    if [ "$monitoring" == "yes" ]; then
        monitoring "$username"
        loading
        echo "monitoring installed"
    else
        echo "Without monitoring."
    fi
    loading
    echo "All processes completed successfully. REBOOT..."
    sleep 2
    sudo reboot
elif  [ "$name" == "uninstall" ]; then
    undo_setup "$username" "$monitoring"
    echo "All processes completed uninstalled... REBOOT..."
    sleep 2
    sudo reboot
else
    echo "Please add an argument $USER"
fi
