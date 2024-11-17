#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	c;

	if (!s1)
	{
		s1 = malloc(sizeof(char) + 1);
		if (!s1)
			return (0);
		s1[0] = 0;
	}
	str = (char *)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (ft_free(&s1));
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	c = -1;
	while (s2[++c])
		str[i + c] = s2[c];
	str[i + c] = '\0';
	free(s1);
	return (str);
}


char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return (&((char *)s)[i]);
		i++;
	}
	if ((char)c == '\0')
		return (&((char *)s)[i]);
	return (0);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*res;

	i = 0;
	if (!s)
		return (0);
	if (start > ft_strlen(s))
	{
		res = malloc(sizeof(char) * (1));
		if (!res)
			return (NULL);
		res[0] = '\0';
		return (res);
	}
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	while (start < ft_strlen(s) && i < len && s[start])
		res[i++] = s[start++];
	res[i] = '\0';
	return (res);
}

size_t	ft_strlen(char *str)
{
	size_t len;

	len = 0;
	if (!str)
		return (0);
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

// void	*ft_calloc(size_t nmemb, size_t size)
// {
// 	void *ptr;

// 	ptr = (void *)malloc(nmemb * size);
// 	if (!ptr)
// 	{
// 		return (NULL);
// 	}
// 	ft_bzero(ptr, nmemb * size);
// 	return (ptr);
// }

// void	*ft_bzero(void *s, size_t n)
// {
// 	char *pt;
// 	size_t i;

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

// char	ft_strchr(const char *s, char c)
// {
// 	unsigned int	i;
// 	char			*str;

// 	str = (char *)s;
// 	i = 0;
// 	while (str[i] != '\0')
// 	{
// 		if (str[i] == (char)c)
// 		{
// 			return (str[i]);
// 		}
// 		i++;
// 	}
// 	if ((char)c == '\0')
// 		return (str[i]);
// 	return (0);
// }

// char	*ft_strcat(char *dest, char *src)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	j = 0;
// 	if (!dest)
// 		return (src);
// 	while (dest[i])
// 		i++;
// 	while (src[j])
// 	{
// 		dest[j + i] = src[j];
// 		j++;
// 	}
// 	dest[i + j] = '\0';
// 	return (dest);
// }

// char	*ft_strlcpy(char *dst, const char *src)
// {
// 	size_t	i;

// 	i = 0;
// 	while (src[i])
// 	{
// 		dst[i] = src[i];
// 		i++;
// 	}
// 	dst[i] = '\0';
// 	return (dst);
// }

// char	*ft_strdup(const char *s)
// {
// 	int		len;
// 	char	*pt;
// 	char	*s1;

// 	s1 = (char *)s;
// 	len = 0;
// 	while (s1[len] != '\0')
// 	{
// 		len++;
// 	}
// 	pt = (char *)malloc(sizeof(char) * len + 1);
// 	if (!pt)
// 	{
// 		return (NULL);
// 	}
// 	len = 0;
// 	while (s1[len] != '\0')
// 	{
// 		pt[len] = s1[len];
// 		len++;
// 	}
// 	pt[len] = '\0';
// 	return (pt);
// }
