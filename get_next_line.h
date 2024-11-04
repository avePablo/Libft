#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4000
# endif

static char	*get_next_line(int fd);
char	*read_line(int fd, int k);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_bzero(void *s, size_t n);
void	*ft_memset(void *s, int c, size_t n);
char	*ft_substr(char *s, int start, size_t len);
size_t	ft_strlen(char *str);

#endif