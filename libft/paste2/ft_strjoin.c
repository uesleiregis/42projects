

#include "libft.h"

static int	ft_strlen(char *str);
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int	i;
	int	j;

	str =(char *)malloc(sizeof(char) * (ft_strlen((char *) s1) + ft_strlen((char *) s2) + 1));
	if(!str)
		return (NULL);
	if(!s1 || !s2)
		return (NULL);
	i = 0;
	while(s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while(s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	
	return (str);

}

static int ft_strlen(char *str)
{
	int count = 0;

    while(*str != '\0')
	{
		str ++;
 		count ++;
	}
	return (count);
}
// #include <stdio.h>
// int	main()
// {
// 	printf("%s", ft_strjoin("\n\t\tMaria", " das Graças\n\n"));
// 	return (0);
// }
