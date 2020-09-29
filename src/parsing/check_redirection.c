/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmbabazi <nmbabazi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 17:37:49 by nmbabazi          #+#    #+#             */
/*   Updated: 2020/09/29 11:48:54 by nmbabazi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int		checksorti(char *line)
{
	int i;
	int cnt;

	i = 0;
	cnt = 0;
	while (line[i])
	{
		if (line[i] == '>')
		{
			cnt = 0;
			while (line[i] == '>')
			{
				i++;
				cnt++;
			}
			while (line[i] == ' ')
				i++;
			if (cnt > 2 || ft_isalnum(line[i]) == 0)
				return (0);
		}
		i++;
	}
	return (1);
}

int		checkentre(char *line)
{
	int i;
	int cnt;

	i = 0;
	cnt = 0;
	while (line[i])
	{
		if (line[i] == '<')
		{
			cnt = 0;
			while (line[i] == '<')
			{
				i++;
				cnt++;
			}
			while (line[i] == ' ')
				i++;
			if (cnt > 1 || ft_isalnum(line[i]) == 0)
				return (0);
		}
		i++;
	}
	return (1);
}

int		ft_isredirected(char **cmd)
{
	int i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i][0] == '>' || cmd[i][0] == '<')
			return (1);
		i++;
	}
	return (0);
}

void	ft_dell_backslash(char **cmd)
{
	int i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i][0] == '\\' && (cmd[i][1] == '>' || cmd[i][1] == '<'))
			cmd[i][0] = 127;
		i++;
	}
}