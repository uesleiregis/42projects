#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 4096

void display_error(char *message)
{
    int i = 0;
    while (message[i])
        i++;
    write(2, message, i);
}

int main(int argc, char **argv)
{
    int fd;
    char buffer[BUFFER_SIZE];
    int bytes_read;

    if (argc < 2)
    {
        display_error("File name missing.\n");
        return (1);
    }
    if (argc > 2)
    {
        display_error("Too many arguments.\n");
        return (1);
    }
    
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        display_error("Cannot read file.\n");
        return (1);
    }
    
    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        write(1, buffer, bytes_read);
    }
    
    close(fd);
    return (0);
}
