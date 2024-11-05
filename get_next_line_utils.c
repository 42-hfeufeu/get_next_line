/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:41:57 by hfeufeu           #+#    #+#             */
/*   Updated: 2024/10/17 15:41:59 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*r;

	r = s;
	i = 0;
	while (i < n)
	{
		r[i] = c;
		i++;
	}
	return (r);
}

char	*ft_strdup(char *s)
{
	char	*s1;
	int		i;

	s1 = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (s1 == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		s1[i] = s[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*tmp;
	char	*prod;

	i = 0;
	j = 0;
	tmp = ft_strdup(s1);
	free(s1);
	prod = ft_calloc(1, ((ft_strlen(tmp) + ft_strlen(s2)) + 1));
	if (!prod)
		return (NULL);
	while (tmp[i] != '\0')
		prod[j++] = tmp[i++];
	i = 0;
	while (s2[i] != '\0')
		prod[j++] = s2[i++];
	prod[j] = '\0';
	free(tmp);
	return (prod);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	unsigned int	j;
	char			*des;

	j = 0;
	if ((start + len) > ft_strlen(s))
		len = (ft_strlen(s) - start);
	if (start > ft_strlen(s) || s == NULL)
		return (ft_strdup(""));
	des = malloc(sizeof(char) * (len) + 1);
	if (!des)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		des[0] = '\0';
		return (des);
	}
	while (s[start] != '\0' && j < len)
	{
		des[j] = s[start];
		j++;
		start++;
	}
	des[j] = '\0';
	return (des);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mem;

	if (nmemb && nmemb * size / nmemb != size)
		return (NULL);
	mem = malloc(nmemb * size);
	if (!mem)
		return (NULL);
	mem = ft_memset(mem, 0, (nmemb * size));
	return (mem);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if ((unsigned char)c > 127)
		return ((char *)&s[i]);
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

char	*read_and_concat(int fd, char *bin, char *buffer)
{
	int		bytes;

	bytes = read(fd, buffer, BUFFER_SIZE);
	while (bytes > 0)
	{
		bin = ft_strjoin(bin, buffer);
		if (!bin)
			return (NULL);
		if (ft_strchr(bin, '\n'))
			break;
		bytes = read(fd, buffer, BUFFER_SIZE);
	}
	if (!(bytes <= 0))
		return (bin);
	return (NULL);
}

char	*caller(int fd, char *bin)
{
	char	*buffer;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	if (!bin)
		bin = ft_calloc(1, 1);
	if (!bin)
		return (NULL);
	bin = read_and_concat(fd, bin, buffer);
	free(buffer);
	if (!bin || (bin[0] == '\0' && !ft_strlen(bin)))
	{
		free(bin);
		return (NULL);
	}
	return (bin);
}
