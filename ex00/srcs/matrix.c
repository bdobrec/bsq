/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/30 14:46:38 by edal-san          #+#    #+#             */
/*   Updated: 2016/08/30 19:32:59 by edal-san         ###   ########.fr       */
/*   Created: 2016/08/30 11:54:38 by edal-san          #+#    #+#             */
/*   Updated: 2016/08/30 14:30:22 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"
#include <stdio.h>

int		**copy_firsts(int **sum_matrix, char **map)
{
	int 	c;
	int		r;
	
	r = 0;
	while (r < g_num_lines)
	{
		if (map[r][0] == g_symbols[0])
			sum_matrix[r][0] = 1;
		else
			sum_matrix[r][0] = 0;
		r++;
	}
	c = 0;
	while (c < g_linelength)
	{
		if (map[0][c] == g_symbols[0])
			sum_matrix[0][c] = 1;
		else
			sum_matrix[0][c] = 0;
		c++;
	}
	return (sum_matrix);
}

int		**fill_sum_matrix(int **sum_matrix, char **map)
{
	int		r;
	int		c;
	
	sum_matrix = copy_firsts(sum_matrix, map);
	r = 1;
	while (r < g_num_lines)
	{
		c = 1;
		while (c < g_linelength)
		{
			if (map[r][c] == g_symbols[0])
			{
				sum_matrix[r][c] = min(sum_matrix[r][c - 1],
						sum_matrix[r - 1][c - 1], sum_matrix[r - 1][c]) + 1;
			}
			else
				sum_matrix[r][c] = 0;
			c++;
		}
		r++;
	}
	return (sum_matrix);
}

int		find_bsq(int **sum_matrix)
{
	int		r;
	int		c;
	int		bsq;

	bsq = sum_matrix[0][0];
	r = 0;
	while (r < g_num_lines)
	{
		c = 0;
		while (c < g_linelength)
		{
			if (sum_matrix[r][c] > bsq)
			{
				bsq = sum_matrix[r][c];
				g_max_row = r;
				g_max_col = c;
			}
			c++;
		}
		r++;
	}
	return (bsq);
}

void	print_matrix(int **matrix)
{
	int		r;
	int		c;

	r = 0;
	while (r < g_num_lines)
	{
		c = 0;
		while (c < g_linelength)
		{
			ft_putnbr(matrix[r][c]);
			write(1, " ", 1);
			c++;
		}
		write(1, "\n", 1);
		r++;
	}
}

void	destroy_matrix(int **matrix)
{
	int		r;

	r = 0;
	while (r < g_num_lines)
	{
		free(matrix[r]);
		r++;
	}
	free(matrix);
}
