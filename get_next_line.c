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

char    *get_next_line(int fd)
{

}

int main()
{
	int	chars_read;
	char	buf[100];
    int fd;
    fd = open("text.txt", O_RDONLY | O_CREAT | O_APPEND );
    printf("%d\n", fd);

	int x = read(fd, buf, 5);
	while (chars_read = read(fd, buf, 5))
	{
		buf[chars_read] = '\0';
		printf ("%s\n", buf);
	}
	printf("\n%d", x);
	write (1, "\n", 1);
    return 0;
}