/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsayed <abdsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 15:07:59 by abdsayed          #+#    #+#             */
/*   Updated: 2024/10/01 17:11:24 by abdsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	forking(t_pipex *pipex)
{
	if (pipe(pipex->pipes) == -1)
		exitfree("Error", pipex, 1);
	firstchild(pipex);
	secondchild(pipex);
	return ;
}

int	main(int ac, char **av, char **env)
{
	t_pipex	pipex;

	initialize(&pipex, av, env);
	if (ac != 5)
		exitfree("Error Invalid Number of Arguments", &pipex, 1);
	pipex.path = get_path_variable(env);
	if (pipex.path == NULL)
		pipex.bole = 1;
	forking(&pipex);
	waitpid(pipex.pid1, NULL, 0);
	waitpid(pipex.pid2, NULL, 0);
	exitfree(NULL, &pipex, 0);
	return (0);
}