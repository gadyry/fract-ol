/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_bonus_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-gady <ael-gady@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 20:44:55 by ael-gady          #+#    #+#             */
/*   Updated: 2024/12/30 11:17:36 by ael-gady         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	set_plan(t_my_fractol *fract)
{
	fract->zoom = 1;
	fract->x_start = -2.0;
	fract->x_end = +2.0;
	fract->y_start = +2.0;
	fract->y_end = -2.0;
	fract->col1 = 5;
	fract->col2 = 3;
	fract->col3 = 11;
	fract->max_iter = 100;
}

double	map_pixel_to_coordinate(int value, double nmin, \
		double nmax, double omax)
{
	return (((double)value / omax) * (nmax - nmin) + nmin);
}

t_complex_nbr	sum_complex(t_complex_nbr z, t_complex_nbr c)
{
	t_complex_nbr	res;

	res.real = z.real + c.real;
	res.img = z.img + c.img;
	return (res);
}

t_complex_nbr	pow2_complex(t_complex_nbr z, t_my_fractol *f)
{
	double	tmp;

	if (!ft_strcmp(f->name, "tricorn"))
	{
		tmp = (z.real * z.real) - (z.img * z.img);
		z.img = -2 * z.real * z.img;
		z.real = tmp;
	}
	else
	{
		tmp = (z.real * z.real) - (z.img * z.img);
		z.img = 2 * z.real * z.img;
		z.real = tmp;
	}
	return (z);
}

double	ft_atod(char *arg)
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
