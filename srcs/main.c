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

void		draw_var_init(t_var *e)
{
	e->x = 0;
	e->y = 0;
	e->x1 = -2.1;
	e->x2 = 0.6;
	e->y1 = -1.2;
	e->y2 = 1.2;
	e->it_max = 50;
	e->zoom_x = W / (e->x2 - e->x1) + e->z;
	e->zoom_y = H / (e->y2 - e->y1) + e->z;
}

void		var_reset(t_var *e)
{
	e->c_r = e->x / e->zoom_x + e->x1;
	e->c_i = e->y / e->zoom_y + e->y1;
	e->z_r = 0;
	e->z_i = 0;
	e->i = 0;
}

void		ft_draw(t_mlx *min, t_var *e)
{
	draw_var_init(e);
	while (e->x < W)
	{
		e->y = 0;
		while (e->y < H)
		{
			var_reset(e);
			while (e->z_r * e->z_r + e->z_i * e->z_i < 4 && e->i < e->it_max)
			{
				e->tmp = e->z_r;
				e->z_r = e->z_r * e->z_r - e->z_i * e->z_i + e->c_r;
				e->z_i = 2 * e->z_i * e->tmp + e->c_i;
				e->i = e->i + 1;
			}
			if (e->i == e->it_max)
				min->dta[e->x + e->y * H] = BLACK;
			else
				min->dta[e->x + e->y * H] = e->i * BLUE / e->it_max + 1;
			e->y += 1;
		}
		e->x += 1;
	}
}

int			main(int argc, char **argv)
{
	t_mlx		min;
	t_var		e;

	if (argc != 2)
		ft_print_err(argc);
	min.mlx = mlx_init();
	min.win = mlx_new_window(min.mlx, W, H, "fractol");
	min.img = mlx_new_image(min.mlx, W, H);
	min.dta = (int *)mlx_get_data_addr(min.img,
	&min.bpp, &min.sl, &min.end);
	ft_draw(&min, &e);
	e.tl = &min;
	mlx_put_image_to_window(min.mlx, min.win, min.img, 0, 0);
	mlx_string_put(min.mlx, min.win, 15, 15, WHITE, argv[1]);
	mlx_mouse_hook(min.win, &mouse_key, &e);
	// mlx_mouse_hook(min.win, &mouse_zoom, &e);
	mlx_hook(min.win, 2, (1L << 0), &pressed_key, &e);
	mlx_hook(min.win, 6, (6L << 0), &mouse_position, &e);
	mlx_loop(min.mlx);
	return (0);
}
