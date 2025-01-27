/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bot_action.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 15:09:11 by ktintim-          #+#    #+#             */
/*   Updated: 2025/01/27 14:36:34 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bot.h"

static void	set_visible(int i, int j, t_data *data)
{
	if (i < 0 || i >= data->rows || j < 0 || j >= data->cols)
		return ;
	if (data->lose == 1)
		return ;
	if (data->visible[i][j] == 1 || data->map[i][j] == -1)
		return ;
	data->visible[i][j] = 1;
	data->empty_left--;
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

void	left_click(int j, int i, t_data *data)
{
	if (data->first_click == 0)
	{
		data->first_click = 1;
		load_map(data, i, j);
	}
	if (data->lose == 1 || data->visible[i][j] == 2)
		return ;
	if (data->map[i][j] == -1)
	{
		data->visible[i][j] = 1;
		mlx_put_image_to_window(data->mlx, data->win, \
				data->texture->exploded, j * 64, i * 64);
		print_map(data);
		lost(data);
	}
	else
		set_visible(i, j, data);
}

void	right_click(int j, int i, t_data *data)
{
	if (data->visible[i][j] == 0)
	{
		data->visible[i][j] = 2;
		if (data->map[i][j] == -1)
			data->flag++;
	}
	else if (data->visible[i][j] == 2)
	{
		data->visible[i][j] = 0;
		if (data->map[i][j] == -1)
			data->flag--;
	}
}

