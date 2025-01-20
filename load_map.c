/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 14:36:13 by ktintim-          #+#    #+#             */
/*   Updated: 2025/01/20 16:16:35 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minesweeper.h"

static void	place_mines(t_data *data)
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

static void	nbrs(t_data *data, int i, int j)
{
	if (i > 0 && j > 0 && data->map[i - 1][j - 1] == -1)
		data->map[i][j]++;
	if (i > 0 && data->map[i - 1][j] == -1)
		data->map[i][j]++;
	if (i > 0 && j < data->cols - 1 && \
			data->map[i - 1][j + 1] == -1)
		data->map[i][j]++;
	if (j > 0 && data->map[i][j - 1] == -1)
		data->map[i][j]++;
	if (j < data->cols - 1 && data->map[i][j + 1] == -1)
		data->map[i][j]++;
	if (i < data->rows - 1 && j > 0 && \
			data->map[i + 1][j - 1] == -1)
		data->map[i][j]++;
	if (i < data->rows - 1 && data->map[i + 1][j] == -1)
		data->map[i][j]++;
	if (i < data->rows - 1 && j < data->cols - 1 \
			&& data->map[i + 1][j + 1] == -1)
		data->map[i][j]++;
}

static void	place_nbrs(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->rows)
	{
		j = 0;
		while (j < data->cols)
		{
			if (data->map[i][j] != -1)
			{
				data->map[i][j] = 0;
				nbrs(data, i, j);
			}
			j++;
		}
		i++;
	}
}

static void	place_empty(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->rows)
	{
		j = 0;
		while (j < data->cols)
		{
			if (data->map[i][j] != -1)
				data->map[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	load_map(t_data *data)
{
	place_empty(data);
	place_mines(data);
	place_nbrs(data);
}