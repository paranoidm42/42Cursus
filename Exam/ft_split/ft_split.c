#include <stdlib.h>

int u_len(char *str)
{
    int i = 0;
    int len = 0;
    while (str[i])
    {
        if(str[i] > 32 && ( str[i + 1] == ' ' || str[i + 1] == '\0'))
            len++;
        i++;
    }
    return len;
}

int s_len(char *str)
{
    int i = 0;
    int len = 0;

    while (str[i] && str[i] != ' ')
    {
        len++;
        i++;
    }
    return len;
}

char    **ft_split(char *str)
{
    int len = u_len(str);
    int slen;
    int sub = 0;
    int i = 0;
    int z = 0;

    char **res;

    res = (char **)malloc((len + 1) * sizeof(char *));
    if(!res)
        return NULL;
    res[len] = '\0';

    while (sub < len)
    {
        while (str[i] && str[i] == ' ')
            i++;
        slen = s_len(str + i);
        res[sub] = (char *)malloc(sizeof(char) * (slen + 1));
        if(!res)
            return NULL;
        z = 0;
        while (str[i] && z < slen)
        {
            res[sub][z] = str[i];
            i++;
            z++;
        }
        res[sub][slen] = '\0';
        sub++;
    }
    return res;
}