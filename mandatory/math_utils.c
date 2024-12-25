/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-gady <ael-gady@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:27:21 by ael-gady          #+#    #+#             */
/*   Updated: 2024/12/25 10:20:35 by ael-gady         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
* calcule z^2 + c  { {z,c} appartient a C et {a,b} appartient a R | z = a + ib }
*/

double	map_pixel_to_coordinate(int pxl_x, int win_width, double range_start, double range_end)
{
	return (range_start + (pxl_x * (range_end - range_start) / win_width));
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
	frc->y_start*= frc->zoom;
	frc->y_end *= frc->zoom;
}

double  ft_atof(char *arg)
{
	
}
