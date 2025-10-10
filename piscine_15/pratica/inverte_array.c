// funcao que inverte a ordem das strings de um array de strings
#include<stdio.h>
#include<stdlib.h>

char    **f_inverter(char **arr)
{
    int     count;
    int     i;
    char    **res;

    i = 0;
    count = 0;
    while (arr[count] != NULL)
    {
        count++;
    }
    res = malloc((count+1) * sizeof(char *));
    count--;
    while (count >= 0)
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
    x = f_inverter(inverter);
    while (x[i] != NULL)
        printf("%s\n",x[i++]);
    free(x);

    return (0);
}
