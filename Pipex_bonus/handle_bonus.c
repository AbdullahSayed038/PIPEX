/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsayed <abdsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 17:32:58 by abdsayed          #+#    #+#             */
/*   Updated: 2024/10/02 17:55:54 by abdsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	initialize(t_pipex *pipex, char **args, char **env)
{
	pipex->i = 1;
	pipex->av = args;
	pipex->env = env;
	pipex->bole = 0;
	pipex->fdi = -1;
	pipex->fdo = -1;
	pipex->pid2 = -1;
	pipex->pipes[0] = -1;
	pipex->pipes[1] = -1;
	pipex->docpipe[0] = -1;
	pipex->docpipe[1] = -1;
	pipex->path = NULL;
	pipex->token = NULL;
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

void	findtoken(t_pipex *pipex, char	*cmd)
{
	char	**tokens;
	char	**cmd2;
	char	*newcmd;

	cmd2 = ft_split(cmd, ' ');
	if (cmd2 == NULL)
		exitfree("Error", pipex, 1);
	if (cmd2[0] == NULL)
		(bigfree(cmd2), exitfree("Error", pipex, 1));
	tokens = ft_split(pipex->path, ':');
	if (tokens == NULL)
		exitfree("Error", pipex, 1);
	newcmd = prepend_slash(cmd2[0]);
	if (newcmd == NULL)
	{
		bigfree(tokens);
		bigfree(cmd2);
		exitfree("Error", pipex, 1);
	}
	findtoken2(newcmd, tokens, pipex);
	bigfree(cmd2);
	bigfree(tokens);
	return ;
}

void	findtoken2(char *cmd, char **tokens, t_pipex *pipex)
{
	int		i;
	char	*tokenss;

	i = 0;
	while (tokens[i])
	{
		tokenss = ft_strjoin(tokens[i], cmd);
		if (tokenss == NULL)
			(bigfree(tokens), free(cmd), exitfree(NULL, pipex, 1));
		if (access(tokenss, X_OK) == 0)
		{
			free(pipex->token);
			pipex->token = ft_strdup(tokenss);
			free(tokenss);
			free(cmd);
			return ;
		}
		free(tokenss);
		tokenss = NULL;
		i++;
	}
	if (tokenss)
		free(tokenss);
	(free(cmd), pipex->token = NULL);
	return ;
}
