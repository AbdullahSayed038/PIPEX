/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsayed <abdsayed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 12:20:57 by abdsayed          #+#    #+#             */
/*   Updated: 2024/07/09 12:21:29 by abdsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_printf(int nb, int *count)
{
	char	c;

	if (nb < 0)
	{
		write(1, "-", 1);
		*count += 1;
		if (nb == -2147483648)
		{
			write(1, "2147483648", 10);
			*count += 10;
			return ;
		}
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr_printf(nb / 10, count);
	}
	c = (nb % 10) + '0';
	write(1, &c, 1);
	*count += 1;
}
