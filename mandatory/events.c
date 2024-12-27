/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-gady <ael-gady@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 18:43:55 by ael-gady          #+#    #+#             */
/*   Updated: 2024/12/27 18:48:02 by ael-gady         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	return (0);
}

static int _zoom(int button, int x, int y, t_my_fractol *f)
{
	(void)x;
	(void)y;
	if (button == 4)
		f->zoom = 1.05;
	else if (button == 5)
		f->zoom = 0.95;
	create_fractol(f, f->name);
	return (0);
}

void	managing_events(t_my_fractol *f)
{
	mlx_hook(f->mlx_win, 2, 0, _event, f);
	mlx_hook(f->mlx_win, 17, 0, _close, f);
	mlx_mouse_hook(f->mlx_win, _zoom, f);
}