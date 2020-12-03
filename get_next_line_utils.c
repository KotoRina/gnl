/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rin <rin@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 16:16:02 by rin               #+#    #+#             */
/*   Updated: 2020/12/04 02:56:04 by rin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t			my_strlen(char *line)
{
	size_t		len;

	len = 0;
	if (!line)
		return (0);
	while (line[len])
		len++;
	return (len);
}

char			*my_join(char *line, char c)
{
	char		*res;
	int			len;

	len = 0;
	if (!line)
	{
		res = (char *)malloc(sizeof(char) * 2);
		res[0] = c;
		res[1] = '\0';
		return (res);
	}
	res = (char *)malloc(sizeof(char) * (my_strlen(line) + 2));
	while (line[len])
	{
		res[len] = line[len];
		len++;
	}
	res[len] = c;
	len++;
	res[len] = '\0';
	free(line);
	return (res);
}
