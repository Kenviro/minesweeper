/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 14:53:42 by ktintim-          #+#    #+#             */
/*   Updated: 2025/01/27 15:05:46 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bot.h"

void	win(t_data *data)
{
	printf("YOU WON, CONGRATULATIONS\n");
	data->lose = 1;
}

void	lost(t_data *data)
{
	printf("YOU LOST, LOSER\n");
	data->lose = 1;
}

static void	restart(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->rows)
	{
		ft_bzero(data->map[i], sizeof(int) * data->cols);
		ft_bzero(data->visible[i], sizeof(int) * data->cols);
		i++;
	}
	data->lose = 0;
	data->first_click = 0;
	data->flag = 0;
	data->empty_left = data->rows * data->cols - data->mines;
	mlx_clear_window(data->mlx, data->win);
	print_map(data);
}

static void	print_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->rows)
	{
		j = 0;
		while (j < data->cols)
		{
			printf("[");
			printf("%d ", data->visible[i][j]);
			printf("]");
			j++;
		}
		i++;
	}
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 65307)
	{
		free_all(data);
		exit(0);
	}
	if (keycode == 114)
		restart(data);
	if (keycode == 112)
		print_map(data);
	return (0);
}
