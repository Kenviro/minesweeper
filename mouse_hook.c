/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 15:09:11 by ktintim-          #+#    #+#             */
/*   Updated: 2025/01/20 16:31:43 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minesweeper.h"

static void	set_visible(int i, int j, t_data *data)
{
	if (i < 0 || i >= data->rows || j < 0 || j >= data->cols)
		return ;
	if (data->lose == 1)
		return ;
	if (data->visible[i][j] == 1 || data->map[i][j] == -1)
		return ;
	data->visible[i][j] = 1;
	if (data->map[i][j] != 0)
		return ;
	set_visible(i - 1, j - 1, data);
	set_visible(i - 1, j, data);
	set_visible(i - 1, j + 1, data);
	set_visible(i, j - 1, data);
	set_visible(i, j + 1, data);
	set_visible(i + 1, j - 1, data);
	set_visible(i + 1, j, data);
	set_visible(i + 1, j + 1, data);
}

static void	left_click(int x, int y, t_data *data)
{
	int	i;
	int	j;

	i = y / 64;
	j = x / 64;
	if (data->lose == 1 || data->flag == data->mines || \
				data->visible[i][j] == 2)
		return ;
	if (data->map[i][j] == -1)
	{
		data->visible[i][j] = 1;
		data->lose = 1;
		mlx_put_image_to_window(data->mlx, data->win, \
				data->texture->exploded, j * 64, i * 64);
		print_map(data);
		lost(data);
	}
	else
		set_visible(i, j, data);
}

static void	right_click(int x, int y, t_data *data)
{
	int	i;
	int	j;

	i = y / 64;
	j = x / 64;
	if (data->visible[i][j] == 0)
		data->visible[i][j] = 2;
	else if (data->visible[i][j] == 2)
		data->visible[i][j] = 0;
	if (data->map[i][j] == -1)
		data->flag++;
	if (data->flag == data->mines)
		win(data);
}

int	mouse_hook(int button, int x, int y, t_data *data)
{
	static int	refresh = 0;

	if (button == 1)
	{
		if (mlx_mouse_get_pos(data->mlx, data->win, &x, &y) == 0)
			print_error("Failed to get mouse position", data);
		left_click(x, y, data);
		print_map(data);
	}
	else if (button == 3 && data->flag < data->mines && data->lose == 0)
	{
		if (mlx_mouse_get_pos(data->mlx, data->win, &x, &y) == 0)
			print_error("Failed to get mouse position", data);
		right_click(x, y, data);
		if (refresh == 5)
		{
			mlx_clear_window(data->mlx, data->win);
			refresh = 0;
		}
		else
			refresh++;
		print_map(data);
	}
	return (0);
}
