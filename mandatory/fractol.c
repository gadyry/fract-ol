/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-gady <ael-gady@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 23:05:33 by ael-gady          #+#    #+#             */
/*   Updated: 2024/12/23 06:07:09 by ael-gady         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	handle_data_pixel(t_my_fractol *f, int x, int y)
{
	t_complex_nbr	z;
	t_complex_nbr	c;

	z.real = 0.0;
	z.img = 0.0;
	c.real = map_pixel_to_coordinate(x, -2, +2, WIDTH);
	c.img = map_pixel_to_coordinate(y, +2, -2, HEIGHT);
	f->nbr_iter = 0;
	while (f->nbr_iter < MAX_ITER)
	{
		z = sum_complex(pow2_complex(z). c);
		if (z.real * z)
		{
			put_color();//TODO
			return ;
		}
	}
}

void	create_fractol(t_my_fractol *f)
{
	int x;
	int y;
	
	y = -1;
	while (++y < WIDTH)
	{
		x = -1;
		while (++x < HEIGHT)
		{
			handle_data_pixel(f, x, y);
		}
	}
	mlx_put_image_to_window(f, 0, 0);
}
