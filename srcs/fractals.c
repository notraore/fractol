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

void		*man_ft_draw(void *e)
{
	m_draw_var_init(e);
	man_calc(e);
	return ((void *)(1));
}

void		*jul_ft_draw(void *e)
{
	m_draw_var_init(e);
	jul_calc(e);
	return ((void *)(1));
}

void		*nob_ft_draw(void *e)
{
	m_draw_var_init(e);
	nob_calc(e);
	return ((void *)(1));
}
