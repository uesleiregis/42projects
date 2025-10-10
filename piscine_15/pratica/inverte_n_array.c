// funcao que inverte a ordem das strings de um array de strings
// o programa retorna os n primeiros elementos invertidos.
#include<stdio.h>
#include<stdlib.h>

char    **inverte_n_array(char **arr, int n)
{
    int     count;
    int     i;
    char    **res;

    i = 0;
    count = 0;
 
    if(n <= 0)
        return (NULL);
    while(arr[count] != NULL && count < n)
    {
        count++;
    }
    res = malloc((count+1) * sizeof(char *));
    count--;
    while(count >= 0)
    {
        res[i] = arr[count];
        i++;
        count--;
    }
    res[i] = NULL;
    return (res);
}

int main()
{
    char    *inverter[] = {"Amo", "Viajar", "Tanto", NULL};
    char    **x;
    int     i;
    
    i = 0;
    x = inverte_n_array(inverter, 2);
    while (x[i] != NULL)
        printf("%s\n",x[i++]);
    free(x);

    return (0);
}

