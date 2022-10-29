/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbekkal <wbekkal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 14:32:32 by wbekkal           #+#    #+#             */
/*   Updated: 2022/01/04 12:34:09 by wbekkal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_keyboard(int keycode)
{
	if (keycode == KEY_ECHAP)
		exit (0);
	return (0);
}

int	ft_mouse(int keycode, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (keycode == MOUSE_SCROLL_DOWN)
	{
		data->zoom *= 1.05;
		if (!ft_strncmp(data->win_name, "Julia"))
			julia(data);
		else
			mandelbrot(data);
		mlx_put_image_to_window(data->mlx_id, data->win_id, data->img_id, 0, 0);
	}
	else if (keycode == MOUSE_SCROLL_UP)
	{
		data->zoom /= 1.05;
		if (!ft_strncmp(data->win_name, "Julia"))
			julia(data);
		else
			mandelbrot(data);
		mlx_put_image_to_window(data->mlx_id, data->win_id, data->img_id, 0, 0);
	}
	return (0);
}

int	ft_motion(int x, int y, t_data *data)
{
	data->cx = ((x - WIDTH / 2) / 1000.0) * data->zoom;
	data->cy = ((y - HEIGHT / 2) / 1000.0) * data->zoom;
	julia(data);
	mlx_put_image_to_window(data->mlx_id, data->win_id, data->img_id, 0, 0);
	return (0);
}

int	c_color(t_data *data)
{
	int	r;
	int	g;
	int	b;

	r = ((data->color * 6000) / MC) & 0xFF;
	g = ((data->color * 1500) / MC) & 0xFF;
	b = ((data->color * 2600) / MC) & 0xFF;
	return (rgb(r, g, b));
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		i_name;

	i_name = win_name(argc, argv, &data);
	if (argc >= 2 && (!ft_strncmp(argv[1], "mandelbrot")
			|| !ft_strncmp(argv[1], "julia")) && i_name != 0)
	{
		data_init(&data);
		data.mlx_id = mlx_init();
		data.win_id = mlx_new_window(data.mlx_id, WIDTH, HEIGHT, data.win_name);
		data.img_id = mlx_new_image(data.mlx_id, WIDTH, HEIGHT);
		data.add = mlx_get_data_addr(data.img_id, &data.bpp, &data.sl, &data.e);
		launch_fct(i_name, &data);
		if (i_name == 2)
			mlx_hook(data.win_id, 6, 0, ft_motion, &data);
		mlx_put_image_to_window(data.mlx_id, data.win_id, data.img_id, 0, 0);
		mlx_key_hook(data.win_id, ft_keyboard, &data);
		mlx_mouse_hook(data.win_id, ft_mouse, &data);
		mlx_loop(data.mlx_id);
	}
	else
		print_arg_error();
	return (0);
}
