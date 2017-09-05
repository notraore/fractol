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

void		keyboard_actions(int keycode, t_var *e)
{
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	if (keycode == 15)
		reset_the_one(e);
	if (keycode == 13)
		e->imax += 1;
	if (keycode == 1)
		e->imax -= 1;
	if (keycode == 49 && e->mov_flag == 0)
		e->mov_flag = 1;
	else if (keycode == 49 && e->mov_flag == 1)
		e->mov_flag = 0;
	if (keycode == 17)
		e->clr += 0.1;
	if (keycode == 5)
		e->clr -= 0.1;
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
	e->mouse_x = (double)x / W;
	e->mouse_y = (double)y / H;
	e->mod_x = (double)x / W;
	e->mod_y = (double)y / H;
	if ((ft_strcmp("julia", e->argv) == 0 ||
	ft_strcmp("nobila", e->argv) == 0) && e->mov_flag == 0)
		the_one(e);
	return (0);
}
