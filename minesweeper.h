/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minesweeper.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kilian <kilian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:31:03 by ktintim-          #+#    #+#             */
/*   Updated: 2025/01/23 11:16:57 by kilian           ###   ########.fr       */
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
	void	*empty;
}				t_texture;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	int			rows;
	int			cols;
	int			mines;
	int			lose;
	int			flag;
	int			first_click;
	int			**map;
	int			**visible;
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
void	print_map(t_data *data);

// load_map.c
void	load_map(t_data *data, int i, int j);

// key_hook.c
int		key_hook(int keycode, t_data *data);
void	win(t_data *data);
void	lost(t_data *data);

// mouse_hook.c
int		mouse_hook(int button, int x, int y, t_data *data);

#endif
