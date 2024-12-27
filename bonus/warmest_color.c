/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   warmest_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-gady <ael-gady@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 20:40:31 by ael-gady          #+#    #+#             */
/*   Updated: 2024/12/27 20:40:53 by ael-gady         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	put_color(t_my_fractol *f, int x, int y, int nbr_iter)
{
	int	colors[3];

	colors[0] = 0xFF0000;
	colors[1] = 0x00FF00;
	colors[2] = 0x0000FF;
	if (f->nbr_iter == 0)
		f->img.color = 0x000000;
	else
		f->img.color = nbr_iter * 10000 * \
			colors[nbr_iter % (sizeof(colors) / sizeof(colors[0]))];
	put_postition_pixel(f, x, y, f->img.color);
}

void	put_postition_pixel(t_my_fractol *f, int x, int y, int color)
{
	int	pixel_address;

	pixel_address = 0;
	if (!f || !f->img.pixel_data)
	{
		perror("Invalid fractol or invalid image data address\n");
		exit(1);
	}
	if (pixel_address > WIDTH * HEIGHT * (f->img.bits_per_pixel / 8))
	{
		perror("Invalid image offset\n");
		exit(1);
	}
	pixel_address = (y * f->img.line_length) + (x * (f->img.bits_per_pixel / 8));
	*(unsigned int *)(pixel_address + f->img.pixel_data) = color;
}