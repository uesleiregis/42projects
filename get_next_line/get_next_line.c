#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#define BUFFER_SIZE 42

//cc get_next_line.c -Wall -Wextra -Werror -D BUFFER_SIZE=42

int ft_strlen(char const *str)
{
	int	i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

// fd = open("text.txt", O_RDONLY);


char *get_next_line(int fd)
{
	char	*buffer;
	ssize_t	bytes;
	int		count;
	char	*rest;

	count = 0;
	buffer  = malloc(BUFFER_SIZE);
	bytes = read(fd, buffer, sizeof(buffer));

	while(buffer[count] != '\n' || buffer[count] != EOF)
	{
		count++;
	}




	return (buffer);
}
