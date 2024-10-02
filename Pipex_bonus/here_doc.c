/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsayed <abdsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 17:54:48 by abdsayed          #+#    #+#             */
/*   Updated: 2024/10/02 19:35:36 by abdsayed         ###   ########.fr       */
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
		if (ft_strchr(pipex->av[3], '/') != NULL)
			pipex->token = pipex->av[3];
		else if (pipex->bole == 0)
			findtoken(pipex, pipex->av[3]);
		else
			exitfree("Error14", pipex, 1);
		exec(pipex->token, pipex->av[3], pipex->env, pipex);
		exitfree("", pipex, 1);
	}
	return ;
}

void	startforking(t_pipex *pipex)
{
	int	pid;

	if (pipe(pipex->pipes) == -1)
		exitfree("Error15", pipex, 1);
	pid = fork();
	if (pid == 0)
	{
		dup2(pipex->docpipe[0], 0);
		close(pipex->docpipe[0]);
		dup2(pipex->pipes[1], 1);
		(close(pipex->pipes[1]), close(pipex->pipes[0]));
		fprintf(STDIN_FILENO, "%i\n", pipex->bole);
		if (ft_strchr(pipex->av[2], '/') != NULL)
			pipex->token = ft_strdup(pipex->av[2]);
		else if (pipex->bole == 0)
			findtoken(pipex, pipex->av[2]);
		else
			exitfree("Error16", pipex, 1);
		if (pipex->token == NULL)
			exitfree("Error17", pipex, 1);
		exec(pipex->token, pipex->av[2], pipex->env, pipex);
		exitfree("", pipex, 0);
	}
}

void	here_doc(t_pipex *pipex)
{
	char	*str;

	if (pipe(pipex->docpipe) == -1)
		exitfree("Error18", pipex, 1);
	str = get_next_line(0);
	while (ft_strnstr(str, pipex->av[2], ft_strlen(str)) == NULL)
	{
		ft_printf("%s\n", str);
		free(str);
		str = get_next_line(0);
		write(pipex->docpipe[1], str, ft_strlen(str));
	}
	free(str);
	close(pipex->docpipe[1]);
	startforking(pipex);
	(close(pipex->docpipe[0]), close(pipex->docpipe[1]));
	secondfork(pipex);
	close(0);
}
