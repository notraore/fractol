/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 19:29:44 by notraore          #+#    #+#             */
/*   Updated: 2017/09/02 19:29:45 by notraore         ###   ########.fr       */
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
				min->dta[e->x + e->y * H] = e->i * GAY / (e->clr + e->it_max) + 1;
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
				min->dta[e->x + e->y * H] = e->i * GAY / (e->clr + e->it_max) + 1;
			e->y += 1;
		}
		e->x += 1;
	}
}

void		nob_ft_draw(t_mlx *min, t_var *e)
{
	n_draw_var_init(e);
	while (e->x < W)
	{
		e->y = 0;
		while (e->y < H)
		{
			n_var_reset(e);
			while (e->z_r * e->z_r + e->z_i * e->z_i < 4 && e->i < e->it_max)
			{
				e->tmp = e->z_r;
				e->z_r = e->z_r * e->z_r - e->z_i * e->z_i + e->c_r;
				e->z_i = 2 * e->z_i * e->tmp + e->c_i;
				e->i = e->i + 1;
			}
			if ((e->i == e->it_max) && (e->x > 0 && e->x < W) &&
			(e->y > 0 && e->y < H))
				min->dta[e->x + e->y * H] = BLACK;
			else if ((e->x > 0 && e->x < W) && (e->y > 0 && e->y < H))
				min->dta[e->x + e->y * H] = e->i * BLUE / (e->clr + e->it_max) + 1;
			e->y += 1;
		}
		e->x += 1;
	}
}