/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minesweeper.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktintim- <ktintim-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:31:03 by ktintim-          #+#    #+#             */
/*   Updated: 2025/01/17 19:47:39 by ktintim-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINESWEEPER_H
# define MINESWEEPER_H

# include "minilibx-linux/mlx.h"
# include "Libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <time.h>

typedef struct s_texture
{
	void	*tile1;
	void	*tile2;
	void	*tile3;
	void	*tile4;
	void	*tile5;
	void	*tile6;
	void	*tile7;
	void	*tile8;
	void	*mine;
	void	*exploded;
	void	*flag;
	void	*face;
}				t_texture;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	int			rows;
	int			cols;
	int			mines;
	int			**map;
	t_texture	*texture;
}				t_data;

// arg.c
int		arg_check(int argc, char **argv);

// exit.c
void	free_all(t_data *data);
void	print_error(char *error, t_data *data);
int		close_window(t_data *data);

// load_sprite.c
void	load_texture(t_data *data);

// map.c
void	place_mines(t_data *data);
void	print_map(t_data *data);
void	print_mines(t_data *data);

#endif
