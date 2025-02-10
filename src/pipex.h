/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isegura- <isegura-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:51:31 by isegura-          #+#    #+#             */
/*   Updated: 2025/02/10 15:47:45 by isegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>

void	error(char *msg);
void	parent_process(char **env, char **av, int *connection_pipe);
void	child_process(char **env, char **av, int *connection_pipe);
char	*env_path(char **env);
char	*get_def_path(char **start_path, char *command);
void	free_spl(char **arr);
int		open_file(char *file, int flag);

#endif
