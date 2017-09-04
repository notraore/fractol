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

void		reset_the_one(t_var *e)
{
	e->z = 0;
	e->clr = 0;
	if (ft_strcmp("mandelbrot", e->argv) == 0)
		m_first_init(e);
	else if (ft_strcmp("julia", e->argv) == 0)
		j_first_init(e);
	else if (ft_strcmp("nobila", e->argv) == 0)
		n_first_init(e);
}
void		the_one(t_var *e)
{
	if (ft_strcmp("mandelbrot", e->argv) == 0)
		man_ft_draw(e->tl, e);
	else if (ft_strcmp("julia", e->argv) == 0)
		jul_ft_draw(e->tl, e);
	else if (ft_strcmp("nobila", e->argv) == 0)
		nob_ft_draw(e->tl, e);
	mlx_put_image_to_window(e->tl->mlx, e->tl->win, e->tl->img, 0, 0);
}

void		keyboard_actions(int keycode, t_var *e)
{
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	if (keycode == 15)
		reset_the_one(e);
	if (keycode == 13)
		e->it_max += 1;
	if (keycode == 1)
		e->it_max -= 1;
	if (keycode == 49 && e->mov_flag == 0)
		e->mov_flag = 1;
	else if (keycode == 49 && e->mov_flag == 1)
		e->mov_flag = 0;
	if (keycode == 17)
		e->clr += 0.1;
	if (keycode == 5)
		e->clr -= 0.1;
	// if (keycode == 126)
	// 	e->mov_x += 1;
	// if (keycode == 125)
	// if (keycode == 123)
	// if (keycode == 124)
	the_one(e);
}

int			pressed_key(int keycode, t_var *e)
{
	if (keycode == 53 || keycode == 15 || keycode == 13
	|| keycode == 1 || keycode == 49 || keycode == 17 ||
	keycode == 5 || keycode == 126 || keycode == 12 ||
	keycode == 123 || keycode == 124)
		keyboard_actions(keycode, e);
	return (0);
}

int			mouse_key(int keycode, int x, int y, t_var *e)
{
	(void)x;
	(void)y;
	if (keycode == 4)
	{
		get_mouse_position_in(e);
		the_one(e);
	}
	if (keycode == 5)
	{
		get_mouse_position_out(e);
		the_one(e);
	}
	return (0);
}

int			mouse_position(int x, int y, t_var *e)
{
	if ((x > 0 && x < W) && (y > 0 && y < H))
	{
		e->mouse_x = (double)x / W;//e->image_x;
		e->mouse_y = (double)y / H;//e->image_y;
		e->mod_x = (double)x / W;//e->image_x;
		e->mod_y = (double)y / H;//e->image_y;
	}
	if ((ft_strcmp("julia", e->argv) == 0 ||
	ft_strcmp("nobila", e->argv) == 0) && e->mov_flag == 0)
		the_one(e);
	printf("e flag = %d\n", e->mov_flag);
	return (0);
}
