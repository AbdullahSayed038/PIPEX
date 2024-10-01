/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsayed <abdsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 19:02:24 by abdsayed          #+#    #+#             */
/*   Updated: 2024/10/01 19:05:15 by abdsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

void	exitfree(char *str, t_pipex *pipex, int status)
{
	if (str != NULL)
		ft_putendl_fd(str, 2);
	if (pipex->token != NULL)
		free(pipex->token);
	if (pipex->pipes[0] > -1)
		close(pipex->pipes[0]);
	if (pipex->pipes[1] > -1)
		close(pipex->pipes[1]);
	if (pipex->fdi > -1)
		close(pipex->fdi);
	if (pipex->fdo > -1)
		close(pipex->fdo);
	if (status == 1)
		exit(1);
	else
		return ;
}

void	bigfree(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return ;
}
