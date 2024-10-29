#include "get_next_line.h"

// void	buffer_maker(int fd)
// {


	

// }

static char		*read_line(int fd)
{
    static int count;
	char	*buffer;
	int bytes_read;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while()
	{
		
	}
	
	return (buffer);
}

char    *get_next_line(int fd)
{
    char    *buffer_line;
 
    buffer_line = read_line(fd);
    return (buffer_line);
}

int main() 
{
    int fd;

    fd = open("prueba.txt", O_RDONLY);
	printf("%s\n", get_next_line(fd));
    close(fd);
    return (0);
}