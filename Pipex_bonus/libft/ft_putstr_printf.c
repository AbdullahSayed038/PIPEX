/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsayed <abdsayed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 12:18:49 by abdsayed          #+#    #+#             */
/*   Updated: 2024/07/09 13:26:14 by abdsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_printf(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		count += 6;
		return (count);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	count = i;
	return (count);
}
