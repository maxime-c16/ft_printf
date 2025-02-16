/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 20:40:22 by mcauchy           #+#    #+#             */
/*   Updated: 2025/02/14 20:41:13 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putunsigned(unsigned int nb)
{
	int		count;
	char	c;

	count = 0;
	if (nb >= 10)
		count += ft_putunsigned(nb / 10);
	c = nb % 10 + '0';
	count += write(1, &c, 1);
	return (count);
}

int	ft_puthex(unsigned long long nb, int flag)
{
	int		count;
	char	c;

	count = 0;
	if (nb >= 16)
		count += ft_puthex(nb / 16, flag);
	if (flag)
		c = "0123456789ABCDEF"[nb % 16];
	else
		c = "0123456789abcdef"[nb % 16];
	count += write(1, &c, 1);
	return (count);
}

int	ft_putptr(void *ptr)
{
	int		count;
	char	c;

	count = 0;
	count += write(1, "0x", 2);
	if ((unsigned long long)ptr >= 16)
		count += ft_puthex((unsigned long long)ptr / 16, 0);
	c = "0123456789abcdef"[(unsigned long long)ptr % 16];
	count += write(1, &c, 1);
	return (count);
}
