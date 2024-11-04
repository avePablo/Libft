#include "get_next_line.h"

char	*get_line(char *buffer)
{
	char *line;
	int i;
	line = ft_calloc(ft_strlen(buffer) + 1, sizeof(char));
	i = 0;

	while (buffer[i])
	{
		if (buffer[i] != '\n')
		{
		line[i] = buffer[i];
		i++;
		}
		else 
		break;
	}
	
	return(line);
}

char	*get_next_line(int fd)
{
int bytes_read;
char *buffer;
static int i;
i = 0;
buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
bytes_read = read(fd, buffer, BUFFER_SIZE);

return(get_line(buffer));
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

