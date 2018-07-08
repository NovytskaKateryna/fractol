/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 12:01:17 by knovytsk          #+#    #+#             */
/*   Updated: 2018/01/20 14:15:02 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	clear_image(t_env *e)
{
	ft_bzero(e->p.image, WIDTH * HEIGHT * e->bpp);
}

void	put_img_pixel(t_env *e, unsigned int x, unsigned int y, int color)
{
	if (x <= WIDTH && y <= HEIGHT)
		*(int*)(e->p.image + (x + y * WIDTH) * e->bpp) = color;
}
