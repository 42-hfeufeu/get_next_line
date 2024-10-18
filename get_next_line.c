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
	char			*bin;
	unsigned int	reader;
	int				i;
	static char		*txt;

	i = 0;
	buffer = malloc(BUFFER_SIZE);
	read(fd, buffer, sizeof(buffer));
	bin = malloc(sizeof(char) * reader);
	while (buffer[i] != '\0')
	{
		while (buffer[i])
		{
			bin[i] = buffer[i];
			i++;
		}
		if (gocheck(bin) == 1)
			return (allocator(txt, bin));
		read(fd, buffer, sizeof(buffer));
		i++;
	}
	return (bin);
}

int	main(void)
{
	int	file;
	
	file = open("poem.txt", O_RDWR);
	printf("%s", get_next_line(file));
	printf("%s", get_next_line(file));
	printf("%s", get_next_line(file));
}
