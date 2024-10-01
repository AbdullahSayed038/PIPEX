/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsayed <abdsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 15:03:59 by abdsayed          #+#    #+#             */
/*   Updated: 2024/09/29 18:51:11 by abdsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include "libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>

typedef	struct s_pipex
{
	char	**av;
	char	**env;
	char	*token;
	char	*path;
	int		pipes[2];
	int		fdi;
	int		fdo;
	int		pid1;
	int		pid2;
	int		bole;
}	t_pipex;

void	initialize(t_pipex *pipex, char **args, char **env);
void	exitfree(char *str, t_pipex *pipex, int status);
char	*get_path_variable(char **envp);
void	firstchild(t_pipex *pipex);
void	secondchild(t_pipex *pipex);
void	findtoken(t_pipex *pipex, char	*cmd);
void	findtoken2(char *cmd, char **tokens, t_pipex *pipex);
char	*prepend_slash(char *str);
void	bigfree(char **str);


#endif