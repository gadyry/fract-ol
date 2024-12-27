/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-gady <ael-gady@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:27:21 by ael-gady          #+#    #+#             */
/*   Updated: 2024/12/27 16:38:08 by ael-gady         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
* calcule z^2 + c  { {z,c} appartient a C et {a,b} appartient a R | z = a + ib }
*/
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
void	setup_zoom(t_my_fractol *frc)
{
	frc->x_start *= frc->zoom;
	frc->x_end *= frc->zoom;
	frc->y_start *= frc->zoom;
	frc->y_end *= frc->zoom;
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
