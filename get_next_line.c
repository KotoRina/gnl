/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rin <rin@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 16:16:09 by rin               #+#    #+#             */
/*   Updated: 2020/12/03 17:08:47 by rin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	char	*buf;
	int		reader;
	static char	*result;

	reader = 1;
	if (fd == -1 || !line || BUFFER_SIZE <= 0)
		return (-1);
	buf = (char *)malloc(sizeof(char) * 2);
	result = (char *)malloc(sizeof(char) * 2);
	*line = NULL;
	while (reader != 0 && buf[0] != '\n')
	{
		if ((reader = read(fd, buf, 1)) == -1)
		{
			free(buf);
			return (-1);
		}
		buf[1] = '\0';
		if (buf[0] != '\n' && buf[0] != '\0')
			result = my_join(result, buf[0]);
	}
	*line = result;
	if (buf[0] == '\n' || buf[0] == '\0')
	{
		free(buf);
		return(1);
	}
	return (0);
}

int main()
{
	int		file;
	char	*line;

	file = open("test", O_RDONLY);
	while(get_next_line(file, &line))
	{
		printf("%s\n", line);
		free(line);
	}
	return (0);
}
