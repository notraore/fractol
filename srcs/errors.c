/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 12:24:07 by notraore          #+#    #+#             */
/*   Updated: 2017/06/14 15:48:17 by notraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../toolbox.h"

void	ft_help(void)
{
	ft_putendl("./fractol [fractal to display]\n");
	ft_putendl("\t\t\tAvailable fractal :");
	ft_putendl("-> \"Julia\"");
	ft_putendl("-> \"Mandelbrot\"");
	ft_putendl("-> \"Nobila\"");
	ft_putendl("-> Press \"all\" to display all available fractals.");
	ft_putendl("-> Otherwise, press \"random\" to display a random fractale.");
	write(1, "\n", 1);
	ft_putendl("\t\t\t**INPUT**");
	ft_putendl("-Press 'q' and 'e' to add and substract relief.");
	ft_putendl("-Press '+' and '-' to zoom in and out.");
	ft_putendl("-Press directional arrows to move the image.");
	ft_putendl("-Press 'esc' to exit the program.");
	exit(EXIT_SUCCESS);
}

void	ft_print_err(int argc)
{
	if (argc > 2)
		ft_putendl("\n\t\t\t*****Too many arguments.*****\n");
	if (argc < 2)
		ft_putendl("Please. Enter a fractal name to display.");
	ft_help();
}
