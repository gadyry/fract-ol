/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-gady <ael-gady@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 23:05:33 by ael-gady          #+#    #+#             */
/*   Updated: 2024/12/25 12:21:08 by ael-gady         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_color(t_my_fractol *f, int x, int y, int nbr_iter)
{
	int	colors[3];

	colors[0] = 0xFF0000;// RED
	colors[1] = 0x00FF00;// GREEN
	colors[2] = 0x0000FF;// BLUE is the warmest color !
	if (f->nbr_iter == 0)
		f->img.color = 0x000000;// BLACK
	else
		f->img.color = nbr_iter * 10000 * \
			colors[iter % (sizeof(colors) / sizeof(colors[0]))];
	put_postition_pixel(f, x, y, f->img.color);
}

void	put_postition_pixel(t_my_fractol *f, int x, int y, int color)
{
	char	*pixel_address;

	if (!f || !f->img.pixel_data)
	{
		perror("Invalid fractol or invalid image data address\n");
		exit(1);
	}
	if (pixel_address > WIDTH * HEIGHT * (frc->img.bit_p_pxl / 8))
	{
		perror("Invalid image offset\n");
		exit(1);
	}
	pixel_address = (y * f->img.line_length) + (x * (f->img.bits_per_pixel / 8));
	*(unsigned int *)(pixel_address + f->img.pixel_data) = color;
}

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
		if ((z.real * z.real) + (z.im * z.img) > 4 )
		{
			put_color(f, x, y, f->nbr_iter);
			return ;
		}
		f->nbr_iter++;
	}
	put_postition_pixel(f, x, y, BLACK_COLOR);
}

void	create_fractol(t_my_fractol *f)
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
			handle_data_pixel(f, x, y);
		}
	}
	mlx_put_image_to_window(f, 0, 0);
}
