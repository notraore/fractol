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

void		reset_xy(t_var *e)
{
	e->mouse_x = 0;
	e->mouse_y = 0;
}

void		keyboard_actions(int keycode, t_var *e)
{
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	if (keycode == 15)
		reset_the_one(e);
	if (keycode == 13)
		e->mi += 1;
	if (keycode == 1)
		e->mi -= 1;
	if (keycode == 49)
		e->mov_flag = (e->mov_flag == 1) ? 0 : 1;
	if (keycode == 17)
		e->clr += 0.1;
	if (keycode == 5)
		e->clr -= 0.1;
	if (keycode == 4)
		e->hide = (e->hide == 1) ? 0 : 1;
	if (keycode == 34)
		reset_xy(e);
	the_one(e);
}

int			pressed_key(int keycode, t_var *e)
{
	if (keycode == 53 || keycode == 15 || keycode == 13
	|| keycode == 1 || keycode == 49 || keycode == 17 ||
	keycode == 5 || keycode == 12 || keycode == 4 || keycode == 34)
		keyboard_actions(keycode, e);
	return (0);
}

int			mouse_key(int keycode, int x, int y, t_var *e)
{
	(void)x;
	(void)y;
	if (keycode == 4)
		get_mouse_position_in(e);
	if (keycode == 5)
		get_mouse_position_out(e);
	the_one(e);
	return (0);
}

int			mouse_position(int x, int y, t_var *e)
{
	e->mod_x = (double)x / W;
	e->mod_y = (double)y / H;
	if ((ft_strcmp("julia", e->argv) == 0 ||
	ft_strcmp("nobila", e->argv) == 0 ||
	ft_strcmp("mandelbrot", e->argv) == 0) && e->mov_flag == 1)
	{
		e->mouse_x = (double)x / W;
		e->mouse_y = (double)y / H;
	}
	if (e->mov_flag == 1)
		the_one(e);
	return (0);
}
