/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 13:45:47 by notraore          #+#    #+#             */
/*   Updated: 2017/09/06 13:45:48 by notraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../toolbox.h"

void		one_calc(t_var *e)
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
				e->z_i = e->z_i * e->tmp * -2.0 + e->c_i;
				e->i = e->i + 1;
			}
			if ((e->i == e->mi) && (e->x > 0 && e->x < W) &&
			(e->y > 0 && e->y < H))
				e->tl->dta[e->x + e->y * H] = HL;
			else if ((e->x > 0 && e->x < W) && (e->y > 0 && e->y < H))
				e->tl->dta[e->x + e->y * H] = e->i * B / (e->clr + e->mi) + 1;
			e->y += 1;
		}
		e->x += 1;
	}
}

void		two_calc(t_var *e)
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
				e->z_i = fabs(e->tmp * e->z_i) * -2.0 + e->c_i;
				e->i = e->i + 1;
			}
			if ((e->i == e->mi) && (e->x > 0 && e->x < W) &&
			(e->y > 0 && e->y < H))
				e->tl->dta[e->x + e->y * H] = BLACK;
			else if ((e->x > 0 && e->x < W) && (e->y > 0 && e->y < H))
				e->tl->dta[e->x + e->y * H] = e->i * HL / (e->clr + e->mi) + 1;
			e->y += 1;
		}
		e->x += 1;
	}
}

void		three_calc(t_var *e)
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
				e->z_r = fabs(e->z_r * e->z_r - e->z_i * e->z_i) + e->c_r;
				e->z_i = 2 * e->z_i * e->tmp + e->c_i;
				e->i = e->i + 1;
			}
			if ((e->i == e->mi) && (e->x > 0 && e->x < W) &&
			(e->y > 0 && e->y < H))
				e->tl->dta[e->x + e->y * H] = YELLOW;
			else if ((e->x > 0 && e->x < W) && (e->y > 0 && e->y < H))
				e->tl->dta[e->x + e->y * H] = e->i * RO / (e->clr + e->mi) + 1;
			e->y += 1;
		}
		e->x += 1;
	}
}

void		four_calc(t_var *e)
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
				e->z_r = (e->z_r * e->z_r - e->z_i * e->z_i) + e->c_r;
				e->z_i = fabs(e->tmp) * e->z_i * 2.0 + e->c_i;
				e->i = e->i + 1;
			}
			if ((e->i == e->mi) && (e->x > 0 && e->x < W) &&
			(e->y > 0 && e->y < H))
				e->tl->dta[e->x + e->y * H] = MAUVE;
			else if ((e->x > 0 && e->x < W) && (e->y > 0 && e->y < H))
				e->tl->dta[e->x + e->y * H] = e->i * RO / (e->clr + e->mi) + 1;
			e->y += 1;
		}
		e->x += 1;
	}
}

void		five_calc(t_var *e)
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
				e->tmp2 = e->z_r * e->z_r;
				e->tmp = e->z_r;
				e->z_r = -(e->tmp2 - (e->z_i * e->z_i) * 3.0) + e->tmp + e->c_r;
				e->z_i = (2 * e->z_r - (2 * e->z_r * 3.0)) * e->z_i + e->c_i;
				e->i = e->i + 1;
			}
			if ((e->i == e->mi) && (e->x > 0 && e->x < W) &&
			(e->y > 0 && e->y < H))
				e->tl->dta[e->x + e->y * H] = BLACK;
			else if ((e->x > 0 && e->x < W) && (e->y > 0 && e->y < H))
				e->tl->dta[e->x + e->y * H] = e->i * RED / (e->clr + e->mi) + 1;
			e->y += 1;
		}
		e->x += 1;
	}
}
