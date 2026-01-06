#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

void	test_file(char *filename)
{
	int		fd;
	char	*line;
	int		count;

	printf("\n=== Testing: %s ===\n", filename);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		printf("Error: Could not open file\n");
		return ;
	}
	count = 1;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("Line %d: [%s]\n", count, line);
		free(line);
		count++;
	}
	printf("=== EOF reached (returned NULL) ===\n");
	close(fd);
}

void	test_invalid_fd(void)
{
	char	*line;

	printf("\n=== Testing: Invalid file descriptor (-1) ===\n");
	line = get_next_line(-1);
	if (line == NULL)
		printf("Result: NULL (correct behavior)\n");
	else
	{
		printf("Result: [%s] (unexpected!)\n", line);
		free(line);
	}
}

void	test_stdin(void)
{
	char	*line;

	printf("\n=== Testing: stdin (fd = 0) ===\n");
	printf("Type a line and press Enter (Ctrl+D to end):\n");
	line = get_next_line(0);
	if (line)
	{
		printf("Read from stdin: [%s]\n", line);
		free(line);
	}
}

int	main(int argc, char **argv)
{
	printf("╔═══════════════════════════════════════╗\n");
	printf("║     GET_NEXT_LINE TEST SUITE          ║\n");
	printf("╚═══════════════════════════════════════╝\n");

	// Test 1: Basic file reading
	test_file("text.txt");

	// Test 2: Empty file
	test_file("empty.txt");

	// Test 3: Single line without newline
	test_file("no_newline.txt");

	// Test 4: File with only newlines
	test_file("only_newlines.txt");

	// Test 5: Long line (larger than BUFFER_SIZE)
	test_file("long_line.txt");

	// Test 6: Invalid file descriptor
	test_invalid_fd();

	// Test 7: Non-existent file
	test_file("nonexistent.txt");

	// Test 8: Custom file from argument
	if (argc > 1)
		test_file(argv[1]);

	// Uncomment to test stdin:
	// test_stdin();

	printf("\n╔═══════════════════════════════════════╗\n");
	printf("║     ALL TESTS COMPLETED               ║\n");
	printf("╚═══════════════════════════════════════╝\n");
	return (0);
}
