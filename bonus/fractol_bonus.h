/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-gady <ael-gady@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 20:11:09 by ael-gady          #+#    #+#             */
/*   Updated: 2024/12/31 15:22:01 by ael-gady         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# include <mlx.h>
# include <unistd.h> // write 
# include <stdlib.h>
# include <math.h> // malloc & free 
# include <libc.h>

# define ERROR_0 " Invalid input, try again ! \n"
# define ERROR_1 " ./fractol mandebrot\n"
# define ERROR_2 " or :\n ./fractol julia $real $img\n"

# define HEIGHT	800
# define WIDTH	800
# define MAX_ITER 100
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
	double			move_x;
	double			move_y;
	double			mouse_x;
	double			mouse_y;
	double			col1;
	double			col2;
	double			col3;
	double			max_iter;
}				t_my_fractol;

/*  ****----functions----****    */
int				ft_strcmp(const char *s1, const char *s2);
void			ft_putchar_fd(int c, int fd);
void			ft_put_error(char *str, int fd);
t_complex_nbr	calculate_poly_function(t_complex_nbr z);
void			preparing_fractol(t_my_fractol *fractol);
void			create_fractol(t_my_fractol *fractol, char *str);
void			create_fract_mandelbrot(t_my_fractol *f);
void			create_fract_julia(t_my_fractol *f);
void			create_fract_tricorn(t_my_fractol *f);
void			deal_with_error(char *msg, t_my_fractol *f);
void			handle_data_pixel_mand(t_my_fractol *f, int x, int y);
void			handle_data_pixel_julia(t_my_fractol *f, int x, int y);
double			map_pixel_to_coordinate(int value, double nmin, \
				double nmax, double omax);
t_complex_nbr	sum_complex(t_complex_nbr z, t_complex_nbr c);
t_complex_nbr	pow2_complex(t_complex_nbr z, t_my_fractol *f);
void			handle_data_pixel(t_my_fractol *f, int x, int y);
void			put_color(t_my_fractol *f, int x, int y, int nbr_iter);
void			put_postition_pixel(t_my_fractol *f, int x, int y, int color);
void			set_plan(t_my_fractol *fract);
void			managing_events(t_my_fractol *f);
double			ft_atod(char *arg);
void			create_fract_tricorn(t_my_fractol *f);
void			handle_data_pixel_tricorn(t_my_fractol *f, int x, int y);
void			create_fract_canopy(t_my_fractol *f);

#endif
