/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 13:45:53 by notraore          #+#    #+#             */
/*   Updated: 2017/09/06 13:45:54 by notraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../toolbox.h"

void		*one_ft_draw(void *e)
{
	m_draw_var_init(e);
	one_calc(e);
	return ((void *)(1));
}

void		*two_ft_draw(void *e)
{
	m_draw_var_init(e);
	two_calc(e);
	return ((void *)(1));
}

void		*three_ft_draw(void *e)
{
	m_draw_var_init(e);
	three_calc(e);
	return ((void *)(1));
}

void		*four_ft_draw(void *e)
{
	m_draw_var_init(e);
	four_calc(e);
	return ((void *)(1));
}

void		*five_ft_draw(void *e)
{
	m_draw_var_init(e);
	five_calc(e);
	return ((void *)(1));
}
