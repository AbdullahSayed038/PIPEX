/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsayed <abdsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 17:25:28 by abdsayed          #+#    #+#             */
/*   Updated: 2024/10/01 18:01:32 by abdsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec(char *token, char *cmd, char **env, t_pipex *pipex)
{
	char	**cmds;
	char	**path;

	if (token == NULL || cmd == NULL || env == NULL || pipex == NULL)
		exitfree("Error", pipex, 1);
	cmds = ft_split(cmd, ' ');
	if (cmds == NULL)
		(free(token), exitfree("Error", pipex, 1));
	if (cmds[0] == NULL)
		(bigfree(cmds), exitfree("Error", pipex, 1));
	path = ft_split(token, ' ');
	if (path == NULL)
		(bigfree(cmds), exitfree("Error", pipex, 1));
	if (execve(path[0], cmds, env) < 0)
		(bigfree(cmds), exitfree("Error", pipex, 1));
	return ;
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
	while(tokens[i])
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

void	secondchild(t_pipex *pipex)
{
	pipex->pid2 = fork();
	if (pipex->pid2 == 0)
	{
		pipex->fdo = open(pipex->av[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
		if (pipex->fdo < 0)
			(perror(pipex->av[4]), exitfree(NULL, pipex, 1));
		dup2(pipex->fdo, STDOUT_FILENO);
		close(pipex->fdo);
		dup2(pipex->pipes[0], STDIN_FILENO);
		(close(pipex->pipes[1]), close(pipex->pipes[0]));
		if (ft_strchr(pipex->av[3], '/') != NULL)
			pipex->token = pipex->av[3];
		else if (pipex->bole == 0)
			findtoken(pipex, pipex->av[3]);
		else
			exitfree("Error", pipex, 1);
		exec(pipex->token, pipex->av[3], pipex->env, pipex);
		exitfree("", pipex, 1);
	}
	return ;
}

void	firstchild(t_pipex *pipex)
{
	pipex->pid1 = fork();
	if (pipex->pid1 == 0)
	{
		pipex->fdi = open(pipex->av[1], O_RDONLY);
		if (pipex->fdi < 0)
			(perror(pipex->av[1]), exitfree("Error", pipex, 1));
		dup2(pipex->fdi, 0);
		close(pipex->fdi);
		dup2(pipex->pipes[1], 1);
		(close(pipex->pipes[1]), close(pipex->pipes[0]));
		if (ft_strchr(pipex->av[2], '/') != NULL)
			pipex->token = pipex->av[2];
		else if (pipex->bole == 0)
			findtoken(pipex, pipex->av[2]);
		else
			exitfree("Error", pipex, 1);
		if (pipex->token == NULL)
			exitfree("Error", pipex, 1);
		exec(pipex->token, pipex->av[2], pipex->env, pipex);
		exitfree("", pipex, 0);
	}
	return ;
}
