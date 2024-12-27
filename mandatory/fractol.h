/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-gady <ael-gady@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:20:03 by ael-gady          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/12/27 08:28:09 by ael-gady         ###   ########.fr       */
=======
/*   Updated: 2024/12/26 10:44:54 by ael-gady         ###   ########.fr       */
>>>>>>> 28e808c73588d3f6856c587ec8cc93573fa3e511
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h> // for mathematic functions
# include <unistd.h> // write 
# include <stdlib.h> // malloc & free 
# include <libc.h> // for debuggin 

# define ERROR_0 " Invalid input, try again ! \n"
# define ERROR_1 " ./fractol mandebrot\n"
# define ERROR_2 " or :\n ./fractol julia $real $img\n"

# define HEIGHT	900
# define WIDTH	900
# define MAX_ITER 150
# define BLACK_COLOR 0X000000

/*------ struct : ------*/
typedef struct s_complex_nbr
{
	double	real;
	double	img;
}				t_complex_nbr;

typedef struct s_data_img
{
	void	*img_ptr;
	char	*pixel_data;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		color;
}				t_data_img;


typedef struct s_my_fractol
{
	char			*name;
	double			zoom;
	void			*mlx_ptr;
	void			*mlx_win;
	int				nbr_iter;
	t_data_img		img;
	t_complex_nbr	z;
	t_complex_nbr	c_julia;
	double			x_start;
	double			x_end;
	double			y_start;
	double			y_end;
}				t_my_fractol;

/*
typedef struct s_vars
{
	int		i;
	int		j;
	double	x;
	double	y;
}			t_vars;
*/

/*  ****----functions----****    */
int				ft_strcmp(const char *s1, const char *s2);
void			ft_putchar_fd(int c, int fd);
void			ft_put_error(char *str, int fd);
t_complex_nbr	calculate_poly_function(t_complex_nbr z);
void    		preparing_fractol(t_my_fractol *fractol);
void			create_fractol(t_my_fractol *fractol, char *str);
void			create_fract_mandelbrot(t_my_fractol *f);
void			create_fract_julia(t_my_fractol *f);
void			deal_with_error(const char *msg, t_my_fractol *f);
void			handle_data_pixel_mand(t_my_fractol *f, int x, int y);
void			handle_data_pixel_julia(t_my_fractol *f, int x, int y);
double			map_pixel_to_coordinate(int pxl_x, int win_width, double range_start, double range_end);
t_complex_nbr	sum_complex(t_complex_nbr z, t_complex_nbr c);
t_complex_nbr	pow2_complex(t_complex_nbr z);
void			handle_data_pixel(t_my_fractol *f, int x, int y);
void			put_color(t_my_fractol *f, int x, int y, int nbr_iter);
void			put_postition_pixel(t_my_fractol *f, int x, int y, int color);
void			setup_zoom(t_my_fractol *f);
void			managing_events(t_my_fractol *f);
<<<<<<< HEAD
double			ft_atod(char *arg);
=======
double			ft_atof(char *arg);
>>>>>>> 28e808c73588d3f6856c587ec8cc93573fa3e511
#endif