/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilian <kilian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:19:58 by ktintim-          #+#    #+#             */
/*   Updated: 2025/01/23 11:13:00 by kilian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minesweeper.h"

static void	p_nbrs(t_data *data, int i, int j)
{
	if (data->map[i][j] == 1 && data->visible[i][j] == 1)
		mlx_put_image_to_window(data->mlx, data->win, \
			data->texture->tile1, j * 64, i * 64);
	else if (data->map[i][j] == 2 && data->visible[i][j] == 1)
		mlx_put_image_to_window(data->mlx, data->win, \
				data->texture->tile2, j * 64, i * 64);
	else if (data->map[i][j] == 3 && data->visible[i][j] == 1)
		mlx_put_image_to_window(data->mlx, data->win, \
				data->texture->tile3, j * 64, i * 64);
	else if (data->map[i][j] == 4 && data->visible[i][j] == 1)
		mlx_put_image_to_window(data->mlx, data->win, \
				data->texture->tile4, j * 64, i * 64);
	else if (data->map[i][j] == 5 && data->visible[i][j] == 1)
		mlx_put_image_to_window(data->mlx, data->win, \
				data->texture->tile5, j * 64, i * 64);
	else if (data->map[i][j] == 6 && data->visible[i][j] == 1)
		mlx_put_image_to_window(data->mlx, data->win, \
				data->texture->tile6, j * 64, i * 64);
	else if (data->map[i][j] == 7 && data->visible[i][j] == 1)
		mlx_put_image_to_window(data->mlx, data->win, \
				data->texture->tile7, j * 64, i * 64);
	else if (data->map[i][j] == 8 && data->visible[i][j] == 1)
		mlx_put_image_to_window(data->mlx, data->win, \
				data->texture->tile8, j * 64, i * 64);
}

static void	print_empty(t_data *data, int i, int j)
{
	mlx_put_image_to_window(data->mlx, data->win, \
			data->texture->empty, j * 64, i * 64);
}

static void	print_exploded(t_data *data, int i, int j)
{
	mlx_put_image_to_window(data->mlx, data->win, \
			data->texture->exploded, j * 64, i * 64);
}

static void	print_tiles(t_data *data, int i, int j)
{
	if (data->map[i][j] == 0 && data->visible[i][j] == 1)
		print_empty(data, i, j);
	else if (data->map[i][j] != -1 && data->visible[i][j] == 1)
		p_nbrs(data, i, j);
	else if (data->lose && data->visible[i][j] == 1)
		print_exploded(data, i, j);
}

void	print_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->rows)
	{
		j = 0;
		while (j < data->cols)
		{
			if (data->visible[i][j] == 0)
				mlx_put_image_to_window(data->mlx, data->win, \
						data->texture->face, j * 64, i * 64);
			else if (data->visible[i][j] == 2)
				mlx_put_image_to_window(data->mlx, data->win, \
						data->texture->flag, j * 64, i * 64);
			else
			{
				print_tiles(data, i, j);
			}
			j++;
		}
		i++;
	}
}
