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
	ft_putendl("usage : ./fractol [fractal to display]\n");
	ft_putendl("\t\t\tAvailable fractal :");
	ft_putendl("-> \"julia\"");
	ft_putendl("-> \"mandelbrot\"");
	ft_putendl("-> \"nobila\"");
	ft_putendl("-> Press \"all\" to display all available fractals.");
	exit(EXIT_FAILURE);
}

void	ft_print_err(int argc)
{
	if (argc > 2)
		write(2, "\n\t\t\t*****Too many arguments.*****\n", 34);
	if (argc < 2)
		ft_putendl("Please. Enter a fractal name to display.");
	ft_help();
}

int		check_argv(char *argv)
{
	if (ft_strcmp("mandelbrot", argv) == 0)
		return (1);
	else if (ft_strcmp("julia", argv) == 0)
		return (1);
	else if (ft_strcmp("nobila", argv) == 0)
		return (1);
	ft_putendl("\t\t\tBad typography or unknown fractal.");
	return (0);
}

void	show_input(void)
{
	ft_putendl("\t\t\t**INPUT**");
	ft_putendl("-Press mouse roll pad to zoom in and out.");
	ft_putendl("-Press directional arrows to move the image.");
	ft_putendl("-Press 'w' to increase iteration and 's' to decrease.");
	ft_putendl("-Press 't' or 'g' to change colors.");
	ft_putendl("-Press 'r' to reset fractal position");
	ft_putstr("\tIf you're using julia fractal, press the space bar to ");
	ft_putendl("disable/enable mouse motion.");
	ft_putendl("-Press 'esc' to exit the program.");
}
