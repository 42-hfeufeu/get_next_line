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
	char			*buffer;
	int				reader;
	static char		*bin;
	unsigned int	i;
	char			*txt;

	i = 0;
	buffer = malloc(BUFFER_SIZE);
	reader = read(fd, buffer, BUFFER_SIZE);
	txt = malloc(sizeof(char) * BUFFER_SIZE);
	if (!bin)
		bin = malloc(sizeof(char) * reader);
	while (i < 100)
	{
		bin = ft_strjoin(bin, buffer);
		if (!bin)
			return (NULL);
		while (bin[i])
		{
			txt[i] = bin[i];
			if (bin[i] == '\n')
			{
				bin = ft_substr(bin, (i + 1), (ft_strlen(bin) - i));
				return (txt);
			}
			i++;
		}
		free(buffer);
		buffer = malloc(BUFFER_SIZE);
		if (!buffer)
			return (NULL);
		read(fd, buffer, BUFFER_SIZE);
	}
	return (NULL);
}

int	main(void)
{
	int	file;
	
	file = open("poem.txt", O_RDWR);
	printf("%s", get_next_line(file));
	printf("%s", get_next_line(file));
}
