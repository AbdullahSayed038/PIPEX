/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsayed <abdsayed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:28:50 by abdsayed          #+#    #+#             */
/*   Updated: 2024/07/03 18:14:36 by abdsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		total;
	char	*sjoin;
	int		i;
	int		j;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	i = 0;
	j = 0;
	total = ft_strlen(s1) + ft_strlen(s2);
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	sjoin = malloc((sizeof(char) * total) + 1);
	if (!sjoin)
		return (NULL);
	while (s1[i])
		sjoin[j++] = s1[i++];
	i = 0;
	while (s2[i])
		sjoin[j++] = s2[i++];
	sjoin[j] = '\0';
	return (sjoin);
}
