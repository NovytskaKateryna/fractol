/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 10:55:59 by knovytsk          #+#    #+#             */
/*   Updated: 2018/01/20 14:06:39 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	display_fractals(void)
{
	ft_putendl("\nYOU CAN CHOOSE ONE OF THESE:\n");
	ft_putendl("0.mandelbrot");
	ft_putendl("1.julia");
	ft_putendl("2.ships");
	ft_putendl("3.snowman");
	ft_putendl("4.star");
	ft_putendl("5.fish");
	ft_putendl("6.bird");
	ft_putendl("7.man");
	ft_putendl("8.mandelbrot1");
	ft_putendl("9.julia6\n");
	exit(0);
}

int		f_names2(char *av)
{
	if (ft_strcmp(av, "snowman") == 0)
		fractal_init("SNOWMAN", 3);
	else if (ft_strcmp(av, "star") == 0)
		fractal_init("STAR", 4);
	else if (ft_strcmp(av, "fish") == 0)
		fractal_init("FISH", 5);
	else if (ft_strcmp(av, "bird") == 0)
		fractal_init("BIRD", 6);
	else if (ft_strcmp(av, "man") == 0)
		fractal_init("MAN", 7);
	return (0);
}

int		f_names1(char *av)
{
	if (ft_strcmp(av, "mandelbrot") == 0)
		fractal_init("MANDELBROT", 0);
	else if (ft_strcmp(av, "julia") == 0)
		fractal_init("JULIA", 1);
	else if (ft_strcmp(av, "ships") == 0)
		fractal_init("SHIPS", 2);
	else if (ft_strcmp(av, "mandelbrot1") == 0)
		fractal_init("MANDELBROT1", 8);
	else if (ft_strcmp(av, "julia6") == 0)
		fractal_init("JULIA6", 9);
	return (0);
}

int		main(int ac, char **av)
{
	if (ac < 2)
		display_fractals();
	if (ac > 2)
		errors(MANY_ARGUMENTS);
	if (!(f_names1(av[1])) && !(f_names2(av[1])))
		errors(INCORRECT_NAME);
	return (0);
}
