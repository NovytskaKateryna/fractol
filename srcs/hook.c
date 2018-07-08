/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 11:34:14 by knovytsk          #+#    #+#             */
/*   Updated: 2018/01/21 14:58:32 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		program_exit(t_env *e)
{
	free(e);
	e = NULL;
	exit(0);
}

int		win_exit(t_env *e)
{
	mlx_destroy_window(e->p.mlx_ptr, e->p.win_ptr);
	e->p.mlx_ptr = NULL;
	e->p.win_ptr = NULL;
	return (0);
}

int		mouse_events(int button, int x, int y, t_env *e)
{
	e->mouse_re = e->fr.min_re + x * (e->fr.max_re - e->fr.min_re) / WIDTH;
	e->mouse_im = e->fr.max_im - y * (e->fr.max_im - e->fr.min_im) / HEIGHT;
	if (button == 1)
	{
		e->mouse_on = 1;
		e->mouse_x = e->fr.min_re + x * (e->fr.max_re - e->fr.min_re) / WIDTH;
		e->mouse_y = e->fr.max_im - y * (e->fr.max_im - e->fr.min_im) / HEIGHT;
		mouse_move(x, y, e);
	}
	if (button == 5)
	{
		e->zoom_factor = 1.1;
		zoom(e, e->mouse_re, e->mouse_im);
	}
	if (button == 4)
	{
		e->zoom_factor = 1.0 / 1.1;
		zoom(e, e->mouse_re, e->mouse_im);
	}
	clear_image(e);
	make_threads(e);
	return (0);
}

int		key_hook(int keycode, t_env *e)
{
	change_pallete(keycode, e);
	moving(keycode, e);
	windows(keycode, 0);
	if (keycode == 53)
		program_exit(e);
	if (keycode == 69 && e->fr.max_iter < 1000000)
		e->fr.max_iter += 50;
	if (keycode == 78 && e->fr.max_iter > 100)
		e->fr.max_iter -= 50;
	if (keycode == 49 && e->key_on == 0)
		e->key_on = 1;
	else if (keycode == 49 && e->key_on == 1)
		e->key_on = 0;
	if (keycode == 36)
	{
		e->fr.k_im = 0;
		e->fr.k_re = sin(e->angle);
		e->angle += 0.05;
	}
	if (keycode == 67)
		initial_data(e);
	clear_image(e);
	make_threads(e);
	return (0);
}
