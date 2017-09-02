/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 18:17:51 by notraore          #+#    #+#             */
/*   Updated: 2017/07/08 18:17:54 by notraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../toolbox.h"

void		get_mouse_position_in(t_var *e)
{
	e->diff_y = (e->y2 - e->y1) * 0.1;
	e->diff_x = (e->x2 - e->x1) * 0.1;
	e->y1 = (e->y1 + e->diff_y * e->mod_y);
	e->y2 = (e->y2 - e->diff_y * (1 - e->mod_y));
	e->x1 = (e->x1 + e->diff_x * e->mod_x);
	e->x2 = (e->x2 - e->diff_x * (1 - e->mod_x));
	e->z += 5;
	e->it_max += 0.5;
}

void		get_mouse_position_out(t_var *e)
{
	e->diff_y = (e->y2 - e->y1) * 0.1;
	e->diff_x = (e->x2 - e->x1) * 0.1;
	e->y1 = (e->y1 - e->diff_y * e->mod_y);
	e->y2 = (e->y2 + e->diff_y * (1 - e->mod_y));
	e->x1 = (e->x1 - e->diff_x * e->mod_x);
	e->x2 = (e->x2 + e->diff_x * (1 - e->mod_x));
	e->z -= 5;
	e->it_max -= 0.5;
}

void		reset_all(t_var *e)
{
	e->y1 = -1.2;
	e->y2 = 1.2;
	e->x1 = -2.1;
	e->x2 = 0.6;
	e->it_max = 50;
	e->z = 0;
}

int			pressed_key(int keycode, t_var *e)
{
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	if (keycode == 69)
		get_mouse_position_in(e);
	if (keycode == 78)
		get_mouse_position_out(e);
	if (keycode == 15)
		reset_all(e);
	if (keycode == 15)
		e->it_max += 1;
	if (keycode == 1)
		e->it_max -= 1;
	man_ft_draw(e->tl, e);
	mlx_put_image_to_window(e->tl->mlx, e->tl->win, e->tl->img, 0, 0);
	return (0);
}

int			mouse_position(int x, int y, t_var *e)
{
	if ((x > 0 && x < W) && (y > 0 && y < H))
	{
		e->mouse_x = (double)x / W;
		e->mouse_y = (double)y / H;
		e->mod_x = (double)x / W;
		e->mod_y = (double)y / H;
	}
	//Modifier les parametre avec mouse_x et mouse_y sur la fractae julia
	// man_ft_draw(e->tl, e);
	// mlx_put_image_to_window(e->tl->mlx, e->tl->win, e->tl->img, 0, 0);
	return (0);
}
