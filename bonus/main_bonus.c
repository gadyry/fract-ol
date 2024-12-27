/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-gady <ael-gady@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 20:10:31 by ael-gady          #+#    #+#             */
/*   Updated: 2024/12/27 20:41:41 by ael-gady         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	create_fractol(t_my_fractol *f, char *str)
{
	if (!ft_strcmp(str, "mandelbrot"))
		create_fract_mandelbrot(f);
	else if (!ft_strcmp(str, "julia"))
		create_fract_julia(f);
	else
		create_fract_tricorn(f);
	managing_events(f);
}

void	preparing_fractol(t_my_fractol *fr)
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
	fr->img.pixel_data = mlx_get_data_addr(fr->img.img_ptr, \
	&fr->img.bits_per_pixel, &fr->img.line_length, &fr->img.endian);
	if (fr->img.pixel_data == NULL)
		deal_with_error("Problem accessing image data!\n", fr);
	set_plan(fr);
}

int	main(int ac, char *av[])
{
	t_my_fractol	fractol;

	if (ac == 2 && (!ft_strcmp(av[1], "mandelbrot") \
		|| !ft_strcmp(av[1], "tricorn")))
	{
		fractol.name = av[1];
		preparing_fractol(&fractol);
		create_fractol(&fractol, fractol.name);
		managing_events(&fractol);
		mlx_loop(fractol.mlx_ptr);
	}
	else if (ac == 4 && !ft_strcmp(av[1], "julia")
		&& ft_check_arg(av[2]) && ft_check_arg(av[3]))
	{
		fractol.name = "julia";
		fractol.c_julia.real = ft_atod(av[2]);
		fractol.c_julia.img = ft_atod(av[3]);
		preparing_fractol(&fractol);
		create_fractol(&fractol, fractol.name);
		managing_events(&fractol);
		mlx_loop(fractol.mlx_ptr);
	}
	else
		ft_put_error(ERROR_0 ERROR_1 ERROR_2, 2);
	return (0);
}
