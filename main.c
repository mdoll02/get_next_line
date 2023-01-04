/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoll <mdoll@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 10:24:01 by mdoll             #+#    #+#             */
/*   Updated: 2023/01/04 12:36:19 by mdoll            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	char	*str;
	int		fd;
	int		END;
	
	END = 0;
	fd = open("/Users/mdoll/dev/get_next_line/read_from_this", O_RDONLY); //changed so it fits macbook
	while (END == 0)
	{
		str = get_next_line(fd);
		if (str == NULL)
			END = 1;
		printf("%s", str);
	}
	free(str);
	return (0);
}
