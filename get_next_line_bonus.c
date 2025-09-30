/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moatieh <moatieh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 12:48:39 by moatieh           #+#    #+#             */
/*   Updated: 2025/09/30 12:48:39 by moatieh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*line_maker(char *rem)
{
	char	*line;
	int		i;

	i = 0;
	while (rem[i] && rem[i] != '\n')
		i++;
	if (rem[i] == '\n')
		i++;
	line = ft_substr(rem, 0, i);
	if (!line)
		return (NULL);
	return (line);
}

static char	*rem_saver(char *rem)
{
	char	*new_rem;
	int		i;

	i = 0;
	while (rem[i] && rem[i] != '\n')
		i++;
	if (rem[i] == '\n')
		i++;
	if (rem[i] == '\0')
	{
		free(rem);
		return (NULL);
	}
	new_rem = ft_substr(rem, i, ft_strlen(rem) - i);
	if (!new_rem)
	{
		free(rem);
		return (NULL);
	}
	free(rem);
	return (new_rem);
}

static char	*reader(int fd, char *rem)
{
	char	*buffer;
	char	*temp;
	int		bytes;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes = 1;
	while ((bytes > 0 && !ft_strchr(rem, '\n')) || !rem)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(buffer);
			free(rem);
			return (NULL);
		}
		buffer[bytes] = '\0';
		temp = ft_strjoin(rem, buffer);
		if (rem)
			free(rem);
		rem = temp;
	}
	free(buffer);
	return (rem);
}

char	*get_next_line(int fd)
{
	char		*one_line;
	static char	*rem[1000];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rem[fd] = reader(fd, rem[fd]);
	if (!rem[fd] || rem[fd][0] == '\0')
	{
		if (rem[fd])
		{
			free(rem[fd]);
			rem[fd] = NULL;
		}
		return (NULL);
	}
	one_line = line_maker(rem[fd]);
	rem[fd] = rem_saver(rem[fd]);
	return (one_line);
}
