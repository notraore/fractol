/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_reset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 11:59:41 by notraore          #+#    #+#             */
/*   Updated: 2017/09/05 11:59:42 by notraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../toolbox.h"

void		get_mouse_position_in(t_var *e)
{
	e->diff_y = (e->y2 - e->y1) * 0.2;
	e->diff_x = (e->x2 - e->x1) * 0.2;
	e->y1 = (e->y1 + e->diff_y * e->mod_y);
	e->y2 = (e->y2 - e->diff_y * (1 - e->mod_y));
	e->x1 = (e->x1 + e->diff_x * e->mod_x);
	e->x2 = (e->x2 - e->diff_x * (1 - e->mod_x));
	e->mi += 0.5;
}

void		get_mouse_position_out(t_var *e)
{
	e->diff_y = (e->y2 - e->y1) * 0.2;
	e->diff_x = (e->x2 - e->x1) * 0.2;
	e->y1 = (e->y1 - e->diff_y * e->mod_y);
	e->y2 = (e->y2 + e->diff_y * (1 - e->mod_y));
	e->x1 = (e->x1 - e->diff_x * e->mod_x);
	e->x2 = (e->x2 + e->diff_x * (1 - e->mod_x));
	e->mi -= 0.5;
}

void		reset_the_one(t_var *e)
{
	e->clr = 0;
	if (ft_strcmp("mandelbrot", e->argv) == 0)
		m_first_init(e);
	if (ft_strcmp("julia", e->argv) == 0)
		j_first_init(e);
	else if (ft_strcmp("nobila", e->argv) == 0)
		n_first_init(e);
}

void		the_one(t_var *e)
{
	if (ft_strcmp("mandelbrot", e->argv) == 0)
		ft_pthread(e, man_ft_draw);
	else if (ft_strcmp("julia", e->argv) == 0)
		ft_pthread(e, jul_ft_draw);
	else if (ft_strcmp("nobila", e->argv) == 0)
		ft_pthread(e, nob_ft_draw);
}
