/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:09:31 by ktintim-          #+#    #+#             */
/*   Updated: 2025/01/27 13:55:20 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minesweeper.h"

void	print_error(char *error, t_data *data)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(error, 2);
	ft_putstr_fd("\n", 2);
	free_all(data);
	exit (1);
}

static void	free_texture(t_data *data)
{
	t_texture	*texture;

	texture = data->texture;
	mlx_destroy_image(data->mlx, texture->tile1);
	mlx_destroy_image(data->mlx, texture->tile2);
	mlx_destroy_image(data->mlx, texture->tile3);
	mlx_destroy_image(data->mlx, texture->tile4);
	mlx_destroy_image(data->mlx, texture->tile5);
	mlx_destroy_image(data->mlx, texture->tile6);
	mlx_destroy_image(data->mlx, texture->tile7);
	mlx_destroy_image(data->mlx, texture->tile8);
	mlx_destroy_image(data->mlx, texture->mine);
	mlx_destroy_image(data->mlx, texture->exploded);
	mlx_destroy_image(data->mlx, texture->flag);
	mlx_destroy_image(data->mlx, texture->face);
	mlx_destroy_image(data->mlx, texture->empty);
	free(texture);
}

void	free_all(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->rows)
	{
		free(data->map[i]);
		free(data->visible[i]);
		i++;
	}
	free(data->map);
	free(data->visible);
	free_texture(data);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
}

int	close_window(t_data *data)
{
	free_all(data);
	exit(0);
}
