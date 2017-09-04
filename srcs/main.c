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

// void		win_size(t_var *e)
// {
// 	e->image_x = 1000;
// 	e->image_y = 1000;
// }

void		init_fract(t_var *e, char *argv)
{
	if (ft_strcmp("mandelbrot", argv) == 0)
		m_first_init(e);
	else if (ft_strcmp("julia", argv) == 0)
		j_first_init(e);
	else if (ft_strcmp("nobila", argv) == 0)
		n_first_init(e);
}

void		display_frarg(t_mlx *min, t_var *e, char *argv)
{
	if (ft_strcmp("mandelbrot", argv) == 0)
		man_ft_draw(min, e);
	else if (ft_strcmp("julia", argv) == 0)
		jul_ft_draw(min, e);
	else if (ft_strcmp("nobila", argv) == 0)
		nob_ft_draw(min, e);
}

int			main(int argc, char **argv)
{
	t_mlx		min;
	t_var		e;

	if (argc != 2)
		ft_print_err(argc);
	if (check_argv(argv[1]) == 0)
		ft_help();
	// win_size(&e);
	init_fract(&e, argv[1]);
	min.mlx = mlx_init();
	min.win = mlx_new_window(min.mlx, W, H, "fractol");
	min.img = mlx_new_image(min.mlx, W, H);
	min.dta = (int *)mlx_get_data_addr(min.img,
	&min.bpp, &min.sl, &min.end);
	display_frarg(&min, &e, argv[1]);
	mlx_put_image_to_window(min.mlx, min.win, min.img, 0, 0);
	mlx_string_put(min.mlx, min.win, 15, 15, WHITE, argv[1]);
	e.tl = &min;
	e.argv = argv[1];
	printf("%s\n", e.argv);
	mlx_mouse_hook(min.win, &mouse_key, &e);
	mlx_hook(min.win, 2, (1L << 0), &pressed_key, &e);
	mlx_hook(min.win, 6, (6L << 0), &mouse_position, &e);
	mlx_loop(min.mlx);
	return (0);
}
