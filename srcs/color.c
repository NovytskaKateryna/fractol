/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 19:44:47 by knovytsk          #+#    #+#             */
/*   Updated: 2018/01/21 14:58:57 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	fractal_color(unsigned int n, t_fr *fr)
{
	double			index;
	union u_color	c;
	double			z_n;

	if (n == fr->max_iter)
		return (0);
	z_n = sqrt(fr->z_re2 + fr->z_im2);
	index = n + (log(log(4)) - log(log(z_n)) / log(2));
	c.chanel[0] = (unsigned char)(sin(0.01 * index + fr->c[0]) * 250 + 5);
	c.chanel[1] = (unsigned char)(sin(0.01 * index + fr->c[1]) * 250 + 5);
	c.chanel[2] = (unsigned char)(sin(0.01 * index + fr->c[2]) * 250 + 5);
	return (c.color_value);
}
