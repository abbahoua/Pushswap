/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbahoua <abbahoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 20:28:18 by ibnada            #+#    #+#             */
/*   Updated: 2022/04/24 01:01:54 by abbahoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include "../checker_bonus/bonus_header.h"

char	*line_join(char *line, char c)
{
	char	*new;
	int		i;

	i = 0;
	while (line && line[i])
		i++;
	new = malloc(sizeof(char) * (i + 2));
	if (!new)
	{
		free(line);
		return (NULL);
	}
	i = 0;
	while (line && line[i])
	{
		new[i] = line[i];
		i++;
	}
	new[i++] = c;
	new[i] = 0;
	free(line);
	return (new);
}

char	*get_next_line(int fd)
{
	char	*line;
	char	c;
	int		count;
	int		buffersize;

	buffersize = 10;
	if (buffersize < 1 || fd < 0)
		return (NULL);
	line = NULL;
	count = read(fd, &c, 1);
	if (count <= 0)
		return (0);
	while (count)
	{
		line = line_join(line, c);
		if (c == '\n')
			break ;
		count = read(fd, &c, 1);
	}
	return (line);
}
