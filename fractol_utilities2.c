/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utilities2.C                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbekkal <wbekkal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:12:36 by wbekkal           #+#    #+#             */
/*   Updated: 2022/01/04 12:33:53 by wbekkal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	win_name(int argc, char **argv, t_data *data)
{
	if (argc >= 2)
	{
		if (!ft_strncmp(argv[1], "mandelbrot"))
		{
			data->win_name = "Mandelbrot";
			return (1);
		}
		if (!ft_strncmp(argv[1], "julia"))
		{
			data->win_name = "Julia";
			return (2);
		}
	}
	return (0);
}

void	launch_fct(int i_name, t_data *data)
{
	if (i_name == 1)
		mandelbrot(data);
	else
		julia(data);
}
