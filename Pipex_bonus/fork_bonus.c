/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsayed <abdsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 18:33:47 by abdsayed          #+#    #+#             */
/*   Updated: 2024/10/02 19:49:57 by abdsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	exec(char *token, char *cmd, char **env, t_pipex *pipex)
{
	char	**cmds;
	char	**path;

	if (token == NULL || cmd == NULL || env == NULL || pipex == NULL)
		exitfree("Error1", pipex, 1);
	cmds = ft_split(cmd, ' ');
	if (cmds == NULL)
		(free(token), exitfree("Error2", pipex, 1));
	if (cmds[0] == NULL)
		(bigfree(cmds), exitfree("Error3", pipex, 1));
	path = ft_split(token, ' ');
	if (path == NULL)
		(bigfree(cmds), exitfree("Error4", pipex, 1));
	if (execve(path[0], cmds, env) < 0)
		(bigfree(cmds), exitfree("Error5", pipex, 1));
	return ;
}

void	firstfork(t_pipex *pipex)
{
	int	pid;

	if (pipe(pipex->pipes) == -1)
		exitfree("Error6", pipex, 1);
	pid = fork();
	if (pid == 0)
	{
		pipex->fdi = open(pipex->av[1], O_RDONLY);
		if (pipex->fdi < 0)
			(perror(pipex->av[1]), exitfree("Error7", pipex, 1));
		(dup2(pipex->fdi, 0), close(pipex->fdi));
		dup2(pipex->pipes[1], 1);
		(close(pipex->pipes[1]), close(pipex->pipes[0]));
		if (ft_strchr(pipex->av[2], '/') != NULL)
			pipex->token = ft_strdup(pipex->av[2]);
		else if (pipex->bole == 0)
			findtoken(pipex, pipex->av[2]);
		else
			exitfree("Error8", pipex, 1);
		if (pipex->token == NULL)
			exitfree("Error9", pipex, 1);
		exec(pipex->token, pipex->av[2], pipex->env, pipex);
		exitfree("", pipex, 0);
	}
	(dup2(pipex->pipes[0], 0), close(pipex->pipes[1]), close(pipex->pipes[0]));
}

void	midfork(t_pipex *pipex)
{
	int	pid;

	if (pipe(pipex->pipes) == -1)
		exitfree("Error10", pipex, 1);
	pid = fork();
	if (pid == 0)
	{
		dup2(pipex->pipes[1], 1);
		if (pipex->fdi > -1)
			close(pipex->fdi);
		if (pipex->fdo > -1)
			close(pipex->fdo);
		(close(pipex->pipes[1]), close(pipex->pipes[0]));
		if (ft_strchr(pipex->av[pipex->i], '/') != NULL)
			pipex->token = ft_strdup(pipex->av[pipex->i]);
		else if (pipex->bole == 0)
			findtoken(pipex, pipex->av[pipex->i]);
		else
			exitfree("Error11", pipex, 1);
		if (pipex->token == NULL)
			exitfree("Error12", pipex, 1);
		exec(pipex->token, pipex->av[pipex->i], pipex->env, pipex);
		exitfree("", pipex, 0);
	}
	(dup2(pipex->pipes[0], 0), close(pipex->pipes[1]), close(pipex->pipes[0]));
}

void	lastfork(t_pipex *pipex)
{
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		pipex->fdo = open(pipex->av[pipex->i + 1], \
			O_RDWR | O_CREAT | O_TRUNC, 0644);
		if (pipex->fdo < 0)
			(perror(pipex->av[pipex->i + 1]), exitfree(NULL, pipex, 1));
		dup2(pipex->fdo, STDOUT_FILENO);
		close(pipex->fdo);
		if (ft_strchr(pipex->av[pipex->i], '/') != NULL)
			pipex->token = ft_strdup(pipex->av[pipex->i]);
		else if (pipex->bole == 0)
			findtoken(pipex, pipex->av[pipex->i]);
		else
			exitfree("Error13", pipex, 1);
		exec(pipex->token, pipex->av[pipex->i], pipex->env, pipex);
		exitfree("", pipex, 1);
	}
	close(0);
}
