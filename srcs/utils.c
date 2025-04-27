/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macauchy <macauchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 20:24:48 by mcauchy           #+#    #+#             */
/*   Updated: 2025/04/27 12:09:39 by macauchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i])
		if (write(1, &str[i++], 1) == -1)
			return (-1);
	return (i);
}

static int	ft_putnbr_recursive(int nb)
{
	int		count;
	int		written;
	char	c;

	count = 0;
	written = 0;
	if (nb >= 10)
	{
		written = ft_putnbr_recursive(nb / 10);
		if (written == -1)
			return (-1);
		count += written;
	}
	c = nb % 10 + '0';
	written = write(1, &c, 1);
	if (written == -1)
		return (-1);
	count += written;
	return (count);
}

int	ft_putnbr(int nb)
{
	int	count;

	count = 0;
	if (nb == -2147483648)
		return (write(1, "-2147483648", 11));
	if (nb < 0)
	{
		count += write(1, "-", 1);
		if (count == -1)
			return (-1);
		nb = -nb;
	}
	return (count + ft_putnbr_recursive(nb));
}
