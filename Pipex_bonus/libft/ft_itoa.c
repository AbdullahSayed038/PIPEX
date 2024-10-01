/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsayed <abdsayed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:22:26 by abdsayed          #+#    #+#             */
/*   Updated: 2024/07/03 15:46:31 by abdsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

size_t	ft_intlen(int nb)
{
	int	len;

	len = 0;
	if (nb <= 0)
	{
		len++;
	}
	while (nb)
	{
		len++;
		nb /= 10;
	}
	return ((size_t)len);
}

char	*ft_itoa(int nb)
{
	char			*str;
	size_t			length;
	long			nbr;

	length = ft_intlen(nb);
	nbr = nb;
	str = malloc((sizeof(char) * length) + 1);
	if (!str)
		return (NULL);
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = -nbr;
	}
	if (nbr == 0)
		str[0] = '0';
	str[length] = '\0';
	length--;
	while (nbr != 0)
	{
		str[length--] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (str);
}
