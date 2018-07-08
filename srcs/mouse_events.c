/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 15:01:40 by knovytsk          #+#    #+#             */
/*   Updated: 2018/01/15 12:20:29 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		button_release(int button, int x, int y, t_env *e)
{
	double	j;
	double	i;

	i = x;
	j = y;
	if (button == 1)
		e->mouse_on = 0;
	return (0);
}

void	zoom(t_env *e, double mouse_re, double mouse_im)
{
	double inp;

	inp = 1.0 / e->zoom_factor;
	e->index /= e->zoom_factor;
	e->fr.min_re = mouse_re + ((e->fr.min_re - mouse_re) * inp);
	e->fr.min_im = mouse_im + ((e->fr.min_im - mouse_im) * inp);
	e->fr.max_re = mouse_re + ((e->fr.max_re - mouse_re) * inp);
	e->fr.max_im = mouse_im + ((e->fr.max_im - mouse_im) * inp);
}

void	move(t_env *e, double mouse_re, double mouse_im)
{
	double x_translation;
	double y_translation;

	x_translation = e->mouse_x - mouse_re;
	y_translation = e->mouse_y - mouse_im;
	e->fr.min_re += x_translation;
	e->fr.min_im += y_translation;
	e->fr.max_re += x_translation;
	e->fr.max_im += y_translation;
}

int		mouse_move(int x, int y, t_env *e)
{
	e->mouse_re = e->fr.min_re + x * (e->fr.max_re - e->fr.min_re) / WIDTH;
	e->mouse_im = e->fr.max_im - y * (e->fr.max_im - e->fr.min_im) / HEIGHT;
	if (e->key_on == 0 && x > 0 && x < WIDTH && y > 0 && y < HEIGHT)
	{
		e->fr.k_im = e->fr.max_im - y * (e->fr.max_re - e->fr.min_re) / WIDTH;
		e->fr.k_re = e->fr.min_re + x * (e->fr.max_im - e->fr.min_im) / HEIGHT;
		e->fr.g_im = e->fr.max_im - y * (e->fr.max_re - e->fr.min_re) / WIDTH;
		e->fr.g_re = e->fr.min_re + x * (e->fr.max_im - e->fr.min_im) / HEIGHT;
	}
	if (e->mouse_on == 1 && x > 0 && x < WIDTH && y > 0 && y < HEIGHT)
		move(e, e->mouse_re, e->mouse_im);
	clear_image(e);
	make_threads(e);
	return (0);
}
