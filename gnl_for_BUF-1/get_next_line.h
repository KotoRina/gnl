/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rin <rin@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 16:16:13 by rin               #+#    #+#             */
/*   Updated: 2020/12/15 04:22:48 by rin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

typedef	struct	s_gnl
{
	int			rd;
	char		*buf;
	char		*res;
}				t_gnl;

char			*my_join(char *line, char c);
size_t			my_strlen(char	*line);
int				get_next_line(int fd, char **line);

#endif
