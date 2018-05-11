/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 16:29:15 by azinnatu          #+#    #+#             */
/*   Updated: 2018/05/10 18:20:22 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern char	**environ;

void	process_args(char **cmd, char **env, char *temp)
{
	while (1)
	{
		ft_putstr_fd(GRN"m_sh$> "NRM, 1);
		cmd = read_input();
		if (cmd[0] && ft_strcmp(cmd[0], "exit") == 0)
		{
			ft_printf("%s\n", "exit");
			exit(0);
		}
		else if (cmd[0] && ft_strcmp(cmd[0], "cd") == 0)
			ft_cd(cmd, env, temp);
		else if (cmd[0] && ft_strcmp(cmd[0], "env") == 0)
			ft_env(cmd, env, 0, -1);
		else if (cmd[0] && ft_strcmp(cmd[0], "setenv") == 0)
			env = ft_setenv(cmd, env);
		else if (cmd[0] && ft_strcmp(cmd[0], "unsetenv") == 0)
			env = ft_unsetenv(cmd, env);
		else if (cmd[0] && ft_strcmp(cmd[0], "echo") == 0)
			ft_echo(cmd, env);
		else
			ft_cmd(cmd, env);
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
			if (args[i][ft_strlen(args[i]) - 1] == '\'' ||
					args[i][ft_strlen(args[i]) - 1] == '"')
			{
				args[i] = ft_strcpy(args[i], &args[i][1]);
				args[i][ft_strlen(args[i]) - 1] = 0;
			}
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
		i++;
	}
}

int		main(int ac, char **av, char **envp)
{
	char	**cmd;
	char	**env;
	char	*temp;

	cmd = NULL;
	temp = (char*)ft_memalloc(PATH_MAX + 1);
	(void)ac;
	(void)av;
	create_env(&env, envp);
	process_args(cmd, env, temp);
	free_env(env);
	free(temp);
	return (0);
}
