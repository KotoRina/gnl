/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rin <rin@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 21:26:33 by rin               #+#    #+#             */
/*   Updated: 2020/12/15 19:48:18 by rin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* Especially for those who call me a cheater (including the bocal).
* Only because you suddenly decided that I was writing off the code
* - I will not write bad code and insert crutches.
* I despise those who thoughtlessly cheat without understanding
* and optimizing the solution.
* I do not despise those who take the algorithm and implement it beautifully.
* If you think that I am cheating, look at you. Then you are also cheating.
* Because every time you implement an algorithm that has been implemented
* before you - you're cheating.
*/

#include "get_next_line.h"

static int			find_next_line(char *str)
{
	int				len;

	if (!str)
		return (0);
	len = 0;
	while (str[len] && str[len] != '\n')
		len++;
	if (len != (int)my_strlen(str))
		return (1);
	return (0);
}

static char			*save_buf(char *save, char *buf)
{
	int				len_save;
	int				len_buf;
	char			*result;

	if (!save && !buf)
		return (0);
	len_buf = my_strlen(buf);
	len_save = my_strlen(save);
	if (!(result = (char *)malloc(sizeof(char) * (1 + len_save + len_buf))))
		return (0);
	len_buf = 0;
	len_save = 0;
	if (save)
		while (save[len_save])
		{
			result[len_save] = save[len_save];
			len_save++;
		}
	while (buf[len_buf])
		result[len_save++] = buf[len_buf++];
	result[len_save] = '\0';
	free(save);
	return (result);
}

static void			split(char **remainder, char ***line, int len, int i)
{
	char			*res_save;
	char			*rem;
	char			*result_line;

	if (!*remainder)
	{
		***line = 0;
		return ;
	}
	rem = *remainder;
	while (rem[len] && rem[len] != '\n')
		len++;
	if (!(result_line = (char *)malloc(sizeof(char) * (len + 1))) ||
	!(res_save = (char *)malloc(sizeof(char) * (my_strlen(rem) - len + 2))))
		return ;
	len = -1;
	while (rem[++len] && rem[len] != '\n')
		result_line[len] = rem[len];
	result_line[len++] = '\0';
	**line = result_line;
	while (rem[len])
		res_save[i++] = rem[len++];
	res_save[i] = '\0';
	free(*remainder);
	*remainder = res_save;
}

int					get_next_line(int fd, char **line)
{
	char			*buf;
	static char		*save;
	int				reader;

	reader = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0 ||
	!(buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while (!find_next_line(save) && reader != 0)
	{
		if ((reader = read(fd, buf, BUFFER_SIZE)) == -1)
		{
			free(buf);
			return (-1);
		}
		buf[reader] = '\0';
		save = save_buf(save, buf);
	}
	free(buf);
	split(&save, &line, 0, 0);
	if (reader == 0)
		return (0);
	return (1);
}
