#include "get_next_line.h"

char	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

char	*clean_storage(char *storage)
{
	char	*new_storage;
	char	*ptr;
	int		len;

	ptr = ft_strchr(storage, '\n');
	if (!ptr)
	{
		new_storage = NULL;
		return (ft_free(&storage));
	}
	else
		len = (ptr - storage) + 1;
	if (!storage[len])
		return (ft_free(&storage));
	new_storage = ft_substr(storage, len, ft_strlen(storage) - len);
	ft_free(&storage);
	if (!new_storage)
		return (NULL);
	return (new_storage);
}

char	*new_line(char *storage)
{
	char	*line;
	char	*ptr;
	int		len;

	ptr = ft_strchr(storage, '\n');
	len = (ptr - storage) + 1;
	line = ft_substr(storage, 0, len);
	if (!line)
		return (NULL);
	return (line);
}

char	*readbuf(int fd, char *storage)
{
	int		bytes_read;
	char	*buffer;

	bytes_read = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (ft_free(&storage));
	buffer[0] = '\0';
	while (bytes_read > 0 && !ft_strchr(buffer, '\n'))
	{
		bytes_read = read (fd, buffer, BUFFER_SIZE);
		if (bytes_read > 0)
		{
			buffer[bytes_read] = '\0';
			storage = ft_strjoin(storage, buffer);
		}
	}
	free(buffer);
	if (bytes_read == -1)
		return (ft_free(&storage));
	return (storage);
}

char	*get_next_line(int fd)
{
	static char	*storage = {0};
	char		*line;

	if (fd < 0)
		return (NULL);
	if ((storage && !ft_strchr(storage, '\n')) || !storage)
		storage = readbuf (fd, storage);
	if (!storage)
		return (NULL);
	line = new_line(storage);
	if (!line)
		return (ft_free(&storage));
	storage = clean_storage(storage);
	return (line);
}


// char	*get_next_line(int fd)
// {
// 	char	buffer[BUFFER_SIZE + 1];
// 	int		bytes_read;
// 	int 	i;
// 	static char *line;

// 	i = 0;
// 	bytes_read = 0;
	
// 	 if (!line)
//     {
//         line = malloc(1);  // Inicializa `line` para que no sea NULL
//         if (!line) 
// 			return NULL;  // Manejo de error
//         line[0] = '\0';
//     }

// 	while (read(fd, buffer, BUFFER_SIZE) > 0)
// 	{
// 		line = ft_strcat(line, buffer);
// 		if (ft_strchr(buffer, '\n') != 0)
// 		{
// 			break;
// 		}
// 	}
	
	
// 	// printf("buffer:%s\n",buffer);
// 	// printf("line:%s\n",line);
// 	return (line);


// }

int	main(void)
{
	int fd;
	char *line;

	fd = open("prueba.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
	// free(line);

	line = get_next_line(fd);
	printf("%s", line);
	// free(line);

	line = get_next_line(fd);
	printf("%s", line);
	// free(line);

	line = get_next_line(fd);
	printf("%s", line);
	// free(line);

	line = get_next_line(fd);
	printf("%s", line);
	// free(line);
	close(fd);
	return (0);
}
