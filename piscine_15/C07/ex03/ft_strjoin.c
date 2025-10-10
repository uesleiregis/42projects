/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uregis-d <uregis-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 21:40:11 by uregis-d          #+#    #+#             */
/*   Updated: 2025/09/19 22:05:15 by uregis-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// size »» o número de 

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return i;
}

char *ft_strcpy(char *dest, char *src)
{
    int i;
    
    i = 0;
    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

char *ft_strcat(char *dest, char *src)
{
    int i = 0;
    int j = 0;

    while (dest[i])
        i++;
    while (src[j])
    {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';
    return dest;
}

char *ft_strjoin(int size, char **strs, char *sep)
{
    int total_len = 0;
    int i;
    char *result;

    if (size == 0)
    {
        result = (char *)malloc(1);
        if (result == NULL)
            return NULL;
        result[0] = '\0';
        return result;
    }

    // calcular tamanho necessário
    i = 0;
    while (i < size)
    {
        total_len += ft_strlen(strs[i]);
        i++;
    }
    total_len += (size - 1) * ft_strlen(sep);
    total_len += 1; // para o '\0'

    result = (char *)malloc(total_len * sizeof(char));
    if (result == NULL)
        return NULL;

    // construir string final
    result[0] = '\0';
    i = 0;
    while (i < size)
    {
        ft_strcat(result, strs[i]);
        if (i < size - 1)
            ft_strcat(result, sep);
        i++;
    }

    return result;
}


int main(void)
{
    char *result;
    char *strs1[] = {"Hello", "world", "42"};
    char *strs2[] = {"um", "dois", "tres", "quatro"};
    char *strs3[] = {};

    // Teste 1
    result = ft_strjoin(3, strs1, " - ");
    printf("Resultado 1: \"%s\"\n", result);
    free(result);

    // Teste 2
    result = ft_strjoin(4, strs2, ", ");
    printf("Resultado 2: \"%s\"\n", result);
    free(result);

    // Teste 3 (size = 0)
    result = ft_strjoin(0, strs3, " | ");
    printf("Resultado 3: \"%s\"\n", result);
    free(result);

    return 0;
}