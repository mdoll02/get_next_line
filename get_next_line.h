/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoll <mdoll@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 10:18:51 by mdoll             #+#    #+#             */
/*   Updated: 2023/01/05 16:37:38 by mdoll            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_read(int fd, char *remainder);
char	*ft_get_line(int fd, char *remainder);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_get_line(int fd, char *remainder);
char	*ft_resize(char *remainder);
int		ft_find_end(char *str);
int		ft_strlen(char *str);

#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 100
#endif