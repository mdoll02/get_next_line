/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoll <mdoll@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 10:18:42 by mdoll             #+#    #+#             */
/*   Updated: 2023/01/05 16:32:38 by mdoll            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*line;

	if (fd == -1 || BUFFER_SIZE < 1)
		return (NULL);
	remainder = ft_read(fd, remainder);
	if (!remainder)
		return (NULL);
	line = ft_get_line(fd, remainder);
	return (line);
}

char	*ft_read(int fd, char *remainder)
{
	static char	*buf;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (read(fd, buf, BUFFER_SIZE) == -1)
	{
		free(buf);
		return (NULL);
	}
	buf = ft_strjoin(remainder, buf);
	return (buf);
}

char	*ft_get_line(int fd, char *remainder)
{
	char	*line;
	int		i;

	i = 0;
	while (ft_find_end(remainder) == 0)
	{
		remainder = ft_read(fd, remainder);
	}
	while (remainder[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (remainder[i] != '\n')
	{
		line[i] = remainder[i];
		i++;
	}
	line[i] = '\n';
	line[i + 1] = '\0';
	ft_resize(remainder);
	return (line);
}

char	*ft_resize(char *remainder)
{
	char	*tmp;
	int		start;
	int		i;

	i = 0;
	start = ft_find_end(remainder);
	tmp = malloc(sizeof(char) * (ft_strlen(remainder) - start + 1));
	if (!tmp)
		return (NULL);
	while (remainder[start])
	{
		tmp[i] = remainder[start];
		i++;
		start++;
	}
	*remainder = *tmp;
}
