/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isegura- <isegura-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:50:51 by isegura-          #+#    #+#             */
/*   Updated: 2025/02/04 17:04:13 by isegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parent_process(char **env, char **av, int *connection_pipe)
{
	char	**commands;
	int		fd;
	char	*final_path;

	commands = ft_split(av[3], ' ');
	fd = open_file(av[4], 1);
	final_path = get_def_path(env, commands[0]);
	if (!final_path)
		error("Error with path");
	dup2(fd, 1);
	dup2(connection_pipe[0], 0);
	close(connection_pipe[1]);
	if (execve(final_path, commands, env) == -1)
	{
		free_spl(commands);
		error("Error in execve");
	}
}

void	child_process(char **env, char **av, int *connection_pipe)
{
	char	**commands;
	int		fd;
	char	*final_path;

	commands = ft_split(av[2], ' ');
	fd = open_file(av[1], 0);
	final_path = get_def_path(env, commands[0]);
	if (!final_path)
		error("Error with path");
	dup2(fd, 0);
	dup2(connection_pipe[1], 1);
	close(connection_pipe[0]);
	if (execve(final_path, commands, env) == -1)
	{
		free_spl(commands);
		error("Error in execve");
	}
}

int	main(int ac, char **av, char **env)
{
	int		connect_pipe[2];
	pid_t	fork_pid;


	if (ac != 5)
		error("Invalid number of arguments");
	if (pipe(connect_pipe) == -1)
		error("Error in pipe creation");
	fork_pid = fork();
	if (fork_pid == -1)
		error("Fork fail");
	if (!fork_pid)
		child_process(env, av, connect_pipe);
	parent_process(env, av, connect_pipe);
	return (0);
}
