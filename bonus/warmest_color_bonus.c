/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   warmest_color_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-gady <ael-gady@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 20:40:31 by ael-gady          #+#    #+#             */
/*   Updated: 2024/12/29 17:14:58 by ael-gady         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	put_color(t_my_fractol *f, int x, int y, int nbr_iter)
{
	int	colors[3];

	if (f->nbr_iter == 0)
		f->img.color = 0x000000;
	else
	{
		colors[0] = (int)(nbr_iter * f->col1) % 256;
		colors[1] = (int)(nbr_iter * f->col2) % 256;
		colors[2] = (int)(nbr_iter * f->col2) % 256;
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
