/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoll <mdoll@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:24:01 by mdoll             #+#    #+#             */
/*   Updated: 2023/01/05 14:00:11 by mdoll            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	char	*str;
	int		fd;
	int		i;
	int		lines;

	i = 0;
	lines = 13;
	fd = open("/Users/mdoll/Dev/Student_Projects/get_next_line/read_from_this", O_RDONLY);
	while (i < lines)
	{
		str = get_next_line(fd);
		printf("%s", str);
		i++;
	}
	free(str);
	close(fd);
	return (0);
}
