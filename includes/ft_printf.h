/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 20:12:28 by mcauchy           #+#    #+#             */
/*   Updated: 2025/02/14 20:39:32 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);

// utils

int		ft_strlen(const char *str);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
int		ft_putstr(const char *str);
int		ft_putchar(char c);
int		ft_putnbr(int n);
int		ft_putunsigned(unsigned int nb);
int		ft_puthex(unsigned long long n, int flag);
int		ft_putptr(void *ptr);

#endif
