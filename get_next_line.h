/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoll <mdoll@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 10:18:51 by mdoll             #+#    #+#             */
/*   Updated: 2023/01/07 12:33:57 by mdoll            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 69
# endif

char		*get_next_line(int fd);
char		*ft_strchr(const char *s, int c);
char		*ft_strjoin(char *s1, char *s2);
int			ft_find_end(char *str);
size_t		ft_strlen(char *str);

#endif
