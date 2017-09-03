/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jul_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 19:29:44 by notraore          #+#    #+#             */
/*   Updated: 2017/09/02 19:29:45 by notraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../toolbox.h"

void		j_draw_var_init(t_var *e)
{
	e->x = 0;
	e->y = 0;
	e->zoom_x = W / (e->x2 - e->x1) + e->z + e->mod_x;
	e->zoom_y = H / (e->y2 - e->y1) + e->z + e->mod_y;
}

void		j_var_reset(t_var *e)
{
	e->c_r = 0.285 + e->mouse_x / 2;// + e->mod_x;//e->x / e->zoom_x + e->x1;
	e->c_i = 0.01 + e->mouse_y / 2;// + e->mod_y;
	e->z_r = e->x / e->zoom_x + e->x1;// + e->mouse_x;
	e->z_i = e->y / e->zoom_y + e->y1;// + e->mouse_y;
	e->i = 0;
}

void		j_first_init(t_var *e)
{
	e->y1 = -1.2;
	e->y2 = 1.2;
	e->x1 = -1;
	e->x2 = 1;
	e->it_max = 150;
}
