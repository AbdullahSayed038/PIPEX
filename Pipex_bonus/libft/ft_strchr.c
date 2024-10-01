/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsayed <abdsayed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:27:36 by abdsayed          #+#    #+#             */
/*   Updated: 2024/07/02 14:13:47 by abdsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int i)
{
	while (*s)
	{
		if (*s == (char)i)
			return ((char *)s);
		s++;
	}
	if ((char)i == '\0')
		return ((char *)s);
	return (0);
}
