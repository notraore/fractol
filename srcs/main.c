/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 14:37:22 by notraore          #+#    #+#             */
/*   Updated: 2017/07/03 19:33:50 by notraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../toolbox.h"

void		init_fract(t_var *e, char *argv)
{
	if (ft_strcmp("mandelbrot", argv) == 0)
		m_first_init(e);
	else if (ft_strcmp("julia", argv) == 0)
		j_first_init(e);
	else if (ft_strcmp("nobila", argv) == 0)
		n_first_init(e);
}

void		display_frarg(t_var *e, char *argv)
{
	if (ft_strcmp("mandelbrot", argv) == 0)
		ft_pthread(e, man_ft_draw);
	else if (ft_strcmp("julia", argv) == 0)
		ft_pthread(e, jul_ft_draw);
	else if (ft_strcmp("nobila", argv) == 0)
		ft_pthread(e, nob_ft_draw);
}

void		display_info(t_var *e, char *argv)
{
	if (ft_strcmp("mandelbrot", argv) == 0)
		mlx_string_put(e->tl->mlx, e->tl->win, 400, 15, YELLOW, argv);
	else if (ft_strcmp("julia", argv) == 0)
		mlx_string_put(e->tl->mlx, e->tl->win, 400, 15, YELLOW, argv);
	else if (ft_strcmp("nobila", argv) == 0)
		mlx_string_put(e->tl->mlx, e->tl->win, 400, 15, YELLOW, argv);
	mlx_string_put(e->tl->mlx, e->tl->win, 15, 40, RED, "**INPUT**");
	mlx_string_put(e->tl->mlx, e->tl->win, 15, 60, RED, "-Press mouse roll \
	pad to zoom in and out.");
	mlx_string_put(e->tl->mlx, e->tl->win, 15, 80, RED, "-Press directional \
	arrows to move the image.");
	mlx_string_put(e->tl->mlx, e->tl->win, 15, 100, RED, "-Press 'w' to\
	increase iteration and 's' to decrease.");
	mlx_string_put(e->tl->mlx, e->tl->win, 15, 120, RED, "-Press 't' or 'g'\
	to change colors.");
	mlx_string_put(e->tl->mlx, e->tl->win, 15, 140, RED, "-Press 'i' to get \
	the original fractal position.");
	mlx_string_put(e->tl->mlx, e->tl->win, 15, 660, RED, "If you're using \
	julia fractal :");
	mlx_string_put(e->tl->mlx, e->tl->win, 15, 680, RED, "press the space bar \
	to disable/enable mouse motion.");
	mlx_string_put(e->tl->mlx, e->tl->win, 15, 700, RED, "-Press 'r' to \
	reset fractal zoom");
	mlx_string_put(e->tl->mlx, e->tl->win, 300, 780, RED, "-Press 'h' to\
	hide this text");
}

int			main(int argc, char **argv)
{
	t_mlx		min;
	t_var		e;

	e.tl = &min;
	e.argv = argv[1];
	if (argc != 2)
		ft_print_err(argc);
	if (check_argv(argv[1]) == 0)
		ft_help();
	min.mlx = mlx_init();
	min.win = mlx_new_window(min.mlx, W, H, "fractol");
	min.img = mlx_new_image(min.mlx, W, H);
	min.dta = (int *)mlx_get_data_addr(min.img,
	&min.bpp, &min.sl, &min.end);
	init_fract(&e, argv[1]);
	display_frarg(&e, argv[1]);
	show_input();
	mlx_mouse_hook(min.win, &mouse_key, &e);
	mlx_hook(min.win, 2, (1L << 0), &pressed_key, &e);
	mlx_hook(min.win, 6, (6L << 0), &mouse_position, &e);
	mlx_loop(min.mlx);
	return (0);
}
