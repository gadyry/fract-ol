/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   warmest_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-gady <ael-gady@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 08:13:57 by ael-gady          #+#    #+#             */
/*   Updated: 2024/12/30 09:27:31 by ael-gady         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	setup_zoom(t_my_fractol *f)
{
	f->x_start *= f->zoom;
	f->x_end *= f->zoom;
	f->y_start *= f->zoom;
	f->y_end *= f->zoom;
}

void	put_color(t_my_fractol *f, int x, int y, int nbr_iter)
{
	int	colors[3];

	if (f->nbr_iter == 0)
		f->img.color = 0x000000;
	else
	{
		colors[0] = (nbr_iter * 5) % 256;
		colors[1] = (nbr_iter * 3) % 256;
		colors[2] = (nbr_iter * 11) % 256;
		f->img.color = (colors[0] << 16) | (colors[1] << 8) | (colors[2]);
	}
	put_postition_pixel(f, x, y, f->img.color);
}

void	put_postition_pixel(t_my_fractol *f, int x, int y, int color)
{
	int	pixel_add;

	pixel_add = (y * f->img.line_length) + (x * (f->img.bits_per_pixel / 8));
	*(unsigned int *)(pixel_add + f->img.pixel_data) = color;
}
