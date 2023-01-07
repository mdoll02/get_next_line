/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdoll <mdoll@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 10:18:37 by mdoll             #+#    #+#             */
/*   Updated: 2023/01/07 12:31:30 by mdoll            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int				i;
	char			*str;
	unsigned char	uc;

	if (!s)
		return (NULL);
	str = (char *) s;
	i = 0;
	uc = (unsigned char) c;
	while (s[i])
	{
		if (s[i] == uc)
			return (str + i);
		i++;
	}
	if (uc == '\0')
		return (str + i);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char		*jstring;
	size_t		i;
	size_t		j;

	if (!s1)
	{
		s1 = malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	jstring = malloc((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char) + 1);
	if (!jstring)
		return (NULL);
	i = -1;
	while (s1[++i])
		jstring[i] = s1[i];
	j = 0;
	while (i < ft_strlen(s1) + ft_strlen(s2) && s2[j])
		jstring[i++] = s2[j++];
	jstring[i] = '\0';
	free(s1);
	return (jstring);
}
