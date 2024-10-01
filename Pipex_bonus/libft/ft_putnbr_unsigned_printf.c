/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsayed <abdsayed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 11:54:20 by abdsayed          #+#    #+#             */
/*   Updated: 2024/07/09 11:59:51 by abdsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_unsigned_printf(unsigned int nb, int *count)
{
	char	c;

	if (nb >= 10)
	{
		ft_putnbr_unsigned_printf(nb / 10, count);
	}
	c = (nb % 10) + '0';
	write(1, &c, 1);
	*count += 1;
}
