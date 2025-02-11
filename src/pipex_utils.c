/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isegura- <isegura-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:51:10 by isegura-          #+#    #+#             */
/*   Updated: 2025/02/11 17:32:34 by isegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

char	*env_path(char **env)
{
	int	i;

	i = 0;
	while (env)
	{
		if (ft_strncmp (env[i], "PATH=", 5) == 0)
			return (&env[i][5]);
		i++;
	}
	return (NULL);
}

char	*get_def_path(char **env, char *command)
{
	char	**spl;
	int		i;
	char	*final_path;
	char	*path;

	i = 0;
	spl = ft_split(env_path(env), ':');
	while (spl[i])
	{
		path = ft_strjoin(spl[i], "/");
		final_path = ft_strjoin(path, command);
		if (access(final_path, F_OK | X_OK) == 0)
		{
			free(path);
			free_spl(spl);
			return (final_path);
		}
		i++;
		free (final_path);
		free (path);
	}
	free_spl(spl);
	return (final_path);
}

int	open_file(char *file, int flag)
{
	int	ret;

	if (flag == 0)
		ret = open(file, O_RDONLY, 0777);
	if (flag == 1)
		ret = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (ret == -1)
		error("Error open file");
	return (ret);
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
