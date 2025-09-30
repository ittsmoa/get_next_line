/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moatieh <moatieh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 23:20:02 by moatieh           #+#    #+#             */
/*   Updated: 2025/09/30 12:47:10 by moatieh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	*rem;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rem = reader(fd, rem);
	if (!rem || rem[0] == '\0')
	{
		if (rem)
		{
			free(rem);
			rem = NULL;
		}
		return (NULL);
	}
	one_line = line_maker(rem);
	rem = rem_saver(rem);
	return (one_line);
}

// int main(void)
// {
// 	int fd;
// 	char *line;

// 	fd = open("text.txt", O_RDONLY);
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	close(fd);
// 	return (0);
// }
