/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdsayed <abdsayed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 17:20:44 by abdsayed          #+#    #+#             */
/*   Updated: 2024/10/02 18:38:26 by abdsayed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdlib.h>
# include "libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>

typedef struct s_pipex
{
	int		i;
	char	**av;
	char	**env;
	char	*token;
	char	*path;
	int		pipes[2];
	int		docpipe[2];
	int		pid2;
	int		fdi;
	int		fdo;
	int		bole;
}	t_pipex;

void	initialize(t_pipex *pipex, char **args, char **env);
char	*get_path_variable(char **envp);
void	findtoken(t_pipex *pipex, char	*cmd);
void	lastfork(t_pipex *pipex);
void	midfork(t_pipex *pipex);
void	firstfork(t_pipex *pipex);
char	*prepend_slash(char *str);
void	bigfree(char **str);
void	exitfree(char *str, t_pipex *pipex, int status);
void	findtoken2(char *cmd, char **tokens, t_pipex *pipex);
void	exec(char *token, char *cmd, char **env, t_pipex *pipex);
void	here_doc(t_pipex *pipex);

#endif