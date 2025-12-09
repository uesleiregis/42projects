#include "libftprintf.h"
#include <stdio.h>
#include <string.h>

int	count_valid_descriptors(char *str, char *descriptors);

int main(void)
{
	char *result;
	
	printf("=== Testando ft_strlen ===\n");
	printf("ft_strlen(\"Hello\"): %zu (esperado: 5)\n", ft_strlen("Hello"));
	printf("strlen(\"Hello\"): %zu\n\n", strlen("Hello"));
	
	printf("=== Testando ft_strchr ===\n");
	result = ft_strchr("Hello World", 'W');
	printf("ft_strchr(\"Hello World\", 'W'): %s\n", result);
	printf("strchr(\"Hello World\", 'W'): %s\n\n", strchr("Hello World", 'W'));
	
	printf("=== Testando ft_strchr com NULL ===\n");
	result = ft_strchr("Hello World", 'Z');
	printf("ft_strchr(\"Hello World\", 'Z'): %s (esperado: (null))\n", result);
	printf("strchr(\"Hello World\", 'Z'): %s\n\n", strchr("Hello World", 'Z'));
	
	printf("=== Testando ft_strchr com \\0 ===\n");
	result = ft_strchr("Hello", '\0');
	printf("ft_strchr(\"Hello\", '\\0'): %p\n", result);
	printf("strchr(\"Hello\", '\\0'): %p\n\n", strchr("Hello", '\0'));
	
	printf("=== Testando count_valid_descriptors ===\n");
	printf("count_valid_descriptors(\"%%s %%d %%c\", \"csd\"): %d (esperado: 3)\n",
		count_valid_descriptors("%s %d %c", "csd"));
	printf("count_valid_descriptors(\"%%%%\", \"csd\"): %d (esperado: 0)\n",
		count_valid_descriptors("%%%%", "csd"));
	printf("count_valid_descriptors(\"%%\", \"csd\"): %d (esperado: 0)\n",
		count_valid_descriptors("%", "csd"));
	
	return (0);
}
