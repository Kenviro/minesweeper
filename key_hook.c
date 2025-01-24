/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 14:53:42 by ktintim-          #+#    #+#             */
/*   Updated: 2025/01/24 17:00:38 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minesweeper.h"

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

int	key_hook(int keycode, t_data *data)
{
	int	i;

	i = 0;
	if (keycode == 65307)
	{
		free_all(data);
		exit(0);
	}
	if (keycode == 114)
	{
		while (i < data->rows)
		{
			ft_bzero(data->map[i], sizeof(int) * data->cols);
			ft_bzero(data->visible[i], sizeof(int) * data->cols);
			i++;
		}
		data->lose = 0;
		data->first_click = 0;
		data->flag = 0;
		print_map(data);
	}
	return (0);
}
