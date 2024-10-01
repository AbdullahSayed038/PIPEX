/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsayed <abdsayed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:22:16 by abdsayed          #+#    #+#             */
/*   Updated: 2024/07/03 16:59:09 by abdsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*ptr;
	t_list	*deletion;

	if (!lst || !*lst || !del)
		return ;
	ptr = *lst;
	while (ptr != NULL)
	{
		del(ptr->content);
		deletion = ptr;
		ptr = ptr->next;
		free(deletion);
	}
	*lst = NULL;
}
