/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isegura- <isegura-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:51:31 by isegura-          #+#    #+#             */
/*   Updated: 2025/02/11 20:37:15 by isegura-         ###   ########.fr       */
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
# include <sys/types.h>
# include <sys/wait.h>

void	parent_process(pid_t fork_pid_1, pid_t fork_pid_2);
void	error(char *msg);
char	*env_path(char **env);
char	*get_def_path(char **start_path, char *command);
void	free_spl(char **arr);
int		open_file(char *file, int flag);

#endif
