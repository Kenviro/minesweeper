/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 14:53:42 by ktintim-          #+#    #+#             */
/*   Updated: 2025/01/20 16:11:44 by ktintim-         ###   ########.fr       */
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
	if (keycode == 65307)
	{
		free_all(data);
		exit(0);
	}
	return (0);
}
