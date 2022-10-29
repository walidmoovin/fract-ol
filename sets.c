/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbekkal <wbekkal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:27:09 by wbekkal           #+#    #+#             */
/*   Updated: 2022/01/04 12:33:58 by wbekkal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia(t_data *data)
{
	data->y = -1;
	while (++data->y < HEIGHT)
	{
		data->x = -1;
		while (++data->x < WIDTH)
		{
			data->color = 0;
			data->zx = ((data->x - WIDTH / 2) / 1000.0) * data->zoom;
			data->zy = ((data->y - HEIGHT / 2) / 1000.0) * data->zoom;
			data->zx2 = data->zx * data->zx;
			data->zy2 = data->zy * data->zy;
			while ((data->zx2 + data->zy2 < 4) && (data->color < MC))
			{
				data->zx_tmp = (data->zx2 - data->zy2);
				data->zy = (2 * data->zx * data->zy) - data->cy;
				data->zx = data->zx_tmp - data->cx;
				data->zx2 = data->zx * data->zx;
				data->zy2 = data->zy * data->zy;
				data->color++;
			}
			my_pixel_put(data, data->x, data->y, c_color(data));
		}
	}
}

void	mandelbrot(t_data *data)
{
	data->y = -1;
	while (++data->y < HEIGHT)
	{
		data->x = -1;
		while (++data->x < WIDTH)
		{
			data->cx = ((data->x - WIDTH / 2) / 1000.0) * data->zoom;
			data->cy = ((data->y - HEIGHT / 2) / 1000.0) * data->zoom;
			data->color = 0;
			data->zx = 0;
			data->zy = 0;
			data->zx2 = data->zx * data->zx;
			data->zy2 = data->zy * data->zy;
			while ((data->zx2 + data->zy2 < 4) && (data->color < MC))
			{
				data->zx_tmp = data->zx2 - data->zy2 + data->cx;
				data->zy = 2 * data->zx * data->zy + data->cy;
				data->zx = data->zx_tmp;
				data->zx2 = data->zx * data->zx;
				data->zy2 = data->zy * data->zy;
				data->color++;
			}
			my_pixel_put(data, data->x, data->y, c_color(data));
		}
	}
}
