/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsayed <abdsayed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 12:00:27 by abdsayed          #+#    #+#             */
/*   Updated: 2024/07/09 13:53:00 by abdsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puthex_printf(unsigned long num, int *count, int uppercase)
{
	char	c;
	char	*hex_digitsup;
	char	*hex_digitsdown;

	hex_digitsup = "0123456789ABCDEF";
	hex_digitsdown = "0123456789abcdef";
	if (num >= 16)
		ft_puthex_printf(num / 16, count, uppercase);
	if (uppercase == 1)
		c = hex_digitsup[num % 16];
	else if (uppercase == 0)
		c = hex_digitsdown[num % 16];
	write(1, &c, 1);
	*count += 1;
}
