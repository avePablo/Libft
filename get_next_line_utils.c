#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

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
	char	*pt;

	pt = (char *)s;
	pt = ft_memset(s, '\0', n);
	return (pt);
}

void	*ft_memset(void *s, int c, size_t n)
{
	char	*pt;
	size_t	i;

	pt = (char *)s;
	i = 0;
	if (n == 0)
	{
		return (pt);
	}
	while (i < n)
	{
		pt[i] = c;
		i++;
	}
	return (pt);
}