*This project has been created as part of the 42 curriculum by uregis-d.*

# Get Next Line

## Description

The main goal of the **get_next_line** project is to implement a function that reads and returns a single line from a file descriptor, one call at a time. This project introduces the concept of **static variables** in C, which are essential for preserving state between function calls — in this case, keeping track of leftover data from previous reads.

The project also provides hands-on practice with the `read()` system call, which reads a specified number of bytes (defined by `BUFFER_SIZE`) from a file descriptor. The challenge lies in reading data in chunks while returning content line by line, regardless of buffer size.

### Algorithm Explanation

The algorithm works as follows:

1. **Validation**: Check if the file descriptor and buffer size are valid.
2. **Reading Loop**: Use `read()` to fill a buffer with `BUFFER_SIZE` bytes at a time, concatenating each read into a static variable (`resto`) until a newline (`\n`) is found or EOF is reached.
3. **Line Extraction**: Once a newline is found, extract everything from the beginning up to and including the `\n`.
4. **Update Remainder**: Store whatever comes after the newline in the static variable for the next function call.
5. **Return**: Return the extracted line, or `NULL` if EOF is reached with no remaining content.

**Why this approach?** The static variable is crucial because `read()` may read more data than a single line contains. Without preserving this "leftover" data between calls, we would lose parts of subsequent lines. This design allows `get_next_line` to be called repeatedly, returning one line at a time until the entire file is read.

## Instructions

### Compilation

To compile the project with the test file:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c -o gnl
```

> **Note:** The `BUFFER_SIZE` can be changed at compile time to test different read chunk sizes.

### Execution

To display the file contents and run the program:

```bash
cat text.txt && echo "---" && ./gnl
```

> **Important:** Ensure test files (e.g., `text.txt`) are in the same directory as the executable before running.

## Resources

### Documentation & References
- [GNU C Library - File Descriptor Operations](https://www.gnu.org/software/libc/manual/html_node/Low_002dLevel-I_002fO.html)
- [read() man page](https://man7.org/linux/man-pages/man2/read.2.html)
- [Static Variables in C](https://www.geeksforgeeks.org/static-variables-in-c/)

### AI Usage
Generative AI tools (Perplexity, GitHub Copilot) were used for:
- **Concept clarification**: Generating examples to better understand static variables and file descriptor behavior.
- **Debugging assistance**: Identifying memory leaks and edge cases.
- **Code review**: Analyzing the implementation for potential improvements.

The core logic and implementation were developed independently, with AI serving as a learning aid and reference tool.

## Edge Cases Handled

| Edge Case | Expected Behavior | Status |
|-----------|-------------------|--------|
| Empty file | Return `NULL` immediately | ✅ |
| File without `\n` at the end | Return the last line without `\n` | ✅ |
| File with only newlines | Return each `\n` as a separate line | ✅ |
| Line longer than `BUFFER_SIZE` | Handle multiple reads correctly | ✅ |
| Invalid file descriptor (`-1`) | Return `NULL` | ✅ |
| Non-existent file | Return `NULL` (handled by `open()`) | ✅ |
| Multiple consecutive calls | Return lines sequentially | ✅ |
| `BUFFER_SIZE = 1` | Work correctly (slow but functional) | ✅ |
| Very large `BUFFER_SIZE` | Work correctly | ✅ |

## Test Files

The test files below can be placed in the project directory for testing purposes.

### main.c

```c
/*
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
	printf("========================================\n");
	printf("     GET_NEXT_LINE TEST SUITE          \n");
	printf("========================================\n");

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

	printf("\n========================================\n");
	printf("     ALL TESTS COMPLETED               \n");
	printf("========================================\n");
	return (0);
}
*/
```

### text.txt

```plaintext
/*
Esse texto foi lido corretamente?
Linha
Por
Linha?
E o que acontece com \n?
Vejamos\n o q\nue \nacontece.
*/
```

### Creating Additional Test Files

To create the additional test files, run the following commands:

```bash
# Empty file
echo "" > empty.txt

# Single line without newline at the end
echo -n "Single line no newline" > no_newline.txt

# File with only newlines
printf "\n\n\n" > only_newlines.txt

# Long line (larger than BUFFER_SIZE)
printf "This is a very long line that should be longer than the default BUFFER_SIZE of 42 bytes to test if the function handles lines that span multiple read calls correctly. Lorem ipsum dolor sit amet, consectetur adipiscing elit.\n" > long_line.txt
```
