/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rin <rin@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 16:16:13 by rin               #+#    #+#             */
/*   Updated: 2020/12/03 17:08:57 by rin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_HEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# define BUFFER_SIZE 2

char	*my_join(char *line, char c);
size_t	my_strlen(char	*line);
int		get_next_line(int fd, char **line);

#endif