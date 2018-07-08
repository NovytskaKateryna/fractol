/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 15:04:25 by knovytsk          #+#    #+#             */
/*   Updated: 2018/01/21 15:05:15 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	params3(t_env *e)
{
	if (e->n == 4)
	{
		e->fr.min_re = -1.87;
		e->fr.max_re = 1.75;
		e->fr.min_im = -1.8;
	}
	else if (e->n == 8)
	{
		e->fr.min_re = -1.4;
		e->fr.max_re = 1.6;
		e->fr.min_im = -1.5;
	}
	else if (e->n == 9)
	{
		e->fr.min_re = -1.82;
		e->fr.max_re = 1.78;
		e->fr.min_im = -1.85;
	}
	e->fr.max_im = e->fr.min_im + (e->fr.max_re -
		e->fr.min_re) * (HEIGHT / WIDTH);
}

void	params2(t_env *e)
{
	if (e->n == 5)
	{
		e->fr.min_re = -2;
		e->fr.max_re = 1.57;
		e->fr.min_im = -1.8;
	}
	else if (e->n == 6)
	{
		e->fr.min_re = -1.9;
		e->fr.max_re = 1.7;
		e->fr.min_im = -1.75;
	}
	else if (e->n == 7)
	{
		e->fr.min_re = -1.8;
		e->fr.max_re = 1.8;
		e->fr.min_im = -1.72;
	}
	e->fr.max_im = e->fr.min_im + (e->fr.max_re -
			e->fr.min_re) * (HEIGHT / WIDTH);
}

void	params1(t_env *e)
{
	if (e->n == 1)
	{
		e->fr.min_re = -1.9;
		e->fr.max_re = 1.75;
		e->fr.min_im = -1.9;
	}
	else if (e->n == 2)
	{
		e->fr.min_re = -2;
		e->fr.max_re = 1.6;
		e->fr.min_im = -1.5;
	}
	else if (e->n == 3)
	{
		e->fr.min_re = -1.8;
		e->fr.max_re = 1.8;
		e->fr.min_im = -1.76;
	}
	e->fr.max_im = e->fr.min_im + (e->fr.max_re -
			e->fr.min_re) * (HEIGHT / WIDTH);
}
