/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-gady <ael-gady@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:20:03 by ael-gady          #+#    #+#             */
/*   Updated: 2024/12/23 00:15:35 by ael-gady         ###   ########.fr       */
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
	t_complex_nbr	c_mendel;
	t_complex_nbr	c_julia;	
}				t_my_fractol;

typedef struct s_vars
{
	int		i;
	int		j;
	double	x;
	double	y;
}			t_vars;

 /* 
 * typedef struct s_fractol
{
	double	zoom;
	void	*mlx_conn;
	void	*mlx_win;
	int		iteration;
	int		change;
	char	*name;
	t_imag	img;
	t_cmplx	z;
	t_cmplx	c;
	t_cmplx	c_j;
	double	x_debut;
	double	x_fin;
	double	y_debut;
	double	y_fin;
}	t_fractol; 

 */


/*  ****----functions----****    */
int				ft_strcmp(const char *s1, const char *s2);
void			ft_putchar_fd(int c, int fd);
void			ft_put_error(char *str, int fd);
t_complex_nbr	calculate_poly_function(t_complex_nbr z);
void    		preparing_fractol(t_my_fractol *fractol);
void			create_fractol(t_my_fractol *fractol);
void			deal_with_error(const char *msg, t_my_fractol *f);
void			handele_data_pixel(t_my_fractol *fractol, int x, int y);
double			ft_atof(char *arg);
#endif