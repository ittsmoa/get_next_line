/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moatieh <moatieh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 23:20:02 by moatieh           #+#    #+#             */
/*   Updated: 2025/09/19 23:20:02 by moatieh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER 10

char    *get_next_line(int fd)
{
	char *b = calloc(BUFFER, 1);
	char *rem;
	int count;

	while(count != 0)
	{
		count = read(fd, b, BUFFER);
		printf("%s", b);
	}
	return NULL;
}

int main()
{
	int fd = open("text.txt", O_RDONLY);
	get_next_line(fd);
}