/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isegura- <isegura-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:51:10 by isegura-          #+#    #+#             */
/*   Updated: 2025/01/20 15:14:24 by isegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

char	*env_path(char *name, char **env)
{
	int		i;
	int		j;
	char	*sub;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] && env[i][j] != '=')
			j++;
		sub = ft_substr(env[i], 0, j);
		if (ft_strcmp(sub, name) == 0)
		{
			free(sub);
			return (env[i] + j + 1);
		}
		free(sub);
		i++;
	}
	return (NULL);
}


char	*get_def_path(char **start_path, char *command)
{
	int		i;
	char	**final_path;
	char	*path;
	char	**spl_com;
	char	*ret;

	i = 0;
	final_path = ft_split(env_path("PATH", env), ':');
	spl_com = ft_split(command, ' ')
	while (final_path[i])
	{
		path = ft_strjoin(final_path[i], "/");
		ret = ft_strjoin(path, spl_com[0]);
		if (access(final_path, F_OK | X_OK) == 0)
		{
			free_spl(spl_com);
			return (ret);
		}
		free(ret);
		i++;
	}
	free_spl(final_path);
	free_spl(spl_com);
	return (final_path);
}

int	open_file(char *file, int flag)
{
	int	return;

	if (flag == 0)
		return = open(file, O_RDONLY, 0777);
	if (flag == 1)
		return = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (ret == -1)
		error("Error open file");
	return (return);
}

void	free_spl(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}