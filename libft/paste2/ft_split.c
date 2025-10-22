#include "libft.h"

static int ft_strlen(char *str)
{
	int i;

    i = 0;
    while(*str)
	{
		str ++;
 		i ++;
	}
	return (i);
}


void    str_fill(char *str, char c)
{
    int     i;

    i = 0;
    if(!str)
        return;
    while(str[i])
    {
        str[i] = c;
        i++;
    }
    str[i] = c;
}

char    *ft_strtrim_char(char const *s1, char const set)
{
    char    *s;
    int     i;
    int     start;
    int     end;
    
    
    start = 0;
    if (!s1)
        return (NULL);

    while (s1[start] && s1[start] == set)
        start++;

    end = ft_strlen((char *) s1);


    while (end > start && s1[end - 1] == set)
        end--;

    s = (char *)malloc(sizeof(char) * (end - start + 1));
    if (!s)
        return (NULL);

    i = 0;
    while (start < end)
        s[i++] = s1[start++];
    s[i] = '\0';

    return (s);
}

int my_count_words(char *str, char c)
{
    int     count_w;
    int     flag;

    flag = 0;
    count_w = 0;
    if(!str)
        return (0);
    while(*str)
    {
        if(*str != c && flag == 0)
        {
            flag = 1;
            count_w++;
        }
        else if (*str == c)
            flag = 0;
        str++;
    }
    return (count_w);
}

char    *first_word_c(int start, char *str, char c)
{
    char    *first_word;
    int     end;
    int     size_word;
    int     flag;
    int     temp_start;
    int     i;

    if (!str || start < 0 || start >= ft_strlen(str))
        return (NULL);
    size_word = 0;
    flag = 0;
    end = -1;
    i = 0;
    temp_start = start;
    while (str[start])
    {
        if (str[start] != c)
        {
            if (flag == 0)
                flag = 1;
            size_word++;
        }
        else if (flag == 1)
        {
            end = start;
            break ;
        }
        start++;
    }
    if (flag == 1 && end == -1)
        end = start;
    if (flag == 0)
        return (NULL);
    first_word = malloc(sizeof(char) * (size_word + 1));
    if (!first_word)
        return (NULL);
    i = 0;
    while (temp_start < end)
        first_word[i++] = str[temp_start++];
    first_word[i] = '\0';
    return (first_word);
}


char **ft_split(char const *s, char c)
{
    char    **res;
    char    *s_trim;
    int     words;
    int     i;
    char    *temp;
    int     start;

    start = 0;
    s_trim = ft_strtrim_char(s, c);
    if (!s_trim)
        return (NULL);

    words = my_count_words(s_trim, c);
    res = malloc((words + 1) * sizeof(char *));
    if (!res)
    {
        free(s_trim);  // MELHORIA: liberar s_trim em caso de falha para evitar vazamento de memória
        return (NULL);
    }

    i = 0;
    while (i < words)
    {
        temp = first_word_c(start, s_trim, c);
        if (!temp)
        {
            // MELHORIA: liberar todas as strings já alocadas em res antes de retornar NULL
            // para evitar vazamento de memória
            while (i > 0)
                free(res[--i]);
            free(res);
            free(s_trim);
            return (NULL);
        }
        res[i] = temp;

        // MELHORIA: ajustar start para avançar além do separador(es) para evitar loops infinitos
        start += ft_strlen(temp);
        while (s_trim[start] && s_trim[start] == c)
            start++;

        i++;
    }
    res[i] = NULL;
    free(s_trim);
    return (res);
}

#include <stdio.h>
int main()
{
    char **temp = ft_split("Mamae-eu quero-me casar", '-');
    int i = 0;
    while(temp[i])
    {
        printf("%s\n",temp[i]);
        i++;
    }
    return (0);
}




// char    **ft_split(char const *s, char c)
// {
//     char    **res;
//     char    *s_trim;
//     char    *temp;
//     int     start;

//     start = 0;
//     //tratar s com ft_strtrim
//     s_trim = ft_strtrim_char(s, c);
//     if(!s_trim)
//         return (NULL);
    
//     // percorro s_trim
//     // e vou salvando em *temp até encontrar um separador
//         // quando encontrar um separador, 
//             //guardo temp em **res
//             // apago temp
//     // procuro o proximo caractere
//         // encontro
//         // salvo em temp


//         // aloco temp e zero todos os elementos
//         temp = malloc(ft_strlen(s_trim)+1);
//         if(!temp)
//             return (NULL);
//         str_fill(temp, '\0');

//         // preencho com a primeira palavra até o separador
//         while(s_trim[start] &&  s_trim[start] != c)
//         {
//             temp[start] = s_trim[start];
//             start++;
//         }
//         //guardo na posição 0 do array de strings.
//         // res = mallod((ft_strlen(temp) + 1) * (my_count_words(s_trim) + 1));

// }

