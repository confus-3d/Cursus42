/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-los- <fde-los-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 23:25:21 by fde-los-          #+#    #+#             */
/*   Updated: 2023/09/26 16:43:41 by fde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*ft_strchr(const char *s, int c);
int		ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_bzero(char *s, size_t n);

int		ft_free(char **string);
int		get_next_read(int fd, char *buffer, char **copytext);
int		get_next_jump(char **copytext, char **line);
int		remove_last_line(char **copytext, char **line);
char	*get_next_line(int fd);

#endif
