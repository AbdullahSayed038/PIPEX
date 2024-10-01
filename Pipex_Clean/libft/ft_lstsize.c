/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsayed <abdsayed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:24:20 by abdsayed          #+#    #+#             */
/*   Updated: 2024/07/02 13:45:04 by abdsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	ft_lstsize(t_list *lst)
{
	t_list	*ptr;
	int		size;

	size = 1;
	if (lst == NULL)
		return (0);
	ptr = lst;
	while (ptr->next != NULL)
	{
		size++;
		ptr = ptr->next;
	}
	return (size);
}
