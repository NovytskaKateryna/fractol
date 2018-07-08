/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 10:41:43 by knovytsk          #+#    #+#             */
/*   Updated: 2018/01/21 14:55:46 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	*start_threads(void *arg)
{
	t_arg			*a;
	unsigned int	y;
	unsigned int	x;

	a = (t_arg*)arg;
	y = a->id * (HEIGHT / THREADS_NUM);
	a->fr.re_factor = (a->fr.max_re - a->fr.min_re) / WIDTH;
	a->fr.im_factor = (a->fr.max_im - a->fr.min_im) / HEIGHT;
	while (y < (unsigned int)((HEIGHT / THREADS_NUM) * (a->id + 1)))
	{
		a->fr.c_im = a->fr.max_im - y * a->fr.im_factor;
		x = 0;
		while (x < WIDTH)
		{
			a->fr.c_re = a->fr.min_re + x * a->fr.re_factor;
			a->fr.z_re = a->fr.c_re;
			a->fr.z_im = a->fr.c_im;
			a->e.i = a->e.fractal[a->e.n](&a->fr);
			a->fr.pixel_col = fractal_color(a->e.i, &a->fr);
			put_img_pixel(&a->e, x, y, a->fr.pixel_col);
			x++;
		}
		y++;
	}
	return (NULL);
}

void		make_threads(t_env *e)
{
	int			i;
	pthread_t	threads[THREADS_NUM];
	t_arg		args[THREADS_NUM];
	int			status;

	i = -1;
	while (++i < THREADS_NUM)
	{
		args[i].id = i;
		args[i].e = *e;
		args[i].fr = (*e).fr;
		status = pthread_create(&threads[i], NULL, start_threads,
				(void*)&args[i]);
		if (status != 0)
			errors(ERROR_CREATE_THREAD);
	}
	i = -1;
	while (++i < THREADS_NUM)
	{
		status = (pthread_join(threads[i], NULL));
		if (status != 0)
			errors(ERROR_JOIN_THREAD);
	}
	mlx_put_image_to_window(e->p.mlx_ptr, e->p.win_ptr, e->p.img_ptr, 0, 0);
}

void		fractal_init(char *name, int n)
{
	t_env	*e;

	if (!(e = (t_env*)malloc(sizeof(t_env))))
		errors(MALLOC_ERROR);
	e->n = n;
	initial_data(e);
	if (!(e->p.mlx_ptr = mlx_init()))
		errors(MLX_INIT_ERROR);
	if (!(e->p.win_ptr = mlx_new_window(e->p.mlx_ptr, WIDTH, HEIGHT, name)))
		errors(MLX_WINDOW_ERROR);
	if (!(e->p.img_ptr = mlx_new_image(e->p.mlx_ptr, WIDTH, HEIGHT)))
		errors(MLX_IMAGE_ERROR);
	e->p.image = mlx_get_data_addr(e->p.img_ptr, &e->bpp,
			&e->size_line, &e->endian);
	e->bpp /= 8;
	make_threads(e);
	mlx_hook(e->p.win_ptr, 2, 0, key_hook, e);
	mlx_hook(e->p.win_ptr, 4, 0, mouse_events, e);
	mlx_hook(e->p.win_ptr, 6, 0, mouse_move, e);
	mlx_hook(e->p.win_ptr, 5, 0, button_release, e);
	mlx_hook(e->p.win_ptr, 17, 1L << 17, win_exit, e);
	mlx_loop(e->p.mlx_ptr);
}
