/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarriga <mdarriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 19:56:40 by mdarriga          #+#    #+#             */
/*   Updated: 2015/01/07 13:59:20 by mdarriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

static char		*cd_arg(char **arg)
{
	if (check_errors(arg[1], arg) == -1)
		return (NULL);
	chdir(arg[1]);
	return (arg[1]);
}

static char		*cd_home(char **env, int i, int j, char **arg)
{
	int		k;
	char	*to_go;

	k = 0;
	while (env[i] != 0 && ft_strncmp("HOME=", env[i], 5) != 0)
		i++;
	if (env[i] == 0)
	{
		ft_putendl("cd: HOME not set.");
		return (NULL);
	}
	if (!(to_go = (char *)malloc(sizeof(char) * ft_strlen(env[i]))))
		return (0);
	while (env[i][j] != 0)
	{
		to_go[k] = env[i][j];
		k++;
		j++;
	}
	if (check_errors(to_go, arg) == -1)
		return (NULL);
	chdir(to_go);
	return (to_go);
}

static char		*cd_path(char **arg, char **env, int i, int j)
{
	int		k;
	char	*to_go;

	k = 0;
	while (env[i] != 0 && ft_strncmp("PWD=", env[i], 4) != 0)
		i++;
	if (!(to_go = (char *)malloc(sizeof(char) * ft_strlen(env[i]))))
		return (0);
	while (env[i][j] != 0)
	{
		to_go[k] = env[i][j];
		k++;
		j++;
	}
	to_go = ft_strjoin(to_go, "/");
	to_go = ft_strjoin(to_go, arg[1]);
	if (check_errors(to_go, arg) == -1)
		return (NULL);
	else
	{
		chdir(to_go);
		return (to_go);
	}
}

static char		*prev_cd(char **env, int i, int j, char **arg)
{
	int		k;
	char	*to_go;

	k = 0;
	while (env[i] != 0 && ft_strncmp("OLDPWD=", env[i], 7) != 0)
		i++;
	if (!env[i])
		cd_arg(arg);
	if (!(to_go = (char *)malloc(sizeof(char) * ft_strlen(env[i]))))
		return (0);
	while (env[i][j] != 0)
	{
		to_go[k] = env[i][j];
		j++;
		k++;
	}
	if (check_errors(to_go, arg) == -1)
		return (NULL);
	else
	{
		chdir(to_go);
		return (to_go);
	}
}

void			ft_cd(char **arg, char **env)
{
	char	*new_pwd;

	new_pwd = NULL;
	if (!arg[1] || arg[1][0] == '~' || ft_strcmp(arg[1], "$HOME") == 0
		|| ft_strcmp(arg[1], "--") == 0)
		new_pwd = cd_home(env, 0, 5, arg);
	else if (ft_strcmp(arg[1], "-") == 0)
	{
		if (!env[0])
			chdir(arg[1]);
		else
			new_pwd = prev_cd(env, 0, 7, arg);
	}
	else if (arg[1][0] == '/')
		new_pwd = cd_arg(arg);
	else
	{
		if (!env[0])
			chdir(arg[1]);
		else
			new_pwd = cd_path(arg, env, 0, 4);
	}
	if (new_pwd != NULL)
		env = change_both_pwd(new_pwd, env);
}
