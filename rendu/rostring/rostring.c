#include <stdlib.h>
#include <unistd.h>
int u_len(char *str)
{
    int i = 0;
    int len = 0;
    while (str[i])
    {
        if(str[i] > 32 && (str[i+ 1] == ' ' || str[i+ 1] == '\0'))
            len++;
        i++;
    }  
    return len;
}

int s_len(char *str)
{
    int i = 0;
    while (str[i] && str[i] != ' ')
        i++;
    return i;
}

char **ft_split(char *str)
{
    int i = 0;
    int z = 0;
    int sub = 0;
    int len = u_len(str);
    int slen= 0;
    char **res;

    res = (char **)malloc(sizeof(char *) * (len +1));
    if(!res)
        return NULL;
    res[len] = '\0';
    
    while (sub < len)
    {
        while (str[i] == ' ' && str[i])
            i++;
        slen = s_len(str + i);
        res[sub] = malloc(sizeof(char) * (slen + 1));
        res[sub][slen] = '\0';
        z = 0;
        while (str[i] && z < slen)
        {
            res[sub][z] = str[i];
            i++;
            z++;
        }
        sub++;
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

void ft_rev(char **str, int len)
{
    int i = -1;
    char *swap = str[0];
    while (++i < len)
        str[i - 1] = str[i];
    str[len - 1] = swap;
}
int main(int ac, char **av)
{
    if(ac > 1)
    {
        int len = 0;
        char **split;
        split = ft_split(av[1]);
        while (split[len])
            len++;
        ft_rev(split, len);
        for (int i = 0; i < len; i++)
        {
            ft_putstr(split[i]);
            if(i != len - 1)
                write(1," ",1);
        }
    }
    write(1,"\n",1);
}