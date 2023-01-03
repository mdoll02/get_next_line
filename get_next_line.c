/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoll <mdoll@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 10:18:42 by mdoll             #+#    #+#             */
/*   Updated: 2023/01/03 15:31:06 by mdoll            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

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
		remainder = NULL;
	}
	while (!ft_find_end_of_line(buf))
	{
		remainder = ft_strjoin(remainder, buf);
		printf("%s\n", remainder);
		if (read(fd, buf, BUFFER_SIZE) == 0)
			return (NULL);
	}
	ret = ft_construct_return(remainder, buf);
	buf = ft_remalloc(buf);
	remainder = buf;
	buf = NULL;
	return (ret);
}
