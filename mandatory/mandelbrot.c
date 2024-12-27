/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-gady <ael-gady@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 23:05:33 by ael-gady          #+#    #+#             */
/*   Updated: 2024/12/27 10:49:27 by ael-gady         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	handle_data_pixel_mand(t_my_fractol *f, int x, int y)
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
		z = sum_complex(pow2_complex(z), f->c_mendel);
		if ((z.real * z.real) + (z.im * z.img) > 4)
		{
			put_color(f, x, y, f->nbr_iter);
			return ;
		}
		f->nbr_iter++;
	}
	put_postition_pixel(f, x, y, BLACK_COLOR);
}

void	create_fract_mandelbrot(t_my_fractol *f)
{
	int x;
	int y;
	
	y = -1;
	setup_zoom(f);
	while (++y < WIDTH)
	{
		x = -1;
		while (++x < HEIGHT)
		{
			handle_data_pixel_mand(f, x, y);
		}
	}
	mlx_put_image_to_window(f->mlx_ptr, f->mlx_win, f->img.img_ptr, 0, 0);
}
