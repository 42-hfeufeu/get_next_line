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

size_t ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
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

int	gocheck(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	int		i;
	int		j;
	char	*prod;

	i = 0;
	j = 0;
	prod = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (prod == NULL)
		return (NULL);
	while (s1[i] != '\0')
		prod[j++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		prod[j++] = s2[i++];
	prod[j] = '\0';
	free(s1);
	return (prod);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
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

char	*judgator(char *s1, int bsize)
{
	free (s1);
	if (!s1)
	{
		s1 = malloc(sizeof(char) * bsize + 1);
		return (s1);
	}
	return (NULL);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mem;

	if (nmemb && nmemb * size / nmemb != size)
		return (NULL);
	mem = malloc (nmemb * size);
	if (!mem)
		return (NULL);
	mem = ft_memset(mem, 0, (nmemb * size));
	return (mem);
}

/*
void	*freezator(char *s)
{

}*/
