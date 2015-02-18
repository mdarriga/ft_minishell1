/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarriga <mdarriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 16:16:43 by mdarriga          #+#    #+#             */
/*   Updated: 2015/01/20 12:12:53 by mdarriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

int				check_errors(char *to_go, char **arg)
{
	if (access(to_go, F_OK) == -1)
	{
		ft_putstr("cd: no such file or directory: ");
		ft_putendl(arg[1]);
		return (-1);
	}
	else if (access(to_go, X_OK) == -1)
	{
		ft_putstr("cd: permission denied: ");
		ft_putendl(arg[1]);
		return (-1);
	}
	return (0);
}

int				search_line(char **env)
{
	int	i;

	i = 0;
	while (env[i] != 0 && ft_strncmp("PATH=", env[i], 5) != 0)
		i++;
	if (env[i] == 0)
		return (-1);
	else
		return (i);
}

char			**create_arg(char **arg, char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	line = ft_strtrim(line);
	line = ft_strskip(line, '\t');
	arg = ft_strsplit(line, ' ');
	while (arg[i] != '\0')
		i++;
	i--;
	if (i == -1)
		return (NULL);
	while (arg[i][j] != '\0')
	{
		j++;
	}
	arg[i][j] = '\0';
	return (arg);
}

void			print_errors(char **arg)
{
	if (ft_strcmp(arg[0], "setenv") != 0 && ft_strcmp(arg[0], "env") != 0
		&& ft_strcmp(arg[0], "cd") != 0 && ft_strcmp(arg[0], "unsetenv") != 0
		&& arg[0][0] != '\0' && arg[0][0] != 9)
	{
		ft_putstr("sh1: command not found: ");
		ft_putendl(arg[0]);
	}
}

void			ft_exec(char **arg, char **env)
{
	int		i;
	int		bwait[1];
	pid_t	father;
	char	**bin_path;

	i = search_line(env);
	if (i == -1)
		return ;
	father = fork();
	bin_path = ft_strsplit(env[i] + 5, ':');
	i = 0;
	if (father > 0)
		wait(bwait);
	if (father == 0)
	{
		while (bin_path[i] != '\0')
		{
			exec_path(bin_path[i], arg);
			i++;
		}
		if (arg[0] != NULL)
			print_errors(arg);
		exit(0);
	}
}
