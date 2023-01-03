/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoll <mdoll@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:24:01 by mdoll             #+#    #+#             */
/*   Updated: 2023/01/03 15:09:18 by mdoll            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	char	*str;
	int		fd;

	fd = open("/Users/mdoll/Dev/Student_Projects/get_next_line/read_from_this", O_RDONLY);
	str = get_next_line(fd);
	printf("%s", str);
	str = get_next_line(fd);
	printf("%s", str);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	return (0);
}
