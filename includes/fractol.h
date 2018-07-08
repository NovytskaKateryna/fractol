/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 10:51:53 by knovytsk          #+#    #+#             */
/*   Updated: 2018/01/21 15:54:21 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H

# include <mlx.h>
# include <pthread.h>
# include <math.h>
# include <fcntl.h>
# include "../libft/libft.h"

# define WIDTH 800
# define HEIGHT 800
# define THREADS_NUM 8

# define ERROR_CREATE_THREAD 10
# define ERROR_JOIN_THREAD 11
# define INCORRECT_NAME 5
# define MALLOC_ERROR 1
# define MLX_INIT_ERROR 2
# define MLX_WINDOW_ERROR 3
# define MLX_IMAGE_ERROR 4
# define MANY_ARGUMENTS 7

union				u_color
{
	unsigned int	color_value;
	unsigned char	chanel[3];
};

typedef struct		s_fr
{
	long double		min_re;
	long double		max_re;
	long double		min_im;
	long double		max_im;
	double			re_factor;
	double			im_factor;
	double			c_im;
	double			c_re;
	double			z_im;
	double			z_re;
	double			z_re2;
	double			z_im2;
	double			z_re3;
	double			z_im3;
	double			k_re;
	double			k_im;
	double			g_re;
	double			g_im;
	unsigned int	max_iter;
	unsigned int	pixel_col;
	int				c[3];
}					t_fr;

typedef struct		s_p
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*image;
}					t_p;

typedef struct		s_env
{
	t_p				p;
	int				bpp;
	int				size_line;
	int				endian;
	int				width;
	int				height;
	double			angle;
	int				mouse_on;
	int				key_on;
	double			mouse_x;
	double			mouse_y;
	double			mouse_re;
	double			mouse_im;
	double			index;
	double			zoom_factor;
	int				pallete[5][3];
	int				pal_num;
	t_fr			fr;
	int				(*fractal[10])(t_fr*);
	int				n;
	unsigned int	i;
}					t_env;

typedef struct		s_arg
{
	int				id;
	t_env			e;
	t_fr			fr;
}					t_arg;

void				fractal_init(char *name, int n);
void				make_threads(t_env *e);
void				initial_data(t_env *e);
int					fractal_color(unsigned int n, t_fr *fr);
int					key_hook(int keycode, t_env *e);
int					change_pallete(int keycode, t_env *e);
int					moving(int keycode, t_env *e);
int					windows(int keycode, void *param);
int					win_exit(t_env *e);
int					mouse_events(int button, int x, int y, t_env *e);
int					mouse_move(int x, int y, t_env *e);
void				zoom(t_env *e, double mouse_re, double mouse_im);
int					button_release(int button, int x, int y, t_env *e);
void				clear_image(t_env *e);
void				put_img_pixel(t_env *e, unsigned int x, unsigned int y,
									int color);
int					mandelbrot_set(t_fr *m);
int					julia_set(t_fr *m);
int					ships_set(t_fr *m);
int					mandelbrot1_set(t_fr *m);
int					snowman_set(t_fr *m);
int					star_set(t_fr *m);
int					fish_set(t_fr *m);
int					bird_set(t_fr *m);
int					man_set(t_fr *m);
int					julia6_set(t_fr *m);
void				params1(t_env *e);
void				params2(t_env *e);
void				params3(t_env *e);
void				errors(int error);
#endif
