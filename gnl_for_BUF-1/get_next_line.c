/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rin <rin@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 16:16:09 by rin               #+#    #+#             */
/*   Updated: 2020/12/04 02:55:20 by rin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int					get_next_line(int fd, char **line)
{
	t_gnl			gnl;

	gnl.rd = 1;
	gnl.res = NULL;
	if (!(gnl.buf = (char *)malloc(sizeof(char) * 2)) || fd == -1 || \
	!line || BUFFER_SIZE <= 0)
		return (-1);
	while (gnl.rd != 0)
	{
		if ((gnl.rd = read(fd, gnl.buf, 1)) == -1)
		{
			free(gnl.buf);
			return (-1);
		}
		if (gnl.buf[0] == '\n' || gnl.rd == 0)
		{
			*line = gnl.res;
			free(gnl.buf);
			return (gnl.rd == 0 ? 0 : 1);
		}
		gnl.buf[1] = '\0';
		gnl.res = my_join(gnl.res, gnl.buf[0]);
	}
	return (0);
}
