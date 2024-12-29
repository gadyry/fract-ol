/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-gady <ael-gady@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 20:47:29 by ael-gady          #+#    #+#             */
/*   Updated: 2024/12/29 09:57:51 by ael-gady         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static int _close(t_my_fractol *f)
{
	mlx_destroy_image(f->mlx_ptr, f->img.img_ptr);
	mlx_destroy_window(f->mlx_ptr, f->mlx_win);
	free(f->mlx_ptr);
	exit(0);
	return (0);
}

static int	_event(int keycode, t_my_fractol *f)
{
	if (keycode == 53)
		_close(f);
	else if (keycode == 123)
		f->move_x -= 0.1 * f->zoom;
	else if (keycode == 124)
		f->move_x += 0.1 * f->zoom;
	else if (keycode == 125)
		f->move_y -= 0.1 * f->zoom;
	else if (keycode == 126)
		f->move_y += 0.1 * f->zoom;
	// else if (keycode == 49)
	// {
		 /* pass function change the color of my fractal ! */
	// }
	create_fractol(f, f->name);
	return (0);
}

static int _zoom(int button, int x, int y, t_my_fractol *f)
{
	double	mouse_real;
	double	mouse_img;
	double	zoom;

	if (button == 4)
		zoom = 1.05;
	else if (button == 5)
		zoom = 0.95;
	else
		return (0);
	f->zoom *= zoom;
	mouse_real = map_pixel_to_coordinate(x, f->x_start, f->x_end, WIDTH);
	mouse_img = map_pixel_to_coordinate(y, f->y_start, f->y_end, HEIGHT);
	f->x_start = mouse_real + (f->x_start - mouse_real) * zoom;
	f->x_end = mouse_real + (f->x_end - mouse_real) * zoom;
	f->y_start = mouse_img + (f->y_start - mouse_img) * zoom;
	f->y_end = mouse_img + (f->y_end - mouse_img) * zoom;
	create_fractol(f, f->name);
	return (0);
}

void	managing_events(t_my_fractol *f)
{
	mlx_hook(f->mlx_win, 2, 0, _event, f);
	mlx_hook(f->mlx_win, 17, 0, _close, f);
	mlx_mouse_hook(f->mlx_win, _zoom, f);
}