/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoll <mdoll@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 10:18:42 by mdoll             #+#    #+#             */
/*   Updated: 2023/01/05 11:11:27 by mdoll            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char static				*remainder;
	char					*buf;
	char					*ret;

	if (fd == -1)
		return (NULL);
	if (remainder == NULL)
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (read(fd, buf, BUFFER_SIZE) <= 0)
		{
			free(buf);
			return (NULL);
		}
	}
	else
	{
		buf = remainder;
		remainder = NULL; // logic issue | maybe not??
	}
	while (!ft_find_end_of_line(buf))
	{
		remainder = ft_strjoin(remainder, buf);
		if (read(fd, buf, BUFFER_SIZE) == 0)
			break ;
	}
	ret = ft_construct_return(remainder, buf);
	// ret = remainder;
	buf = ft_remalloc(buf);
	remainder = buf;
	free(buf);
	return (ret);
}
