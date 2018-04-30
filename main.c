/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 16:29:15 by azinnatu          #+#    #+#             */
/*   Updated: 2018/04/30 15:20:34 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern char	**environ;

int		main(int ac, char **av, char **envp)
{
	char	**env;
	char	**cmd;

	env = environ;

	(void)ac;
	(void)av;
	// while (*env != NULL)
	// {
	// 	ft_printf("%s\n", *env);
	// 	*env++;
	// }

	while (1)
	{
		ft_putstr_fd(GRN"msh$> "NRM, 1);
		cmd = readinput();
		if (cmd[0] && ft_strcmp(cmd[0], "exit") == 0)
			exit(0);
		else if (cmd[0] && ft_strcmp(cmd[0], "env") == 0)
			print_env(env);
		else if (cmd[0] && ft_strcmp(cmd[0], "setenv") == 0)
			ft_printf("%s\n", "run setenv"); // envp = ft_setenv(&envp, env);
		else if (cmd[0] && ft_strcmp(cmd[0], "unsetenv") == 0)
			ft_printf("%s\n", "run unsetenv"); //envp = ft_unsetenv(&envp, env);
		else if (cmd[0] && ft_strcmp(cmd[0], "cd") == 0)
			ft_printf("%s\n", "run cd"); //ft_cd(env, envp);
		else
			ft_printf("%s\n", "else"); //ft_getcommand(envp, env);
	}

	// ft_printf("%s\n", envp[0]);
	// ft_printf("%s\n", envp[1]);

	// while (get_next_line(0, &str))
	// {
		// ft_printf("%s\n", str);
	// 	free(str);
	// }
	return (0);
}

void	print_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		ft_printf("%s\n", env[i]);
		i++;
	}
}

char	**readinput(void)
{
	char	*command;
	char	**args;
	int		i;

	args = 0;
	get_next_line(0, &command);
	replace(&command);
	args = ft_strsplit(command, 5);
	i = 0;
	while (args && args[i])
	{
		if (args[i][0] == '\'' || args[i][0] == '"')
		{
			args[i] = args[i] + 1;
			if (args[i][ft_strlen(args[i]) - 1] == '\'' ||
					args[i][ft_strlen(args[i]) - 1] == '"')
				args[i][ft_strlen(args[i]) - 1] = 0;
		}
		i++;
	}
	return (args);
}

void	replace(char **line)
{
	int	i;
	int	bet;

	i = 0;
	bet = 0;
	while ((*line)[i] != 0)
	{
		if ((*line)[i] == ' ')
			(*line)[i] = 5;
		if ((*line)[i] == '\'' || (*line)[i] == '"')
			bet = (bet + 1) % 2;
		i++;
	}
}