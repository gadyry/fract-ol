/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_std_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-gady <ael-gady@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 00:08:18 by ael-gady          #+#    #+#             */
/*   Updated: 2024/12/23 06:16:44 by ael-gady         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void deal_with_error(const char *msg, t_my_fractol *f)
{
	if (f->img.img_ptr)
		mlx_destroy_image(f->mlx_ptr, f->img.img_ptr);
	if (f->mlx_win)
		mlx_destroy_window(f->mlx_ptr, f->mlx_win);
    if(f->mlx_ptr)
		free(f->mlx_ptr);
    ft_put_error(msg, 2);
    exit(1);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_putchar_fd(int c, int fd)
{
	if (fd >= 0)
		write (fd, &c, 1);
}

void	ft_put_error(char *str, int fd)
{
	int	i;

	if (!str && fd < 0)
		return ;
	i = 0;
	while (str[i])
	{
		ft_putchar_fd(str[i], fd);
		i++;
	}
}
