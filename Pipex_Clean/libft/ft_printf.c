/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsayed <abdsayed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 12:21:53 by abdsayed          #+#    #+#             */
/*   Updated: 2024/07/09 12:25:46 by abdsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *word, ...)
{
	int		count;
	va_list	arg;
	int		i;

	count = 0;
	i = 0;
	if (!word)
		return (-1);
	va_start(arg, word);
	while (word && word[i])
	{
		if (word[i] == '%')
			ft_printarg(word[++i], arg, &count);
		else
		{
			write(1, &word[i], 1);
			count++;
		}
		i++;
		if (count == -1)
			break ;
	}
	va_end(arg);
	return (count);
}
