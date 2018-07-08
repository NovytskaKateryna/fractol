/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knovytsk <knovytsk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 11:04:23 by knovytsk          #+#    #+#             */
/*   Updated: 2018/01/20 14:07:14 by knovytsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	errors(int error)
{
	if (error == ERROR_CREATE_THREAD)
		ft_putendl("Cannot create a thread.");
	else if (error == ERROR_JOIN_THREAD)
		ft_putendl("Cannot join threads.");
	else if (error == INCORRECT_NAME)
		ft_putendl("Input name is incorrect.");
	else if (error == MALLOC_ERROR)
		ft_putendl("Cannot allocate memory.");
	else if (error == MLX_INIT_ERROR)
		ft_putendl("Cannot connect to the X server.");
	else if (error == MLX_WINDOW_ERROR)
		ft_putendl("Cannot create a new mindow.");
	else if (error == MLX_IMAGE_ERROR)
		ft_putendl("Cannot create an image.");
	else if (error == MANY_ARGUMENTS)
		ft_putendl("Put one argument.");
	exit(1);
}
