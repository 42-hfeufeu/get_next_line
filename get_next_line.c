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
	static char		*buffer;
	char			*temp;
	int				i;
	int				j;
	unsigned int	reader;

	i = 0;
	j = 0;
	reader = read(fd, buffer, sizeof(buffer));
	buffer = malloc(sizeof(char) * reader);
	while (buffer[i] != '\0')
	{

		if (buffer[i] == '\n')
		{
			temp = malloc(sizeof(char) * i);
			return (&temp[j]);
			free(temp);
			j = i;
		}
		i++;
	}
	return (NULL);
}

int	main(void)
{
	int	file;
	
	file = open("poem.txt", O_RDWR);
	printf("%s", get_next_line(file));
}
