/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-gady <ael-gady@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 20:39:16 by ael-gady          #+#    #+#             */
/*   Updated: 2024/12/29 09:56:57 by ael-gady         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	handle_data_pixel_mand(t_my_fractol *f, int x, int y)
{
	t_complex_nbr	z;
	t_complex_nbr	c;

	z.real = 0.0;
	z.img = 0.0;
	f->nbr_iter = 0;
	c.real = map_pixel_to_coordinate(x, f->x_start, f->x_end, WIDTH) + f->move_x;
	c.img = map_pixel_to_coordinate(y, f->y_start, f->y_end, HEIGHT) + f->move_y;
	while (f->nbr_iter < MAX_ITER)
	{
		z = sum_complex(pow2_complex(z), c);
		if ((z.real * z.real) + (z.img * z.img) > 4)
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

	y = 0;
	while (y < WIDTH)
	{
		x = 0;
		while (x < HEIGHT)
		{
			handle_data_pixel_mand(f, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx_ptr, f->mlx_win, f->img.img_ptr, 0, 0);
}