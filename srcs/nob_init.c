/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nob_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 19:29:44 by notraore          #+#    #+#             */
/*   Updated: 2017/09/02 19:29:45 by notraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../toolbox.h"

void		n_draw_var_init(t_var *e)
{
	e->x = 0;
	e->y = 0;
	e->zoom_x = W / (e->x2 - e->x1) + e->z + e->mod_x;
	e->zoom_y = H / (e->y2 - e->y1) + e->z + e->mod_y;
}

void		n_var_reset(t_var *e)
{
	if (e->mov_flag == 0)
	{
		e->c_r = e->x / + e->zoom_x + e->mouse_y;
		e->c_i = e->y / + e->zoom_y + e->mouse_x;
	}
	e->z_r = .2;
	e->z_i = 0.2;
	e->i = 0;
}

void		n_first_init(t_var *e)
{
	e->y1 = -1.2;
	e->y2 = 1.2;
	e->x1 = -1;
	e->x2 = 1;
	e->it_max = 50;
}
