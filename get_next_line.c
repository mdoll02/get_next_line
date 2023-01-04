/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoll <mdoll@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 10:18:42 by mdoll             #+#    #+#             */
/*   Updated: 2023/01/04 12:39:46 by mdoll            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char static				*remainder;
	char					*buf;
	char					*ret;

	if (remainder == NULL)
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (read(fd, buf, BUFFER_SIZE) == 0)
			return (NULL);
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
			return (NULL);
	}
	ret = ft_construct_return(remainder, buf);
	buf = ft_remalloc(buf);
	remainder = buf;
	free(buf);
	return (ret);
}
