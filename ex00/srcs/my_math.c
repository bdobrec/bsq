/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 09:42:02 by edal-san          #+#    #+#             */
/*   Updated: 2016/08/30 13:16:05 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

#define WS(ws) (ws=='\t'||ws=='\n'||ws=='\v'||ws=='\f'||ws==' '||ws=='\r')

int		ft_atoi(char *str)
{
	unsigned long long	res;
	int					i;
	int					sign;

	res = 0;
	i = 0;
	sign = 1;
	while (WS(str[i]))
		str++;
	if (str[i] == '+' || str[i] == '-')
	{
		sign = str[i] == '-' ? -1 : 1;
		str++;
	}
	while (*str == 0)
		str++;
	while (str[i] != '\0')
	{
		if (str[i] > 57 || str[i] < 48)
			return (res * sign);
		res = res * 10 + str[i++] - '0';
	}
	if (i > 19 || res > 9223372036854775807ULL)
		return (sign == 1 ? -1 : 0);
	return (res * sign);
}

void	ft_putnbr(int nb)
{
	char	n;

	if (nb < 0)
	{
		write(1, "-", 1);
		if (nb == -2147483648)
		{
			write(1, "2", 1);
			nb = nb % 1000000000;
		}
		nb = nb * -1;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	n = (nb % 10) + '0';
	write(1, &n, 1);
}

int		min(int a, int b, int c)
{
	if ((a <= b) && (a <= c))
		return (a);
	else if ((b <= a) && (b <= c))
		return (b);
	else
		return (c);
}
