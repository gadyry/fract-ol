/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_bonus_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-gady <ael-gady@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 20:44:55 by ael-gady          #+#    #+#             */
/*   Updated: 2024/12/28 18:33:50 by ael-gady         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	set_plan(t_my_fractol *fract)
{
	fract->zoom = 1;
	fract->x_start = -2.0;
	fract->x_end = 2.0;
	fract->y_start = 2.0;
	fract->y_end = -2.0;
}

double	map_pixel_to_coordinate(double value, double nmin, double nmax, double omax)
{
	return ((value / omax ) * (nmax - nmin) + nmin);
}

t_complex_nbr	sum_complex(t_complex_nbr z, t_complex_nbr c)
{
	t_complex_nbr	res;
	res.real = z.real + c.real;
	res.img = z.img + c.img;
	return (res);
}

t_complex_nbr  pow2_complex(t_complex_nbr z)
{
	double tmp;

	tmp = (z.real * z.real) - (z.img * z.img);
	z.img = 2 * z.real * z.img;
	z.real = tmp;
	return (z);
}
void	set_up_zoom(t_my_fractol *f, int x, int y)  // I have a problem in this function !!
{
	double	mouse_real;
	double	mouse_img;
	// double	zoom;

	// f->zoom *= zoom;
	mouse_real = map_pixel_to_coordinate(x, f->x_start, f->x_end, WIDTH);
	mouse_img = map_pixel_to_coordinate(y, f->y_start, f->y_end, HEIGHT);
	f->x_start = mouse_real + (f->x_start - mouse_real) * f->zoom;
	f->x_end = mouse_real + (f->x_end - mouse_real) * f->zoom;
	f->y_start = mouse_img + (f->x_start - mouse_img) * f->zoom;
	f->y_end = mouse_img + (f->x_end - mouse_img) * f->zoom;
}

double  ft_atod(char *arg)
{
	int		i;
	int		sign;
	double	res;
	double	nbr_rational;

	sign = 1;
	i = 0;
	if (arg[i] == '+' || arg[i] == '-')
		if (arg[i++] == '-')
			sign *= -1;
	res = 0;
	while (arg[i] >= '0' && arg[i] <= '9')
		res = res * 10 + arg[i++] - '0';
	if (arg[i] == '.')
		i++;
	nbr_rational = 0.1;
	while (arg[i] >= '0' && arg[i] <= '9')
	{
		res += (arg[i++] - '0') * nbr_rational;
		nbr_rational *= 0.1;
	}
	return (sign * res);
}
