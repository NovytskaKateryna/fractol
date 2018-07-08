/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_set2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 09:31:21 by knovytsk          #+#    #+#             */
/*   Updated: 2018/01/20 14:14:08 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		star_set(t_fr *m)
{
	unsigned int n;

	n = 0;
	while (n < m->max_iter)
	{
		m->z_re2 = m->z_re * m->z_re;
		m->z_im2 = m->z_im * m->z_im;
		if (m->z_re2 + m->z_im2 > 4)
			return (n);
		m->z_im = -4 * m->z_re * m->z_im * (m->z_re2 - m->z_im2) + m->c_im;
		m->z_re = m->z_re2 * m->z_re2 + m->z_im2 * m->z_im2 -
			6 * m->z_re2 * m->z_im2 + m->c_re;
		n++;
	}
	return (n);
}

int		fish_set(t_fr *m)
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
		m->z_re = fabs(m->z_re2 - m->z_im2) + m->c_re;
		n++;
	}
	return (n);
}

int		bird_set(t_fr *m)
{
	unsigned int n;

	n = 0;
	while (n < m->max_iter)
	{
		m->z_re2 = m->z_re * m->z_re;
		m->z_im2 = m->z_im * m->z_im;
		if (m->z_re2 + m->z_im2 > 4)
			return (n);
		m->z_im = ((m->z_re2 * 3) - m->z_im2) * fabs(m->z_im) + m->c_im;
		m->z_re = (m->z_re2 - (m->z_im2 * 3)) * fabs(m->z_re) + m->c_re;
		n++;
	}
	return (n);
}

int		man_set(t_fr *m)
{
	unsigned int n;

	n = 0;
	while (n < m->max_iter)
	{
		m->z_re2 = m->z_re * m->z_re;
		m->z_im2 = m->z_im * m->z_im;
		if (m->z_re2 + m->z_im2 > 4)
			return (n);
		m->z_im = ((m->z_re2 * 3) - m->z_im2) * fabs(m->z_im) + m->c_im;
		m->z_re = (m->z_re2 - (m->z_im2 * 3)) * m->z_re + m->c_re;
		n++;
	}
	return (n);
}

int		julia6_set(t_fr *m)
{
	unsigned int n;

	n = 0;
	while (n < m->max_iter)
	{
		m->z_re2 = m->z_re * m->z_re;
		m->z_im2 = m->z_im * m->z_im;
		m->z_re3 = m->z_re2 * m->z_re;
		m->z_im3 = m->z_im2 * m->z_im;
		if (m->z_re2 + m->z_im2 > 4)
			return (n);
		m->z_im = 6 * m->z_re3 * m->z_re2 * m->z_im - 20 * m->z_re3 *
			m->z_im3 + 6 * m->z_re * m->z_im3 * m->z_im2 + m->g_im;
		m->z_re = m->z_re3 * m->z_re3 - 15 * m->z_re2 * m->z_re2 * m->z_im2 +
			15 * m->z_re2 * m->z_im2 * m->z_im2 - m->z_im3 * m->z_im3 + m->g_re;
		n++;
	}
	return (n);
}
