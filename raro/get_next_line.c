#include "get_next_line.h"


char	*get_line(int i, char buffer[])
{
	int j;
	char *line;

	j = 0;
	line = ft_calloc(ft_strlen(buffer) + 1, sizeof(char));

	while (buffer[i] && buffer[i] != '\n')
	{
		line[j] = buffer[i];
		i++;
		j++;
	}
	line[j] = '\0';
	// printf("line: %s\n", line);
	return (line);
}

char	*get_next_line(int fd)
{
	int bytes_read;
	char buffer[BUFFER_SIZE + 1];
	char *line;
	static int len;

	// printf("len: %d\n", len);

	// buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	line = ft_calloc(BUFFER_SIZE + 1, sizeof(char));

	line = ft_strcat(line, get_line(len, buffer));
	len += ft_strlen(line) + 1;
	// printf("len: %d\n", len);
	return (line);
}

int	main(void)
{
	int fd;

	fd = open("prueba.txt", O_RDONLY);

	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	close(fd);
	return (0);
}
