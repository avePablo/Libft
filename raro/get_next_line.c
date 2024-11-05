#include "get_next_line.h"


char	*get_line(int *i, char buffer[])
{
	int j;
	char *line;

	j = 0;
	line = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!line)
		return (NULL);
	while (buffer[*i] && buffer[*i] != '\n')
	{
		line[j] = buffer[*i];
		(*i)++;
		j++;
	}
	if (buffer[*i] == '\n') 
	{
        line[j] = buffer[*i];  
        (*i)++;                
    }
	line[j] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	int bytes_read;
	static char buffer[BUFFER_SIZE + 1];
	char *line;
	static int len;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	buffer[bytes_read] = '\0';

	line = get_line(&len, buffer);

	return (line);
}

int	main(void)
{
	int fd;
	char *line;

	fd = open("prueba.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s\n", line);
	free(line);

	line = get_next_line(fd);
	printf("%s\n", line);
	free(line);

	line = get_next_line(fd);
	printf("%s\n", line);
	free(line);

	line = get_next_line(fd);
	printf("%s\n", line);
	free(line);

	line = get_next_line(fd);
	printf("%s\n", line);
	free(line);
	close(fd);
	return (0);
}
