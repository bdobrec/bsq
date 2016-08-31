/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/28 13:55:40 by edal-san          #+#    #+#             */
/*   Updated: 2016/08/30 15:43:49 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"
#include <stdio.h> //REMOVE ME!!!!

char	**make_arr(char *buf, char *argv, char **map)
	{
	int	r;
	int c;
	int fd;

	fd = open(argv, O_RDONLY);
	read(fd, buf, 5);	
	buf += 4;
	r = 0;
	while ((read(fd, buf, 1)))
	{
		c = 0;	
		while (*buf != '\n')
		{	
			map[r][c] = *buf;
			read(fd, buf, 1);
			c++;
		}
		map[r][c] = '\0';
		r++;
	}
	map[r] = 0;
	close(fd);
	return (map);
}

char	**file_to_arr(char *buf, char *argv)
{
	char	**map;
	int		fd;
	int		i;
	int		j;

	fd = open(argv, O_RDONLY);
	j = 0;
	while (*buf != '\n')
	{
		read(fd, buf, 1);
		if (*buf >= '0' && *buf <='9')
			g_num_lines = g_num_lines * 10 + *buf - '0';
		else
			g_symbols[j++] = *buf;
	}
	g_empty = g_symbols[0];
	g_full = g_symbols[2];
	g_linelength = get_line_length(fd, buf);
	map = (char **)malloc((sizeof(char *) * (g_num_lines + 1) + sizeof(int)));
	i = 0;
	while (i < g_num_lines)
		map[i++] = (char *)malloc((sizeof(char) * g_linelength) + 1);
	close(fd);
	map = make_arr(buf, argv, map);
	return (map);
}

int		**make_sum_matrix(char 	**map)
{
	int				**sum_matrix;
	int				i;

	sum_matrix = (int **)malloc((sizeof(int *) * g_num_lines) + sizeof(int));
	i = 0;
	while (i < g_num_lines)
		sum_matrix[i++] = (int *)malloc(sizeof(int) * g_linelength);
	sum_matrix = fill_sum_matrix(sum_matrix, map);
	return (sum_matrix);
}

char	**solve_map(char	**map)
{
	int		**sum_matrix;
	int		bsq;

	sum_matrix = make_sum_matrix(map); 
	print_matrix(sum_matrix);
	bsq = find_bsq(sum_matrix);
	destroy_matrix(sum_matrix);
	map = insert_bsq(map, bsq);
	return (map);
}

int		main(int argc, char **argv)
{
	char	buf[BUF_SIZE + 1];
	char	**map;

	if (argc == 1)
		read_stdin();
	else
	{
		while (*++argv)
		{
			//if (valid_map(*argv))
			//{
				map = file_to_arr(buf, *argv);
				print_map(map);
				write(1, "----------\n", 11);
				solve_map(map);
				print_map(map);
				destroy_map(map);
			//}
		//	else
		//		write(1, "map error", 9);
			write(1, "\n", 1);
		}
	}
	return (0);
}
