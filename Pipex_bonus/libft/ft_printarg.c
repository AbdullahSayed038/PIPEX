/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printarg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsayed <abdsayed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 12:13:40 by abdsayed          #+#    #+#             */
/*   Updated: 2024/07/09 13:54:37 by abdsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printarg(char specifier, va_list arg, int *count)
{
	if (specifier == 'c')
		ft_putchr_printf((char)va_arg(arg, int), count);
	else if (specifier == 'd' || specifier == 'i')
		ft_putnbr_printf(va_arg(arg, int), count);
	else if (specifier == 's')
		*count += ft_putstr_printf(va_arg(arg, char *));
	else if (specifier == 'u')
		ft_putnbr_unsigned_printf(va_arg(arg, unsigned int), count);
	else if (specifier == 'x')
		ft_puthex_printf(va_arg(arg, unsigned int), count, 0);
	else if (specifier == 'X')
		ft_puthex_printf(va_arg(arg, unsigned int), count, 1);
	else if (specifier == 'p')
	{
		write(1, "0x", 2);
		*count += 2;
		ft_puthex_printf(va_arg(arg, unsigned long), count, 0);
	}
	else if (specifier == '%')
		ft_putchr_printf('%', count);
	else
		*count = -1;
}
