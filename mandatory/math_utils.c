/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-gady <ael-gady@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:27:21 by ael-gady          #+#    #+#             */
/*   Updated: 2024/12/22 21:02:53 by ael-gady         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
* calcule z^2 + c  { {z,c} appartient a C et {a,b} appartient a R | z = a + ib }
*/

t_complex_nbr  calculate_poly_function(t_complex_nbr z)
{
    double tmp;
    
    tmp = (z.real * z.real) - (z.img * z.img); // real part 
    z.img = 2 * z.real * z.img; // img part 
    z.real = tmp;
    return (z);
}

double  ft_atof(char *arg)
{
    
}
