#include "get_next_line.h"



char	*get_next_line(int fd)
{
	static int k;
	char *buffer;
	int j;
	int i;
	int bytes_read;
	j = 0;
	 printf("%d\n\n", k);
	i = k;
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (buffer[k + j++] != '\n')
	{
		j++;
	}
    k += j + 1;
	// printf("%d\n", i);
	// printf("%d\n", j);
	// printf("%d\n", k);

	return (ft_substr(buffer, i, j));
}

int	main(void)
{
	int fd;

	fd = open("prueba.txt", O_RDONLY);
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));

	close(fd);
	return (0);
}