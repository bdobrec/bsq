/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/30 11:54:38 by edal-san          #+#    #+#             */
/*   Updated: 2016/08/30 15:44:28 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

void	print_map(char **map)
{
	int		r;
	int		c;

	r = 0;
	while (r < g_num_lines)
	{
		c = 0;
		while (c < g_linelength)
		{
			write(1, &map[r][c], 1);
			c++;
		}
		write(1, "\n", 1);
		r++;
	}
}

int		get_line_length(int fd, char *buf)
{
	int		line_length;

	line_length = 0;
	read(fd, buf, 1);
	while (*buf != '\n')
	{		
		line_length++;
		read(fd, buf, 1);
	}
	return (line_length);
}

char	**insert_bsq(char **map, int bsq)
{
	int		r;
	int		c;
	
	r = g_max_row - (bsq - 1);
	while (r <= g_max_row)
	{
		c = g_max_col - (bsq - 1);
		while (c <= g_max_col)
		{
			map[r][c] = g_full;
			c++;
		}
		r++;
	}
	return (map);
}

void	destroy_map(char **map)
{
	int		r;

	r = 0;
	while (r < g_num_lines)
	{
		free(map[r]);
		r++;
	}
	free(map);
}
