/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/28 14:15:31 by edal-san          #+#    #+#             */
/*   Updated: 2016/08/28 19:42:47 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

void	read_stdin(void)
{
	int		ret;
	char	buf[BUF_SIZE + 1];

	while ((ret = read(0, buf, BUF_SIZE)))
		write(1, buf, ret);
}

void	ft_strcpy(char *dest, char *src)
{
	char *d;

	d = dest;
	while (*src++)
		*d++ = *src;
	*d = '\0';
}
