/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfeufeu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:41:52 by hfeufeu           #+#    #+#             */
/*   Updated: 2024/10/17 15:44:02 by hfeufeu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_list {
	char			c;
	struct s_list	*next;
}					t_list;

char	*ft_strchr(const char *s, int c);
void	*ft_calloc(size_t nmemb, size_t size);
int	checkif(char *s1);
char	*caller(int fd, char *bin);
void	*ft_memset(void *s, int c, size_t n);
int	gocheck(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strdup(char *s);
size_t	ft_strlen(char *s);
char	*judgator(char *s1, int bsize);
#endif
