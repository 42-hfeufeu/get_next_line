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

char	*ft_strjoin(char const *s1, char const *s2)
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
	{
		prod[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		prod[j] = s2[i];
		i++;
		j++;
	}
	prod[j] = '\0';
	return (prod);
}

char	*allocator(char s1, char s2)
{
	char	*gigatxt;
	int		i;

	i = 0;
	while (s2[i] != '\n')
		i++;
	gigatxt = malloc(sizeof(char) * (i + 1));
	i = 0;
	return (ft_strjoin((const char *)s1, (const char *)s2));
}
