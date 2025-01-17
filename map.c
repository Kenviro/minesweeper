/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 18:19:58 by ktintim-          #+#    #+#             */
/*   Updated: 2025/01/17 19:47:22 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minesweeper.h"

void	place_mines(t_data *data)
{
	int	placed_mines;
	int	random_cols;
	int	random_rows;

	placed_mines = 0;
	srand(time(NULL));
	while (placed_mines < data->mines)
	{
		random_rows = rand() % data->rows;
		random_cols = rand() % data->cols;
		if (data->map[random_rows][random_cols] != -1)
		{
			data->map[random_rows][random_cols] = -1;
			placed_mines++;
		}
	}
}

void	print_map(t_data *data)
{
	print_mines(data);
}
