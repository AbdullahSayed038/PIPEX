/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsayed <abdullahsayed@42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 17:54:48 by abdsayed          #+#    #+#             */
/*   Updated: 2024/10/02 21:45:37 by abdsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	secondfork(t_pipex *pipex)
{
	pipex->pid2 = fork();
	if (pipex->pid2 == 0)
	{
		pipex->fdo = open(pipex->av[5], O_RDWR | O_CREAT | O_APPEND, 0644);
		if (pipex->fdo < 0)
			(perror(pipex->av[5]), exitfree(NULL, pipex, 1));
		dup2(pipex->pipes[0], 0);
		dup2(pipex->fdo, 1);
		(close(pipex->fdo), close(pipex->pipes[0]), close(pipex->pipes[1]));
		if (ft_strchr(pipex->av[4], '/') != NULL)
			pipex->token = pipex->av[4];
		else if (pipex->bole == 0)
			findtoken(pipex, pipex->av[4]);
		else
			exitfree("Error14", pipex, 1);
		exec(pipex->token, pipex->av[4], pipex->env, pipex);
		exitfree("", pipex, 1);
	}
	close(0), close(1);
}

void	startforking(t_pipex *pipex)
{
	int	pid;

	if (pipe(pipex->pipes) == -1)
		exitfree("Error15", pipex, 1);
	pid = fork();
	if (pid == 0)
	{
		dup2(pipex->docpipe[0], STDIN_FILENO);
		close(pipex->docpipe[0]);
		dup2(pipex->pipes[1], STDOUT_FILENO);
		(close(pipex->pipes[1]), close(pipex->pipes[0]));
		if (ft_strchr(pipex->av[3], '/') != NULL)
			pipex->token = ft_strdup(pipex->av[3]);
		else if (pipex->bole == 0)
			findtoken(pipex, pipex->av[3]);
		else
			exitfree("Error16", pipex, 1);
		if (pipex->token == NULL)
			exitfree("Error17", pipex, 1);
		exec(pipex->token, pipex->av[3], pipex->env, pipex);
		exitfree("", pipex, 0);
	}
	close(pipex->docpipe[0]);
}

void	here_doc(t_pipex *pipex)
{
	char	*str;
	int		len;

	if (pipe(pipex->docpipe) == -1)
		exitfree("Error18", pipex, 1);
	str = get_next_line(0);
	len = ft_strlen(pipex->av[2]);
	pipex->av[2][len] = '\n';
	while (ft_strncmp(pipex->av[2], str, len + 1))
	{
		if (write(pipex->docpipe[1], str, ft_strlen(str)) < 0)
			exitfree("Error", pipex, 1);
		free(str);
		str = get_next_line(0);
	}
	free(str);
	close(pipex->docpipe[1]);
	startforking(pipex);
	(close(pipex->docpipe[0]));
	secondfork(pipex);
	close(pipex->pipes[1]), close(pipex->pipes[0]);	
}
