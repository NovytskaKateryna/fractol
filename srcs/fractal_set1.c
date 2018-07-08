/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_set1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 19:47:20 by knovytsk          #+#    #+#             */
/*   Updated: 2018/01/20 14:12:11 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		mandelbrot_set(t_fr *m)
{
	unsigned int n;

	n = 0;
	while (n < m->max_iter)
	{
		m->z_re2 = m->z_re * m->z_re;
		m->z_im2 = m->z_im * m->z_im;
		if (m->z_re2 + m->z_im2 > 4)
			return (n);
		m->z_im = 2 * m->z_re * m->z_im + m->c_im;
		m->z_re = m->z_re2 - m->z_im2 + m->c_re;
		n++;
	}
	return (n);
}

int		julia_set(t_fr *m)
{
	unsigned int n;

	n = 0;
	while (n < m->max_iter)
	{
		m->z_re2 = m->z_re * m->z_re;
		m->z_im2 = m->z_im * m->z_im;
		if (m->z_re2 + m->z_im2 > 4)
			return (n);
		m->z_im = 2 * m->z_re * m->z_im + m->k_im;
		m->z_re = m->z_re2 - m->z_im2 + m->k_re;
		n++;
	}
	return (n);
}

int		ships_set(t_fr *m)
{
	unsigned int n;

	n = 0;
	while (n < m->max_iter)
	{
		m->z_re2 = m->z_re * m->z_re;
		m->z_im2 = m->z_im * m->z_im;
		if (m->z_re2 + m->z_im2 > 4)
			return (n);
		m->z_im = -2 * fabs(m->z_re * m->z_im) + m->c_im;
		m->z_re = m->z_re2 - m->z_im2 + m->c_re;
		n++;
	}
	return (n);
}

int		mandelbrot1_set(t_fr *m)
{
	unsigned int n;

	n = 0;
	while (n < m->max_iter)
	{
		m->z_re2 = m->z_re * m->z_re;
		m->z_im2 = m->z_im * m->z_im;
		if (m->z_re2 + m->z_im2 > 4)
			return (n);
		m->z_im = 2 * m->z_re * m->z_im - m->z_im + m->c_im;
		m->z_re = m->z_re2 - m->z_im2 - m->z_re + m->c_re;
		n++;
	}
	return (n);
}

int		snowman_set(t_fr *m)
{
	unsigned int	n;

	n = 0;
	while (n < m->max_iter)
	{
		m->z_re2 = m->z_re * m->z_re;
		m->z_im2 = m->z_im * m->z_im;
		if (m->z_re2 + m->z_im2 > 4)
			return (n);
		m->z_im = 4 * m->z_re * m->z_im * (m->z_re2 - m->z_im2) + m->c_im;
		m->z_re = m->z_re2 * m->z_re2 + m->z_im2 * m->z_im2 -
			6 * m->z_re2 * m->z_im2 + m->c_re;
		n++;
	}
	return (n);
}
