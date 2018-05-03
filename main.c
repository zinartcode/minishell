/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 16:29:15 by azinnatu          #+#    #+#             */
/*   Updated: 2018/05/02 21:01:02 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern char	**environ;

int		main(int ac, char **av, char **envp)
{
	char	**env;

	// env = environ;
	(void)ac;
	(void)av;
	create_env(&env, envp);
	process_args(env, envp);
	free_env(env);
	return (0);
}

void	process_args(char **env, char **envp)
{
	char	**cmd;

	while (1)
	{
		ft_putstr_fd(GRN"m_sh$> "NRM, 1);
		cmd = read_input();
		// print_env(cmd);
		if (cmd[0] && ft_strcmp(cmd[0], "exit") == 0)
		{
			ft_printf("%s\n", "exit");
			exit(0);
		}
		else if (cmd[0] && ft_strcmp(cmd[0], "cd") == 0)
			ft_cd(cmd, env);
		else if (cmd[0] && ft_strcmp(cmd[0], "env") == 0)
			print_env(env);
		else if (cmd[0] && ft_strcmp(cmd[0], "setenv") == 0)
			ft_printf("%s\n", "run setenv"); // envp = ft_setenv(cmd, &envp, env);
		else if (cmd[0] && ft_strcmp(cmd[0], "unsetenv") == 0)
			ft_printf("%s\n", "run unsetenv"); //envp = ft_unsetenv(cmd, &envp, env);
		else if (cmd[0] && ft_strcmp(cmd[0], "echo") == 0)
			ft_printf("%s\n", "run echo"); //envp = ft_echo(cmd, &envp, env);
		else
			ft_cmd(cmd, env, envp);
		free_env(cmd);
	}
}

char	**read_input(void)
{
	char	*command;
	char	**args;
	int		i;

	args = NULL;
	get_next_line(0, &command);
	format_str(&command);
	args = ft_strsplit(command, ' ');
	i = 0;
	while (args && args[i])
	{
		if (args[i][0] == '\'' || args[i][0] == '"')
		{
			args[i]++;
			if (args[i][ft_strlen(args[i]) - 1] == '\'' ||
					args[i][ft_strlen(args[i]) - 1] == '"')
				args[i][ft_strlen(args[i]) - 1] = 0;
		}
		i++;
	}
	if (command)
		free(command);
	return (args);
}

void	format_str(char **line)
{
	int	i;

	i = 0;
	while ((*line)[i] != 0)
	{
		if ((*line)[i] == '\t')
			(*line)[i] = ' ';
		if ((*line)[i] == '\'' || (*line)[i] == '"')
			;
		i++;
	}
}