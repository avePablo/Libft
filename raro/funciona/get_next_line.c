// // #include "get_next_line.h"


// // char	*get_line(int fd, int *i)
// // {
// // 	int 	j;
// // 	char	*line;
// // 	char	*buffer;
// // 	int		bytes_read;

// // 	j = 0;
// // 	line = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
// // 	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
// // 	if (!line)
// // 		return (NULL);
// // 	// bytes_read = read(fd, buffer, BUFFER_SIZE);	
// // 	// buffer[bytes_read] = '\0';
// // 	bytes_read = 1;
// // 	while (bytes_read > 0)
// // 	{
// // 		bytes_read = read(fd, buffer, BUFFER_SIZE);	
// // 	if (buffer[*i] && buffer[*i] != '\n')
// // 	{
// // 		line[j] = buffer[*i];
// // 		(*i)++;
// // 		j++;
// // 	}
// // 	if (buffer[*i] == '\n') 
// // 	{
// //         line[j] = buffer[*i];  
// //         (*i)++;    
// // 		break;           
// //     }
// // 	}
// // 	line[j] = '\0';
// // 	return (line);
// // }

// // char	*get_next_line(int fd)
// // {
// // 	static	char *line;
// // 	static	int len;

// // 	line = get_line(fd, &len);
// // 	return (line);
// // }

// #include "get_next_line.h"

// char *read_line(int fd)
// {
//     char *line;
//     char buffer[BUFFER_SIZE];
//     int bytes_read;
//     int i = 0;

//     line = malloc(sizeof(char) * (BUFFER_SIZE + 1));
//     if (!line)
//         return NULL;

//     while (1)
//     {
//         bytes_read = read(fd, buffer, BUFFER_SIZE);
//         if (bytes_read <= 0)
//         {
//             if (i == 0)
//             {
//                 free(line);
//                 return NULL;
//             }
//             break;
//         }

//         for (int j = 0; j < bytes_read; j++)
//         {
//             if (buffer[j] == '\n')
//             {
//                 line[i] = '\0';
//                 return line;
//             }
//             line[i++] = buffer[j];
//         }
//     }

//     line[i] = '\0';
//     return line;
// }



// char	*get_next_line(int fd)
// {
// 	static int i = 0;
// 	return read_line(fd);
// }


// int	main(void)
// {
// 	int fd;
// 	char *line;

// 	fd = open("prueba.txt", O_RDONLY);
// 	line = get_next_line(fd);
// 	printf("%s\n", line);
// 	free(line);

// 	line = get_next_line(fd);
// 	printf("%s\n", line);
// 	free(line);

// 	line = get_next_line(fd);
// 	printf("%s\n", line);
// 	free(line);

// 	line = get_next_line(fd);
// 	printf("%s\n", line);
// 	free(line);

// 	line = get_next_line(fd);
// 	printf("%s\n", line);
// 	free(line);
// 	close(fd);
// 	return (0);
// }

#include "get_next_line.h"

char *read_line(int fd)
{
    char *line;
    char buffer[BUFFER_SIZE];
    static int buffer_idx;
    static int bytes_read;
    int i = 0;
    int line_size = BUFFER_SIZE;

    line = malloc(sizeof(char) * (line_size + 1)); 
    if (!line)
        return NULL;
    while (1)
    {
        if (buffer_idx == 0)  // Si no hemos leído datos antes, leemos del archivo
        {
            bytes_read = read(fd, buffer, BUFFER_SIZE);
            if (bytes_read <= 0)
            {
                if (i == 0)  // Si no se ha leído nada, devolvemos NULL
                {
                    free(line);
                    return NULL; 
                }
                break;  
            }
        }

        while (buffer_idx < bytes_read)  // Procesamos el buffer
        {
            if (i >= line_size)  // Si la línea es más grande que el tamaño asignado
            {
                line_size += BUFFER_SIZE;  // Aumentamos el tamaño de la línea
                line = realloc(line, line_size + 1);  // Realocamos memoria para la línea
                if (!line)
                    return NULL;  // Si no podemos reasignar memoria, devolvemos NULL
            }

            if (buffer[buffer_idx] == '\n')
            {
                line[i] = '\0';  // Terminamos la línea cuando encontramos un salto de línea
                buffer_idx++;
                return line;
            }
            line[i++] = buffer[buffer_idx++];
        }

        if (buffer_idx == bytes_read)  // Cuando el buffer se haya procesado por completo, reiniciamos
            buffer_idx = 0;
    }

    line[i] = '\0';  // Terminamos la línea
    return line;
}

char *get_next_line(int fd)
{
    return read_line(fd);
}

int main(void)
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


