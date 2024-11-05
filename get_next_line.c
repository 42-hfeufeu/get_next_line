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

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*mem;
	size_t	i;

	i = 0;
	if (nmemb && nmemb * size / nmemb != size)
		return (NULL);
	mem = malloc(nmemb * size);
	if (!mem)
		return (NULL);
	while (i < (nmemb * size))
	{
		mem[i] = 0;
		i++;
	}
	return (mem);
}

char	*read_and_concat(int fd, char *bin, char *buffer, int bytes)
{
	int	read_bytes;

	while (bytes > 0)
	{
		buffer[bytes] = '\0';
		bin = ft_strjoin(bin, buffer);
		if (!bin)
			return (NULL);
		if (ft_strchr(bin, '\n'))
			break ;
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes < 0)
		{
			free(bin);
			return (NULL);
		}
		bytes = read_bytes;
	}
	if (bytes == 0 && (!bin || bin[0] == '\0'))
	{
		free(bin);
		return (NULL);
	}
	return (bin);
}

char	*caller(int fd, char *bin, int bytes, char *buffer)
{
	if (bytes < 0 && buffer[0] == '\0')
	{
		free(buffer);
		free(bin);
		return (NULL);
	}
	if (!bin)
		bin = ft_calloc(1, 1);
	if (!bin)
		return (NULL);
	bin = read_and_concat(fd, bin, buffer, bytes);
	free(buffer);
	if (!bin || (bin[0] == '\0' && !ft_strlen(bin)))
	{
		free(bin);
		return (NULL);
	}
	return (bin);
}

char	*get_bytes(int fd, char *bin)
{
	int		bytes;
	char	*buffer;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	bytes = read(fd, buffer, BUFFER_SIZE);
	bin = caller(fd, bin, bytes, buffer);
	if (!bin)
		return (NULL);
	return (bin);
}

char	*get_next_line(int fd)
{
	static char	*bin;
	char		*tmp;
	char		*txt;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	bin = get_bytes(fd, bin);
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
