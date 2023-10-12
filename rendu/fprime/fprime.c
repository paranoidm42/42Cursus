#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
    if(ac == 2)
    {
        int num = atoi(av[1]);
        if(num == 1)
            printf("%d",num);
        int i = 2;
        while (num >= i)
        {   
            if(num % i == 0)
            {
                printf("%d",i);
                if(num == i)
                    break;
                printf("*");
                num /= i;
                i = 2;
            }
            i++;
        }
    }
    printf("\n");
}