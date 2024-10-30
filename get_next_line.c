#include "get_next_line.h"


// void	buffer_maker(int fd)
// {

// }

char	*read_line(int fd)
{
	char *buffer;
	int bytes_read;
	char *save;
	int i;

	i = 0;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	save = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (buffer[i] != '\n')
	{
		save[i] = buffer[i];
		i++;
	}

	return (save);
}

char	*get_next_line(int fd)
{
	static char *buffer_line;

	buffer_line = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	buffer_line = read_line(fd);
	return (buffer_line);
}

int	main(void)
{
	int fd;

	fd = open("prueba.txt", O_RDONLY);
	printf("%s\n", get_next_line(fd));

	close(fd);
	return (0);
}