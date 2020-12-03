/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rin <rin@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 16:16:09 by rin               #+#    #+#             */
/*   Updated: 2020/12/03 21:14:05 by rin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int					get_next_line(int fd, char **line)
{
	char			*buf;
	int				reader;
	char			*result;

	reader = 1;
	if (!(buf = (char *)malloc(sizeof(char) * 2)) || fd == -1 || !line
	|| BUFFER_SIZE <= 0 || !(result = (char *)malloc(sizeof(char) * 2)))
		return (-1);
	while (reader != 0)
	{
		if ((reader = read(fd, buf, 1)) == -1)
		{
			free(buf);
			return (-1);
		}
		if (buf[0] == '\n')
		{
			*line = result;
			free(buf);
			return (1);
		}
		buf[1] = '\0';
		result = my_join(result, buf[0]);
	}
	return (0);
}

/*
int main()
{
	int		file;
	char	*line;

	file = open("test", O_RDONLY);
	while(get_next_line(file, &line))
	{
		printf("%s\n", line);
		//free(line);
	}
	//printf("%s\n", line);
	return (0);
}
*/
