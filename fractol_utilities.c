/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utilities.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbekkal <wbekkal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 14:32:41 by wbekkal           #+#    #+#             */
/*   Updated: 2022/01/04 12:34:03 by wbekkal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int	ft_strncmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	my_pixel_put(t_data *data, int r, int i, int color)
{
	char	*dst;

	dst = data->add + (i * data->sl + r * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

void	print_arg_error(void)
{
	printf("invalid argument(s), please retry with a valid entry||\n");
	printf("Available parameters are :\nName of the set you want to display.\n");
}

void	data_init(t_data *data)
{
	data->zoom = 8.0;
	data->y = 0;
	data->x = 0;
	data->color = 0;
	data->bpp = 0;
	data->sl = 0;
	data->e = 0;
}
