/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 13:09:22 by knovytsk          #+#    #+#             */
/*   Updated: 2018/01/21 14:57:34 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		change_pallete(int keycode, t_env *e)
{
	if (keycode == 51)
	{
		e->pal_num++;
		if (e->pal_num == 5)
			e->pal_num = 0;
		e->fr.c[0] = e->pallete[e->pal_num][0];
		e->fr.c[1] = e->pallete[e->pal_num][1];
		e->fr.c[2] = e->pallete[e->pal_num][2];
	}
	return (0);
}

int		moving(int keycode, t_env *e)
{
	if (keycode == 126)
	{
		e->fr.min_im -= e->index;
		e->fr.max_im -= e->index;
	}
	if (keycode == 125)
	{
		e->fr.min_im += e->index;
		e->fr.max_im += e->index;
	}
	if (keycode == 123)
	{
		e->fr.min_re += e->index;
		e->fr.max_re += e->index;
	}
	if (keycode == 124)
	{
		e->fr.min_re -= e->index;
		e->fr.max_re -= e->index;
	}
	return (0);
}

int		win_count(int keycode, int win_n)
{
	if ((keycode == 29 || keycode == 18 || keycode == 19 ||
		keycode == 20 || keycode == 21 || keycode == 23 ||
		keycode == 22 || keycode == 26 || keycode == 28 ||
		keycode == 25) && win_n < 20)
		win_n++;
	return (win_n);
}

int		windows(int keycode, void *param)
{
	static int win_n = 1;

	param = NULL;
	win_n = win_count(keycode, win_n);
	if (keycode == 29 && win_n < 20)
		fractal_init("MANDELBROT", 0);
	else if (keycode == 18 && win_n < 20)
		fractal_init("JULIA", 1);
	else if (keycode == 19 && win_n < 20)
		fractal_init("SHIPS", 2);
	else if (keycode == 20 && win_n < 20)
		fractal_init("SNOWMAN", 3);
	else if (keycode == 21 && win_n < 20)
		fractal_init("STAR", 4);
	else if (keycode == 23 && win_n < 20)
		fractal_init("FISH", 5);
	else if (keycode == 22 && win_n < 20)
		fractal_init("BIRD", 6);
	else if (keycode == 26 && win_n < 20)
		fractal_init("MAN", 7);
	else if (keycode == 28 && win_n < 20)
		fractal_init("MANDELBROT1", 8);
	else if (keycode == 25 && win_n < 20)
		fractal_init("JULIA6", 9);
	return (0);
}
