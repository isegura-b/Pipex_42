/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isegura- <isegura-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:50:51 by isegura-          #+#    #+#             */
/*   Updated: 2025/02/11 20:38:07 by isegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parent_process(pid_t fork_pid_1, pid_t fork_pid_2)
{
	waitpid (fork_pid_1, (int *) NULL, 0);
	waitpid (fork_pid_2, (int *) NULL, 0);
}

void	child_process_2(char **env, char **av, int *connection_pipe)
{
	char	**commands;
	int		fd;
	char	*final_path;

	commands = ft_split(av[3], ' ');
	fd = open_file(av[4], 1);
	final_path = get_def_path(env, commands[0]);
	if (!final_path)
		error("pipex: command not found");
	dup2(fd, 1);
	close(fd);
	dup2(connection_pipe[0], 0);
	close(connection_pipe[1]);
	close(connection_pipe[0]);
	if (execve(final_path, commands, env) == -1)
	{
		free_spl(commands);
		error("pipex: command not found");
	}
}

void	child_process_1(char **env, char **av, int *connection_pipe)
{
	char	**commands;
	int		fd;
	char	*final_path;

	commands = ft_split(av[2], ' ');
	fd = open_file(av[1], 0);
	final_path = get_def_path(env, commands[0]);
	if (!final_path)
		error("pipex: command not found");
	dup2(fd, 0);
	close(fd);
	dup2(connection_pipe[1], 1);
	close(connection_pipe[1]);
	close(connection_pipe[0]);
	if (execve(final_path, commands, env) == -1)
	{
		free_spl(commands);
		error("pipex: command not found");
	}
}

int	main(int ac, char **av, char **env)
{
	int		connect_pipe[2];
	pid_t	fork_pid_1;
	pid_t	fork_pid_2;

	if (ac != 5)
		error("Invalid number of arguments");
	if (pipe(connect_pipe) == -1)
		error("Error in pipe creation");
	fork_pid_1 = fork();
	if (fork_pid_1 == -1)
		error("Fork fail");
	if (!fork_pid_1)
		child_process_1(env, av, connect_pipe);
	fork_pid_2 = fork();
	if (fork_pid_2 == -1)
		error("Fork fail");
	if (!fork_pid_2)
		child_process_2(env, av, connect_pipe);
	close(connect_pipe[1]);
	close(connect_pipe[0]);
	parent_process(fork_pid_1, fork_pid_2);
	return (0);
}
