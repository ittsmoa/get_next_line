/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moatieh <moatieh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 17:04:15 by moatieh           #+#    #+#             */
/*   Updated: 2025/09/30 17:42:01 by moatieh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main()
{
    int fd;
    char *line;

    fd = open("text.txt", O_RDONLY);
   line = get_next_line(fd);

        printf("%s", line);
        if (line)
            free(line);
    if (line == NULL)
        printf("NULllL\n");
    
    return 0;
}