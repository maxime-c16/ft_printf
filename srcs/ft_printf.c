/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 20:12:02 by mcauchy           #+#    #+#             */
/*   Updated: 2025/02/14 20:38:03 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	process_format(const char *format, int *index, va_list args)
{
	int	count;
	int	i;

	i = *index;
	count = 0;
	if (format[i] == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (format[i] == 'd' || format[i] == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (format[i] == 'u')
		count += ft_putunsigned(va_arg(args, unsigned int));
	else if (format[i] == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (format[i] == 'x')
		count += ft_puthex(va_arg(args, unsigned int), 0);
	else if (format[i] == 'X')
		count += ft_puthex(va_arg(args, unsigned int), 1);
	else if (format[i] == 'p')
		count += ft_putptr(va_arg(args, void *));
	else if (format[i] == '%')
		count += ft_putchar('%');
	*index = i;
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += process_format(format, &i, args);
		}
		else
			count += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}
