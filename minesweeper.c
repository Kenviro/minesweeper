/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minesweeper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:50:14 by ktintim-          #+#    #+#             */
/*   Updated: 2025/01/17 19:47:09 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minesweeper.h"

static void	init(t_data *data, char **argv)
{
	int	i;

	i = 0;
	data->rows = ft_atoi(argv[1]);
	data->cols = ft_atoi(argv[2]);
	data->mines = ft_atoi(argv[3]);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, \
		data->rows * 64, data->cols * 64, "Minesweeper");
	data->texture = (t_texture *)malloc(sizeof(t_texture));
	if (!data->texture)
		print_error("Failed to allocate memory for texture", data);
	data->map = (int **)malloc(sizeof(int *) * data->rows);
	if(!data->map)
		print_error("Failed to allocate memory for map", data);
	while (i < data->rows)
	{
		data->map[i] = (int *)malloc(sizeof(int) * data->cols);
		if (!data->map[i])
			print_error("Failed to allocate memory for map", data);
		ft_bzero(data->map[i], sizeof(int) * data->cols);
		i++;
	}
	load_texture(data);
}

int	main(int argc, char **argv)
{
	t_data	data;

	ft_bzero(&data, sizeof(t_data));
	if (arg_check(argc, argv) == 0)
		return (0);
	init(&data, argv);
	mlx_hook(data.win, 17, 0, close_window, &data);
	place_mines(&data);
	print_map(&data);
	mlx_loop(data.mlx);
	return (0);
}
