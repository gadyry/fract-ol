/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-gady <ael-gady@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 23:05:33 by ael-gady          #+#    #+#             */
/*   Updated: 2024/12/23 00:15:41 by ael-gady         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	create_fractol(t_my_fractol *f)
{
	int i;
	int j;
	
	i = -1;
	while (++i < WIDTH)
	{
		j = -1;
		while (j++ < HEIGHT)
		{
			handele_data_pixel(f, i, j);
		}
	}
	mlx_put_image_to_window(f->mlx_ptr, f->mlx_win, f->img.img_ptr, 0, 0);
}
