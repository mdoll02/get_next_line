/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoll <mdoll@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 10:18:42 by mdoll             #+#    #+#             */
/*   Updated: 2023/01/03 11:32:08 by mdoll            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char			*save_line;
	char				*buf;
	char				*end_of_line;
	char				*ret;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	buf[BUFFER_SIZE + 1] = '\0';
	read(fd, buf, BUFFER_SIZE);
	while (buf != NULL)
	{
		end_of_line = ft_find_end_of_line(buf);
		if (end_of_line != NULL)
		{
			ret = ft_construct_return(save_line, buf);
			if (ft_remalloc(buf) == NULL)
				return (NULL);
			save_line = buf;
			buf = NULL;
		}
		else
		{
			ft_strjoin(save_line, buf);
			read(fd, buf, BUFFER_SIZE);
		}
	}
	return (ret);
}
