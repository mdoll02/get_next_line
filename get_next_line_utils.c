/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoll <mdoll@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 10:18:37 by mdoll             #+#    #+#             */
/*   Updated: 2023/01/05 16:38:25 by mdoll            ###   ########.fr       */
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

int	ft_find_end(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\0')
		return (0);
	return (i);
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
	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	while (--len)
	{
		if (*s1)
			jstring[i] = *s1++;
		else
			jstring[i] = *s2++;
		i++;
	}
	jstring[i] = '\0';
	return (jstring);
}