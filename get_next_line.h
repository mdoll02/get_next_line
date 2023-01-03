/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoll <mdoll@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 10:18:51 by mdoll             #+#    #+#             */
/*   Updated: 2023/01/03 15:22:15 by mdoll            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_find_end_of_line(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_remalloc(char *buf);
char	*ft_construct_return(char *save_line, char *buf);

#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 100
#endif