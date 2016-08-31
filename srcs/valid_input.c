/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdobrec <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/29 11:31:18 by bdobrec           #+#    #+#             */
/*   Updated: 2016/08/30 12:42:22 by bdobrec          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int		ft_read_map(char *buf, char *argv, char **map)
{
	int row;
	int col;
	int fd;
	int count;
	int nb;

	fd = open(argv, O_RDONLY);
	read(fd, buf, 5);
	buf += 4;
	row = 0;
	while ((ret = read(fd, buf, 1)))
	{
		col = 0;
		while (buf[i++] != '\n')
		{
			map[row][col] = *buf;
			read(fd, buf, 1);
			col++;
		}
		*map[row][col] = '\0';
		row++;
	}
	validate(*buf);
}

int		ft_validate(char *buf)
{
	while (*buf)
	{
		if (*buf != g_empty || *buf != g_obstacles || *buf != g_full)
			return (0);
		count = 0;
		while (*buf != '\n')
			count++;
		if (count != get_line_length(fd, buf))
			return (0);
		nb = 0;
		while (*buf == '\n')
			nb++;
		if (nb != buf[0])
			return (0);
	}
	buf++;
	return (1);
}
