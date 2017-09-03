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

void		man_ft_draw(t_mlx *min, t_var *e)
{
	m_draw_var_init(e);
	while (e->x < W)
	{
		e->y = 0;
		while (e->y < H)
		{
			m_var_reset(e);
			while (e->z_r * e->z_r + e->z_i * e->z_i < 4 && e->i < e->it_max)
			{
				e->tmp = e->z_r;
				e->z_r = e->z_r * e->z_r - e->z_i * e->z_i + e->c_r;
				e->z_i = 2 * e->z_i * e->tmp + e->c_i;
				e->i = e->i + 1;
			}
			if ((e->i == e->it_max) && (e->x > 0 && e->x < W) &&
			(e->y > 0 && e->y < H))
				min->dta[e->x + e->y * H] = MAUVE;
			else if ((e->x > 0 && e->x < W) && (e->y > 0 && e->y < H))
				min->dta[e->x + e->y * H] = e->i * GAY / e->it_max + 1;
			e->y += 1;
		}
		e->x += 1;
	}
}

void		jul_ft_draw(t_mlx *min, t_var *e)
{
	j_draw_var_init(e);
	while (e->x < W)
	{
		e->y = 0;
		while (e->y < H)
		{
			j_var_reset(e);
			while (e->z_r * e->z_r + e->z_i * e->z_i < 4 && e->i < e->it_max)
			{
				e->tmp = e->z_r;
				e->z_r = e->z_r * e->z_r - e->z_i * e->z_i + e->c_r;
				e->z_i = 2 * e->z_i * e->tmp + e->c_i;
				e->i = e->i + 1;
			}
			if ((e->i == e->it_max) && (e->x > 0 && e->x < W) &&
			(e->y > 0 && e->y < H))
				min->dta[e->x + e->y * H] = BLUE;
			else if ((e->x > 0 && e->x < W) && (e->y > 0 && e->y < H))
				min->dta[e->x + e->y * H] = e->i * GAY / e->it_max + 1;
			e->y += 1;
		}
		e->x += 1;
	}
}

void		display_frarg(t_mlx *min, t_var *e, char *argv)
{
	if (ft_strcmp("maldelbrot", argv) == 0)
	{
		m_first_init(e);
		man_ft_draw(min, e);
	}
	if (ft_strcmp("julia", argv) == 0)
	{
		j_first_init(e);
		jul_ft_draw(min, e);
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
	display_frarg(&min, &e, argv[1]);
	mlx_put_image_to_window(min.mlx, min.win, min.img, 0, 0);
	mlx_string_put(min.mlx, min.win, 15, 15, WHITE, argv[1]);
	e.tl = &min;
	e.argv = argv[1];
	printf("%s\n", e.argv);
	mlx_hook(min.win, 2, (1L << 0), &pressed_key, &e);
	mlx_hook(min.win, 6, (6L << 0), &mouse_position, &e);
	mlx_loop(min.mlx);
	return (0);
}
