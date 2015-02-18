/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarriga <mdarriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 12:39:20 by mdarriga          #+#    #+#             */
/*   Updated: 2015/01/06 20:09:53 by mdarriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

static char	**fill_tab(char **env, char **new_env, char **arg, int j)
{
	int	i;
	int	n;

	i = 0;
	n = ft_strlen(arg[j]);
	while (env[i] != 0 && (ft_strncmp(arg[j], env[i], n) != 0))
	{
		i++;
		if (env[i] == 0)
			return (env);
	}
	n = 0;
	while (n < i)
	{
		new_env[n] = env[n];
		n++;
	}
	i++;
	while (env[i++] != 0)
	{
		new_env[n] = env[i];
		n++;
	}
	new_env[n] = NULL;
	return (new_env);
}

char		**unset_env(char **env, char **arg)
{
	int		i;
	int		j;
	char	**new_env;

	i = ft_tablen(env);
	j = 1;
	if (!(new_env = (char **)malloc(sizeof(char *) * i)))
		return (NULL);
	while (arg[j] != 0)
	{
		new_env = fill_tab(env, new_env, arg, j);
		env = new_env;
		j++;
	}
	return (new_env);
}
