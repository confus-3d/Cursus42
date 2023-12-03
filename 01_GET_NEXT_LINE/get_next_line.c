/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-los- <fde-los-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 19:50:29 by fde-los-          #+#    #+#             */
/*   Updated: 2023/11/04 17:10:31 by fde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_free(char **string)
{
	free(*string);
	*string = NULL;
	return (-1);
}

int	get_next_read(int fd, char *buffer, char **copytext)
{
	char	*temp;
	int		flag;

	ft_bzero(buffer, BUFFER_SIZE + 1);
	flag = read(fd, buffer, BUFFER_SIZE);
	if (flag < 0 || buffer == NULL)
		return (ft_free(copytext));
	if (flag == 0)
		return (flag);
	temp = ft_strjoin(*copytext, buffer);
	if (temp == NULL)
		return (ft_free(copytext));
	free(*copytext);
	*copytext = temp;
	return (flag);
}

int	get_next_jump(char **copytext, char **line)
{
	char	*nextline;
	int		len;
	int		counter;

	nextline = ft_strchr(*copytext, '\n');
	if (nextline != NULL)
		len = ft_strlen(*copytext) - ft_strlen(nextline) + 2;
	else
		len = ft_strlen(*copytext) - ft_strlen(nextline) + 1;
	*line = (char *) malloc (len * sizeof(char));
	if (*line == NULL)
		return (ft_free(copytext));
	counter = 0;
	while (counter < len - 1)
	{
		(*line)[counter] = (*copytext)[counter];
		counter++;
	}
	(*line)[counter] = '\0';
	return (0);
}

int	remove_last_line(char **copytext, char **line)
{
	char	*nextline;
	char	*swap;
	int		counter1;
	int		counter2;

	nextline = ft_strchr(*copytext, '\n');
	if (nextline == NULL)
		ft_free(copytext);
	if (nextline == NULL)
		return (0);
	swap = (char *) malloc (ft_strlen(nextline) * sizeof(char));
	if (swap == NULL)
		ft_free(copytext);
	if (swap == NULL)
		return (ft_free(line));
	counter1 = 0;
	counter2 = ft_strlen(*copytext) - ft_strlen(nextline) + 1;
	while (counter2 < ft_strlen(*copytext))
		swap[counter1++] = (*copytext)[counter2++];
	swap[counter1] = '\0';
	free(*copytext);
	*copytext = swap;
	if (**copytext == 0)
		ft_free(copytext);
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*copytext;
	char		*buffer;
	char		*line;
	int			flag;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
	{
		if (copytext != NULL)
			ft_free(&copytext);
		return (NULL);
	}
	flag = 1;
	while (ft_strchr(copytext, '\n') == NULL && flag > 0)
		flag = get_next_read(fd, buffer, &copytext);
	free(buffer);
	buffer = NULL;
	if (flag == -1 || ft_strlen(copytext) == 0
		|| get_next_jump(&copytext, &line) == -1
		|| remove_last_line(&copytext, &line) == -1)
		return (NULL);
	return (line);
}
/*
int main(int argc, char **argv)
{
	int	fd;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		printf("%s", get_next_line(fd));
		printf("%s", get_next_line(fd));
		printf("%s", get_next_line(fd));
		printf("%s", get_next_line(fd));
		printf("%s", get_next_line(fd));
		printf("%s", get_next_line(fd));
		printf("%s", get_next_line(fd));
		printf("%s", get_next_line(fd));
	}
	system("leaks a.out");
}
*/
