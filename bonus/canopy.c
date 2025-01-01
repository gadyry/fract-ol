/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canopy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-gady <ael-gady@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 20:20:00 by ael-gady          #+#    #+#             */
/*   Updated: 2025/01/01 17:50:11 by ael-gady         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void draw_line(t_my_fractol *f, int x1, int y1, int x2, int y2, int color)
{
	int dx = abs(x2 - x1);
	int dy = abs(y2 - y1);
	int sx = (x1 < x2) ? 1 : -1;
	int sy = (y1 < y2) ? 1 : -1;
	int err = dx - dy;

	while (1)
	{
		put_postition_pixel(f, x1, y1, color);
		if (x1 == x2 && y1 == y2)
			break;
		int e2 = 2 * err;
		if (e2 > -dy)
		{
			err -= dy;
			x1 += sx;
		}
		if (e2 < dx)
		{
			err += dx;
			y1 += sy;
		}
	}
}

void draw_canopy(t_my_fractol *f, int x1, int y1, double length, double angle, int depth)
{
	if (depth == 0)
		return;

	int x2 = x1 + (int)(cos(angle) * length);
	int y2 = y1 - (int)(sin(angle) * length);

	draw_line(f, x1, y1, x2, y2, 0x00ff00);//0xB0FFF4

	draw_canopy(f, x2, y2, length * 0.7, angle - M_PI / 8, depth - 1);
	draw_canopy(f, x2, y2, length * 0.7, angle + M_PI / 8, depth - 1);
}

void create_fract_canopy(t_my_fractol *f)
{
	int x_start = WIDTH / 2;
	int y_start = HEIGHT - 100;
	double initial_length = 150;
	double initial_angle =  M_PI / 2;
	int max_depth = 20;

	draw_canopy(f, x_start, y_start, initial_length, initial_angle, max_depth);
	mlx_put_image_to_window(f->mlx_ptr, f->mlx_win, f->img.img_ptr, 0, 0);
}
