/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_calc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 17:50:21 by notraore          #+#    #+#             */
/*   Updated: 2017/09/05 17:50:22 by notraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../toolbox.h"

void		man_calc(t_var *e)
{
	e->x += e->start;
	while (e->x < e->end)
	{
		e->y = 0;
		while (e->y < H)
		{
			m_var_reset(e);
			while (e->z_r * e->z_r + e->z_i * e->z_i < 4 && e->i < e->mi)
			{
				e->tmp = e->z_r;
				e->z_r = e->z_r * e->z_r - e->z_i * e->z_i + e->c_r;
				e->z_i = 2 * e->z_i * e->tmp + e->c_i;
				e->i = e->i + 1;
			}
			if ((e->i == e->mi) && (e->x > 0 && e->x < W) &&
			(e->y > 0 && e->y < H))
				e->tl->dta[e->x + e->y * H] = BLACK;
			else if ((e->x > 0 && e->x < W) && (e->y > 0 && e->y < H))
				e->tl->dta[e->x + e->y * H] = e->i * RO / (e->clr + e->mi) + 1;
			e->y += 1;
		}
		e->x += 1;
	}
}

void		jul_calc(t_var *e)
{
	e->x += e->start;
	while (e->x < e->end)
	{
		e->y = 0;
		while (e->y < H)
		{
			j_var_reset(e);
			while (e->z_r * e->z_r + e->z_i * e->z_i < 4 && e->i < e->mi)
			{
				e->tmp = e->z_r;
				e->z_r = e->z_r * e->z_r - e->z_i * e->z_i + e->c_r;
				e->z_i = 2 * e->z_i * e->tmp + e->c_i;
				e->i = e->i + 1;
			}
			if ((e->i == e->mi) && (e->x > 0 && e->x < W) &&
			(e->y > 0 && e->y < H))
				e->tl->dta[e->x + e->y * H] = YELLOW;
			else if ((e->x > 0 && e->x < W) && (e->y > 0 && e->y < H))
				e->tl->dta[e->x + e->y * H] = e->i * RED / (e->clr + e->mi) + 1;
			e->y += 1;
		}
		e->x += 1;
	}
}

void		nob_calc(t_var *e)
{
	e->x = e->start;
	while (e->x < e->end)
	{
		e->y = 0;
		while (e->y < H)
		{
			n_var_reset(e);
			while (e->z_r * e->z_r + e->z_i * e->z_i < 4 && e->i < e->mi)
			{
				e->tmp = e->z_r;
				e->z_r = e->z_r * e->z_r - e->z_i * e->z_i + e->c_r;
				e->z_i = fabs(e->tmp) * e->z_i * -2.0 + e->c_i;
				e->i = e->i + 1;
			}
			if ((e->i == e->mi) && (e->x > 0 && e->x < W) &&
			(e->y > 0 && e->y < H))
				e->tl->dta[e->x + e->y * H] = MINE;
			else if ((e->x > 0 && e->x < W) && (e->y > 0 && e->y < H))
				e->tl->dta[e->x + e->y * H] = e->i * B / (e->clr + e->mi) + 1;
			e->y += 1;
		}
		e->x += 1;
	}
}
