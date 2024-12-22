/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-gady <ael-gady@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:19:46 by ael-gady          #+#    #+#             */
/*   Updated: 2024/12/23 00:06:43 by ael-gady         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void preparing_fractol(t_my_fractol *fr)
{
    fr->mlx_ptr = NULL;
    fr->mlx_win = NULL;
    fr->img.img_ptr = NULL;
    fr->mlx_ptr = mlx_init();
    if (fr->mlx_ptr == NULL)
        deal_with_error("Problem in connection!\n", fr);
    fr->mlx_win = mlx_new_window(fr->mlx_ptr, WIDTH, HEIGHT, fr->name);
    if (fr->mlx_win == NULL)
        deal_with_error("Problem creating the window!\n", fr);
    fr->img.img_ptr = mlx_new_image(fr->mlx_ptr, WIDTH, HEIGHT);
    if (fr->img.img_ptr == NULL)
        deal_with_error("Problem creating the image!\n", fr);
    fr->img.data = mlx_get_data_addr(fr->img.img_ptr, &fr->img.bits_per_pixel, \
					&fr->img.line_length, &fr->img.endian);
    if (fr->img.addr == NULL)
		deal_with_error("Problem accessing image data!\n", fr);
}

int main (int ac, char *av[])
{
	if (ac == 2 && (!ft_strcmp(av[1],"mandelbrot")))
	{
		t_my_fractol	fractol;

		fractol.name = "mandelbrot";
		preparing_fractol(&fractol);
		create_fractol(&fractol);
	}
	else if (ac == 4 && !ft_strcmp(av[1], "julia"))
	{
		t_my_fractol	fractol;

		fractol.name = "julia";
		// fractol.c_julia.real = ft_atof(av[2]);
		// fractol.c_julia.img = ft_atof(av[3]);
		preparing_fractol(&fractol);
	}
	else
	{
		ft_put_error(ERROR_0 ERROR_1 ERROR_2, 2);
	}
}