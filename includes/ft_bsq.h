/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/28 14:08:30 by edal-san          #+#    #+#             */
/*   Updated: 2016/08/30 15:46:40 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BSQ_H
# define FT_BSQ_H

# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# define BUF_SIZE 30179

void	read_stdin(void);
void	ft_putnbr(int nb);
void	print_map(char **map);
void	destroy_matrix(int **sum_matrix);
void    destroy_map(char **map);
void	print_matrix(int **matrix);
char	**make_arr(char *buf, char *argv, char **map);
char	**file_to_arr(char *buf, char *argv);
char	**insert_bsq(char **map, int bsq);
int		ft_atoi(char *str);
int		get_line_length(int fd, char *buf);
int		**fill_sum_matrix(int **sum_matrix, char **map);
int     find_bsq(int **sum_matrix);
int		min(int a, int b, int c);
int     **copy_firsts(int **sum_matrix, char **map);

char		g_symbols[3];
char		g_empty;
char		g_full;
int			g_num_lines;
int			g_linelength;
int			g_max_row;
int			g_max_col;

#endif
