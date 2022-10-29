/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbekkal <wbekkal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 14:18:47 by wbekkal           #+#    #+#             */
/*   Updated: 2022/01/04 12:34:00 by wbekkal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define HEIGHT 800
# define WIDTH 800
# define MC 100

# ifdef __linux__
#  define KEY_ARROW_UP 65362
#  define KEY_ARROW_DOWN 65364
#  define KEY_ECHAP 65307
# elif __APPLE__
#  define MOUSE_SCROLL_UP 4
#  define MOUSE_SCROLL_DOWN 5
#  define KEY_ECHAP 53
# endif

# include "mlx.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct data_struct{
	void	*mlx_id;
	void	*win_id;
	void	*img_id;
	char	*win_name;
	int		x;
	int		y;
	float	zoom;
	int		color;
	float	zx;
	float	zx_tmp;
	float	zy;
	float	cx;
	float	cy;
	int		bpp;
	int		sl;
	int		e;
	char	*add;
	int		pixel_dest;
	float	zx2;
	float	zy2;
}	t_data;

void		julia(t_data *data);
void		mandelbrot(t_data *data);
void		my_pixel_put(t_data *data, int x, int y, int color);
int			ft_strncmp(char *s1, char *s2);
int			rgb(int r, int g, int b);
void		print_arg_error(void);
void		data_init(t_data *data);
void		mandelbrot(t_data *data);
void		julia(t_data *data);
int			win_name(int argc, char **argv, t_data *data);
int			c_color(t_data *data);
void		launch_fct(int i_name, t_data *data);

#endif