/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moatieh <moatieh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 23:19:58 by moatieh           #+#    #+#             */
/*   Updated: 2025/10/01 13:42:30 by moatieh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	count;

	count = 0;
	if (!s)
		return (0);
	while (s[count] != '\0')
	{
		count++;
	}
	return (count);
}

static char	*cpy(char *str, char const *first, char const *sec)
{
	int	i;
	int	j;

	i = 0;
	if (!first)
		first = "";
	while (first[i])
	{
		str[i] = first[i];
		i++;
	}
	j = 0;
	if (!sec)
		sec = "";
	while (sec[j])
	{
		str[i + j] = sec[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	total;

	i = 0;
	total = 0;
	while (s1 && s1[total])
		total++;
	while (s2 && s2[i])
		i++;
	total += i;
	str = (char *)malloc((total + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str = cpy(str, s1, s2);
	free(s1);
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	slen;
	size_t	i;

	i = 0;
	slen = ft_strlen(s);
	if (!s)
		return (NULL);
	if (start >= slen)
	{
		str = (char *)malloc(1);
		str[0] = '\0';
		return (str);
	}
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (i < len && s[start])
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	count;

	count = 0;
	if (!s)
		return (NULL);
	while (s[count] != '\0')
	{
		if ((unsigned char)s[count] == ((unsigned char)c))
			return ((char *)(s + count));
		count++;
	}
	if (c == '\0')
		return ((char *)(s + count));
	return (NULL);
}
