/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsayed <abdsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 15:10:26 by abdsayed          #+#    #+#             */
/*   Updated: 2024/09/29 19:08:52 by abdsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

void	initialize(t_pipex *pipex, char **args, char **env)
{
	pipex->av = args;
	pipex->env = env;
	pipex->bole = 0;
	pipex->fdi = -1;
	pipex->fdo = -1;
	pipex->pipes[0] = -1;
	pipex->pipes[1] = -1;
	pipex->path = NULL;
	pipex->pid1 = 0;
	pipex->pid2 = 0;
	pipex->token = NULL;
	return ;
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

char	*get_path_variable(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			return (envp[i] + 5);
		}
		i++;
	}
	return (NULL);
}
