/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoll <mdoll@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 10:18:37 by mdoll             #+#    #+#             */
/*   Updated: 2023/01/03 11:31:51 by mdoll            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_find_end_of_line(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\0')
		return (NULL);
	else
		return (&str[i]);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		len;
	char	*jstring;
	int		i;

	len = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	jstring = malloc(len * sizeof(char) + 1);
	if (jstring == NULL)
		return (NULL);
	len += 1;
	while (--len)
	{
		if (*s1)
			jstring[i] = *(char *)s1++;
		else
			jstring[i] = *(char *)s2++;
		i++;
	}
	jstring[i] = '\0';
	return (jstring);
}

char	*ft_remalloc(char *buf)
{
	int		i_buf;
	int		i_tmp;
	char	*tmp;

	i_buf = 0;
	i_tmp = 0;
	while (buf[i_buf] != '\n')
		i_buf++;
	i_buf++;
	i_tmp = i_buf;
	while (buf[i_tmp])
		i_tmp++;
	tmp = malloc (sizeof(char) * i_tmp + 1);
	if (!tmp)
		return (NULL);
	i_tmp = 0;
	while (buf[i_buf])
	{
		tmp[i_tmp] = buf[i_buf];
		i_tmp++;
		i_buf++;
	}
	
	return (":)");
}

char	*ft_construct_return(char *save_line, char *buf)
{
	char	*tmp;
	int		len_save_line;
	int		i;

	len_save_line = ft_strlen(save_line);
	i = 0;
	while (buf[i] != '\n')
		i++;
	tmp = malloc (sizeof(char) * (len_save_line + i + 1));
	if (!tmp)
		return (NULL);
	i = 0;
	len_save_line = 0;
	if (save_line != NULL)
	{
		while (save_line[len_save_line])
			tmp[len_save_line] = len_save_line;
	}
	while (buf[i] != '\n')
	{
		tmp[len_save_line] = buf[i];
		len_save_line++;
		i++;
	}
	return (tmp);
}
