/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moatieh <moatieh@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 23:19:58 by moatieh           #+#    #+#             */
/*   Updated: 2025/09/19 23:19:58 by moatieh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



void* ft_malloc(size_t size)
{
    static size_t call = 0;

    call++;
    if (call % 2 == 1)
        return NULL;
    else
        return malloc(size);        
}

int	ft_strlen(const char *s)
{
	int	count;

	count = 0;
	while (s[count] != '\0')
	{
		count++;
	}
	return (count);
}

char	*ft_strdup(const char *s)
{
	char	*cpy;
	int	slen;
	int		count;

	slen = ft_strlen(s);
	cpy = ft_malloc((slen + 1) * sizeof(char));
	if (!cpy)
		return (NULL);
	count = 0;
	while (s[count])
	{
		cpy[count] = s[count];
		count++;
	}
	cpy[count] = '\0';
	return (cpy);
}
