/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:22:30 by ktintim-          #+#    #+#             */
/*   Updated: 2025/01/17 18:06:31 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minesweeper.h"

static void	load_tile2(t_texture *texture, void *mlx, t_data *data)
{
	texture->tile7 = mlx_xpm_file_to_image(mlx, "Tiles/Tile7.xpm", \
			&(int){0}, &(int){0});
	if (!texture->tile7)
		print_error("Failed to load tile7 texture", data);
	texture->tile8 = mlx_xpm_file_to_image(mlx, "Tiles/Tile8.xpm", \
			&(int){0}, &(int){0});
	if (!texture->tile8)
		print_error("Failed to load tile8 texture", data);
}

static void	load_tile(t_texture *texture, void *mlx, t_data *data)
{
	texture->tile1 = mlx_xpm_file_to_image(mlx, "Tiles/Tile1.xpm", \
			&(int){0}, &(int){0});
	if (!texture->tile1)
		print_error("Failed to load tile1 texture", data);
	texture->tile2 = mlx_xpm_file_to_image(mlx, "Tiles/Tile2.xpm", \
			&(int){0}, &(int){0});
	if (!texture->tile2)
		print_error("Failed to load tile2 texture", data);
	texture->tile3 = mlx_xpm_file_to_image(mlx, "Tiles/Tile3.xpm", \
			&(int){0}, &(int){0});
	if (!texture->tile3)
		print_error("Failed to load tile3 texture", data);
	texture->tile4 = mlx_xpm_file_to_image(mlx, "Tiles/Tile4.xpm", \
			&(int){0}, &(int){0});
	if (!texture->tile4)
		print_error("Failed to load tile4 texture", data);
	texture->tile5 = mlx_xpm_file_to_image(mlx, "Tiles/Tile5.xpm", \
			&(int){0}, &(int){0});
	if (!texture->tile5)
		print_error("Failed to load tile5 texture", data);
	texture->tile6 = mlx_xpm_file_to_image(mlx, "Tiles/Tile6.xpm", \
			&(int){0}, &(int){0});
	if (!texture->tile6)
		print_error("Failed to load tile6 texture", data);
	load_tile2(texture, mlx, data);
}

static void	load_mine(t_texture *texture, void *mlx, t_data *data)
{
	texture->mine = mlx_xpm_file_to_image(mlx, "Tiles/TileMine.xpm", \
			&(int){0}, &(int){0});
	if (!texture->mine)
		print_error("Failed to load mine texture", data);
	texture->exploded = mlx_xpm_file_to_image(mlx, "Tiles/TileExploded.xpm", \
			&(int){0}, &(int){0});
	if (!texture->exploded)
		print_error("Failed to load exploded texture", data);
	texture->flag = mlx_xpm_file_to_image(mlx, "Tiles/TileFlag.xpm", \
			&(int){0}, &(int){0});
	if (!texture->flag)
		print_error("Failed to load flag texture", data);
	texture->face = mlx_xpm_file_to_image(mlx, "Tiles/TileUnknown.xpm", \
			&(int){0}, &(int){0});
	if (!texture->face)
		print_error("Failed to load face texture", data);
}

void	load_texture(t_data *data)
{
	load_tile(data->texture, data->mlx, data);
	load_mine(data->texture, data->mlx, data);
}
