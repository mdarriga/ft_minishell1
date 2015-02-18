/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarriga <mdarriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 14:24:43 by mdarriga          #+#    #+#             */
/*   Updated: 2015/01/20 12:13:23 by mdarriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

int g_prompt;

static void	sighandler(int s)
{
	if (s == 2)
	{
		ft_putstr("\n$> ");
		g_prompt = 0;
	}
}

int			main(int ac, char **av, char **env)
{
	char	**envcpy;
	char	**arg;
	char	*line;

	(void)ac;
	(void)av;
	envcpy = tabcpy(env);
	while (42)
	{
		g_prompt = 1;
		signal(2, sighandler);
		g_prompt == 0 ? g_prompt = 1 : ft_putstr("$> ");
		if (get_next_line(0, &line) == 0)
			close_shell();
		if (line[0] != '\0')
		{
			arg = create_arg(arg, line);
			ft_strclr(line);
			if (arg != NULL && ft_strncmp(arg[0], ".", 1) != 0 &&
			ft_strncmp(arg[0], "/", 1) != 0)
				envcpy = check_arg(arg, envcpy);
			else if (arg != NULL)
				exec_arg(arg, envcpy);
		}
	}
}
