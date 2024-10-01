/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsayed <abdsayed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 13:10:20 by abdsayed          #+#    #+#             */
/*   Updated: 2024/07/03 17:29:52 by abdsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	if (!s1 && !s2)
		return (NULL);
	d = (unsigned char *)s1;
	s = (unsigned char *)s2;
	if (s < d && d < s + n)
		while (n--)
			d[n] = s[n];
	else
		while (n--)
			*(d++) = *(s++);
	return (s1);
}
