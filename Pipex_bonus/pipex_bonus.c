/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsayed <abdsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 17:20:36 by abdsayed          #+#    #+#             */
/*   Updated: 2024/10/02 18:39:15 by abdsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	forking(t_pipex *pipex, int ac)
{
	while (pipex->i < ac)
	{
		if (pipex->i == 2)
			firstfork(pipex);
		if ((pipex->i > 2) && (pipex->i < ac - 2))
			midfork(pipex);
		if (pipex->i == ac - 2)
			lastfork(pipex);
		pipex->i++;
	}
	(close(pipex->pipes[1]), close(pipex->pipes[0]));
	return ;
}

int	main(int ac, char **av, char **env)
{
	t_pipex	pipex;
	int		w;

	w = 0;
	initialize(&pipex, av, env);
	if (ac < 5)
		exitfree("Invalid args", &pipex, 1);
	pipex.path = get_path_variable(env);
	if (pipex.path == NULL)
		pipex.bole = 1;
	if (ft_strncmp(av[1], "here_doc", 9) == 0)
		here_doc(&pipex);
	else
		forking(&pipex, ac);
	while (w < ac - 3 - (ft_strncmp(av[1], "here_doc", 9) == 0))
	{
		wait(NULL);
		w++;
	}
	waitpid(pipex.pid2, NULL, 0);
	exitfree(NULL, &pipex, 0);
	return (0);
}
