/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:14:29 by hfeufeu           #+#    #+#             */
/*   Updated: 2024/10/17 15:50:12 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*bin;
	char		*tmp;
	char		*txt;
	int			i;

	bin = caller(fd, bin);
	if (!bin)
		return (NULL);
	i = 0;
	while (bin[i] && bin[i] != '\n')
		i++;
	if (bin[i] == '\n' || bin[i] == '\0')
	{
		tmp = ft_strdup(bin);
		free(bin);
		txt = ft_substr(tmp, 0, (i + 1));
		bin = ft_substr(tmp, (i + 1), ft_strlen(tmp) - i);
		free(tmp);
		return (txt);
	}
	return (NULL);
}
/*
int	main(void)
{
	int	file;

	file = open("poem.txt", O_RDWR);
	printf("%s", get_next_line(file));
	printf("%s", get_next_line(file));
}*/
