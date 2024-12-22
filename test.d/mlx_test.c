/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-gady <ael-gady@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 19:45:22 by ael-gady          #+#    #+#             */
/*   Updated: 2024/12/18 10:14:03 by ael-gady         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdio.h>

void    create_rectangle(void *mlx_ptr, void *win_ptr, int x, int y, int hight, int width, int color)
{
    int i = 0, j;

    while (i < width)
    {
        j = 0;
        while (j < hight)
        {
            mlx_pixel_put(mlx_ptr, win_ptr, x + i, y + j, color);
            j++;
        }
        i++;
    }
}

int main()
{
    void    *mlx_ptr;
    void    *win_ptr;

    mlx_ptr = mlx_init();
    if (NULL == mlx_ptr)
        return (-1);
    
    win_ptr = mlx_new_window(mlx_ptr, 800, 600, "Window for test !");
    if (NULL == win_ptr)
        return (-1);

    int hight = 100, width = 100;
    int i = 0, j;
    int x = 100, y = 100;

    create_rectangle(mlx_ptr, win_ptr, 0, 0, hight, width, 0x00FF00);
    create_rectangle(mlx_ptr, win_ptr, x, y, hight, width, 0xFF0000);
    create_rectangle(mlx_ptr, win_ptr, 200, 200, hight, width, 0x000080);
    create_rectangle(mlx_ptr, win_ptr, 300, 300, hight, width, 0xFF00FF);
    create_rectangle(mlx_ptr, win_ptr, 400, 400, hight, width, 0x800080);
    create_rectangle(mlx_ptr, win_ptr, 500, 500, hight, width, 0xFFFF00);
    





    
    // while (i < width)
    // {
    //     j = 0;
    //     while (j < hight)
    //     {
    //         mlx_pixel_put(mlx_ptr, win_ptr, x + i, y + j, 0x00FF00);
    //         j++;
    //     }
    //     i++;
    // }
    
    mlx_loop(mlx_ptr);
}