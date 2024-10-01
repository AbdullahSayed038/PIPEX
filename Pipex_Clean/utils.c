/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsayed <abdsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 18:26:29 by abdsayed          #+#    #+#             */
/*   Updated: 2024/09/30 16:19:40 by abdsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*prepend_slash(char *str)
{
	size_t	new_length;
	char	*new_str;

	new_length = ft_strlen(str) + 2;
	new_str = (char *)malloc(new_length * sizeof(char));
	new_str[0] = '/';
	ft_strlcpy(new_str + 1, str, new_length);
	return (new_str);
}