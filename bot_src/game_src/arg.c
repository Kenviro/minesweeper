/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:55:47 by ktintim-          #+#    #+#             */
/*   Updated: 2025/01/17 19:38:15 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minesweeper.h"

static int	ft_is_arg_digit(char **argv)
{
	int	i;
	int	arg;

	arg = 1;
	while (arg < 4)
	{
		i = 0;
		while (i < ft_strlen(argv[arg]))
		{
			if ((argv[arg][0] == '-' || argv[arg][0] == '+') && i == 0)
				i++;
			else if (argv[arg][i] >= '0' && argv[arg][i] <= '9')
				i++;
			else
				return (0);
		}
		arg++;
	}
	return (1);
}

static int	is_positive(char **argv)
{
	int	arg;

	arg = 1;
	while (arg < 4)
	{
		if (ft_atoi(argv[arg]) <= 0)
			return (0);
		arg++;
	}
	return (1);
}

static int	nb_mine(int rows, int cols, int mines)
{
	int	total_cells;
	int	mines_max;

	total_cells = rows * cols;
	mines_max = (int)(0.35 * total_cells);
	if (mines >= mines_max)
		return (0);
	return (1);
}

int	arg_check(int argc, char **argv)
{
	if (argc != 4)
	{
		ft_putstr_fd("Error: Invalid number of arguments\n", 2);
		return (0);
	}
	if (ft_is_arg_digit(argv) == 0)
	{
		ft_putstr_fd("Error: Invalid argument\n", 2);
		return (0);
	}
	if (is_positive(argv) == 0)
	{
		ft_putstr_fd("Error: negative and zero excluded\n", 2);
		return (0);
	}
	if (nb_mine(ft_atoi(argv[1]), ft_atoi(argv[2]), ft_atoi(argv[3])) == 0)
	{
		ft_putstr_fd("Error: Too many mines\n", 2);
		return (0);
	}
	return (1);
}
