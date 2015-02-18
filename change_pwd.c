/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_pwd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarriga <mdarriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 16:48:17 by mdarriga          #+#    #+#             */
/*   Updated: 2015/01/06 17:38:22 by mdarriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

static char	**change_pwd(char **env, char *new_pwd, int pwd_pos, int j)
{
	int		i;
	char	*final_pwd;

	i = 0;
	if (!(final_pwd = malloc(sizeof(char) * (ft_strlen(new_pwd) + 5))))
		return (env);
	while (env[pwd_pos] != 0 && ft_strncmp("PWD=", env[pwd_pos], 4) != 0)
		pwd_pos++;
	while (i < 4)
	{
		final_pwd[i] = env[pwd_pos][i];
		i++;
	}
	while (new_pwd[j] != '\0')
	{
		final_pwd[i] = new_pwd[j];
		i++;
		j++;
	}
	final_pwd[i] = '\0';
	env[pwd_pos] = final_pwd;
	return (env);
}

static char	**change_old_pwd(char **env, int pwd_pos, int old_pos, int j)
{
	char	*new_old;
	int		k;

	k = 7;
	while (env[pwd_pos] != 0 && ft_strncmp("PWD=", env[pwd_pos], 4) != 0)
		pwd_pos++;
	while (env[old_pos] != 0 && ft_strncmp("OLDPWD=", env[old_pos], 7) != 0)
		old_pos++;
	if (!(new_old = malloc(sizeof(char) * (ft_strlen(env[pwd_pos]) + 4))))
		return (env);
	while (j < 7)
	{
		new_old[j] = env[old_pos][j];
		j++;
	}
	j = 4;
	while (env[pwd_pos][j] != 0)
	{
		new_old[k] = env[pwd_pos][j];
		j++;
		k++;
	}
	new_old[k] = '\0';
	env[old_pos] = new_old;
	return (env);
}

char		**change_both_pwd(char *new_pwd, char **env)
{
	env = change_old_pwd(env, 0, 0, 0);
	env = change_pwd(env, new_pwd, 0, 0);
	return (env);
}
