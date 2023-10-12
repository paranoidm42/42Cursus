#include <stdlib.h>

char    *ft_itoa(int nbr)
{
    int snbr = nbr;
    int len = 0;
    if(nbr == 0)
        return ("0\0");
    char *res;
    while (snbr)
    {
        snbr /= 10;
        len++;
    }
    if(nbr < 0)
        len++;
    res = malloc(sizeof(char) * (len + 1));
    if(!res)
        return NULL;
    if(nbr < 0)
    {
        res[0] = '-';
        nbr *= -1;
    }
    res[len] = '\0';
    len--;
    while (nbr)
    {
        res[len] = nbr % 10 + '0';
        nbr /= 10;
        len--;
    }
    return res;       
}