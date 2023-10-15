#include <unistd.h>
#include <stdlib.h>

int u_len(char *str)
{
    int i = 0;
    int len = 0;
    while (str[i])
    {
        if(str[i] > 32 && (str[i + 1] == ' ' || str[i + 1] == '\0'))
            len++;
        i++;
    }
    return len;   
}

int s_len(char *str)
{
    int i = 0;
    while (str[i] && str[i] != ' ')
    {
        i++;
    }
    return i;
}

char **ft_split(char *str)
{
    int len = u_len(str);
    char **res;
    int i = 0;
    int slen = 0;
    int s = 0;
    int x = 0;
    res = (char **)malloc(sizeof(char *) * (len + 1));
    if(!res)
        return NULL;
    res[len] = '\0';
    while (s < len)
    {
        while (str[i] && str[i] == ' ')
            i++;
        slen = s_len(str + i);
        res[s] = malloc(sizeof(char) * slen + 1);
        if(!res[s])
            return NULL;
        x = 0;
        while (str[i] && x < slen)
        {
            res[s][x] = str[i];
            i++;
            x++;
        }
        res[s][slen] = '\0';
        s++;
    }
    return res;
}

void ft_putstr(char *str)
{
    int i = 0;
    while (str[i])
    {
        write(1,&str[i],1);
        i++;   
    }
}

#include <stdio.h>
int main(int ac, char **av)
{
    if(ac == 2)
    {
        char **swap;
        swap = ft_split(av[1]);
        int len = 0;
        while (swap[len])
            len++;
        len--;
        while(len >= 0)
        {
            ft_putstr(swap[len]);
            if(len != 0)
                write(1," ",1);
            len--;
        }
    }
    write(1,"\n",1);
}
