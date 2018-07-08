/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 18:15:36 by knovytsk          #+#    #+#             */
/*   Updated: 2018/01/21 15:00:38 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	all_fractals(t_env *e)
{
	e->fractal[0] = &mandelbrot_set;
	e->fractal[1] = &julia_set;
	e->fractal[2] = &ships_set;
	e->fractal[3] = &snowman_set;
	e->fractal[4] = &star_set;
	e->fractal[5] = &fish_set;
	e->fractal[6] = &bird_set;
	e->fractal[7] = &man_set;
	e->fractal[8] = &mandelbrot1_set;
	e->fractal[9] = &julia6_set;
}

void	make_pallete(t_env *e)
{
	e->pallete[0][0] = 0;
	e->pallete[0][1] = 0;
	e->pallete[0][2] = 0;
	e->pallete[1][0] = 0;
	e->pallete[1][1] = 0;
	e->pallete[1][2] = 4;
	e->pallete[2][0] = 4;
	e->pallete[2][1] = 2;
	e->pallete[2][2] = 1;
	e->pallete[3][0] = 1;
	e->pallete[3][1] = 2;
	e->pallete[3][2] = 5;
	e->pallete[4][0] = 4;
	e->pallete[4][1] = 0;
	e->pallete[4][2] = 0;
	e->pal_num = 0;
}

void	initial_data(t_env *e)
{
	e->key_on = 1;
	e->index = 0.07;
	e->fr.g_re = 0.390982;
	e->fr.g_im = 0.640481;
	e->fr.k_im = -0.225451;
	e->fr.k_re = -0.743487;
	e->fr.c[0] = 0;
	e->fr.c[1] = 0;
	e->fr.c[2] = 0;
	e->fr.max_iter = 100;
	e->fr.min_re = -2;
	e->fr.max_re = 1;
	e->fr.min_im = -1.5;
	params1(e);
	params2(e);
	params3(e);
	all_fractals(e);
	make_pallete(e);
}
