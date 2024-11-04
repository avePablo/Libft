#include "get_next_line.h"


void	*ft_calloc(size_t nmemb, size_t size)
{
	void *ptr;

	ptr = (void *)malloc(nmemb * size);
	if (!ptr)
	{
		return (NULL);
	}
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

void	*ft_bzero(void *s, size_t n)
{
	char *pt;
	size_t i;

	pt = (char *)s;
	i = 0;
	if (n == 0)
	{
		return (pt);
	}
	while (i < n)
	{
		pt[i] = '\0';
		i++;
	}
	return (pt);
}

// void	*ft_memset(void *s, size_t n)
// {
// 	char	*pt;
// 	size_t	i;

// 	pt = (char *)s;
// 	i = 0;
// 	if (n == 0)
// 	{
// 		return (pt);
// 	}
// 	while (i < n)
// 	{
// 		pt[i] = '\0';
// 		i++;
// 	}
// 	return (pt);
// }

// todo esto de abajo es del substr

// char	*d_less_len(char *dest, const char *s, unsigned int start,
// 		size_t len)
// {
// 	size_t	d;

// 	d = 0;
// 	while (d < len)
// 	{
// 		dest[d] = s[start + d];
// 		d++;
// 	}
// 	dest[d] = '\0';
// 	return (dest);
// }

// char	*ft_substr(char *s, int start, size_t len)
// {
// 	char	*dest;

// 	if (s == NULL)
// 		return (NULL);
// 	if (start >= ft_strlen(s))
// 	{
// 		dest = malloc(1 * sizeof(char));
// 		if (dest == NULL)
// 			return (NULL);
// 		dest[0] = '\0';
// 		return (dest);
// 	}
// 	if ((start + len) > ft_strlen(s))
// 		len = ft_strlen(s) - start;
// 	dest = malloc((len + 1) * sizeof(char));
// 	if (dest == NULL)
// 		return (NULL);
// 	d_less_len(dest, s, start, len);
// 	return (dest);
// }

size_t	ft_strlen(char *str)
{
	size_t len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[j + i] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	// printf("dest: %s\n", dest);
	return (dest);
}