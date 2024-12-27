/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-gady <ael-gady@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 18:43:55 by ael-gady          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/12/27 08:03:51 by ael-gady         ###   ########.fr       */
=======
/*   Updated: 2024/12/26 10:22:47 by ael-gady         ###   ########.fr       */
>>>>>>> 28e808c73588d3f6856c587ec8cc93573fa3e511
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	_event(int keycode, t_my_fractol *f)
{
	if (keycode == 53)
<<<<<<< HEAD
		return (_close(f));
=======
		_close(f);
>>>>>>> 28e808c73588d3f6856c587ec8cc93573fa3e511
	return (0);
}

static int _close(t_my_fractol *f)
{
	mlx_destroy_image(f->mlx_ptr, f->img.img_ptr);
	mlx_destroy_window(f->mlx_ptr, f->mlx_win);
	free(f->mlx_ptr);
	exit(0);
}

static int _zoom(int button, int x, int y, t_my_fractol *f)
{
	(void)x;
	(void)y;
	if (button == 4)
<<<<<<< HEAD
		f->zoom = 1.1;
	else if (button == 5)
		f->zoom = 0.9;
	create_fractol(f, f->name);
=======
	{
		f->zoom = 1.1;
		// function_check_(mandel/julia)
		create_frac_mandelbrot(f);
	}
	else if (button == 5)
	{
		f->zoom = 0.9;
		// function_check_(mandel/julia)
		create_frac_julia(f);
	}
>>>>>>> 28e808c73588d3f6856c587ec8cc93573fa3e511
}

void    managing_events(t_my_fractol *f)
{
	mlx_hook(f->mlx_win, 2, 0, _event, f);
	mlx_hook(f->mlx_win, 17, 0, _close, f);
	mlx_mouse_hook(f->mlx_win, _zoom, f);
}