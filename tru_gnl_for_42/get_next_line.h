/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rin <rin@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 21:26:30 by rin               #+#    #+#             */
/*   Updated: 2020/12/15 03:44:13 by rin              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 10
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

int			get_next_line(int fd, char **line);
size_t		my_strlen(const char *str);

#endif