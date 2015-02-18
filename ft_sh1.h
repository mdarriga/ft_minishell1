/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh1.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdarriga <mdarriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 14:24:49 by mdarriga          #+#    #+#             */
/*   Updated: 2015/02/03 14:09:07 by mdarriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SH1_H
# define FT_SH1_H
# define BUFF_SIZE 2048

# include "libft/libft.h"
# include <signal.h>
# include <sys/stat.h>

int		get_next_line(int fd, char **line);
int		check_errors(char *to_go, char **arg);
int		search_line(char **env);
int		main(int ac, char **av, char **env);
void	ft_exec(char **arg, char **env);
void	ft_cd(char **arg, char **env);
void	exec_arg(char **arg, char **env);
void	print_errors(char **arg);
void	close_shell();
void	exec_path(char *bin_path, char **arg);
char	**unset_env(char **env, char **arg);
char	**check_arg(char **av, char **env);
char	**set_env(char **env, char **arg, int j);
char	**create_arg(char **arg, char *buf);
char	**change_both_pwd(char *new_pwd, char **env);

#endif
