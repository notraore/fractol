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

void	clear_and_reput(t_var *env)
{
	ft_draw(env->tl, env);
	mlx_put_image_to_window(env->tl->mlx, env->tl->win, env->tl->img, 0, 0);
}

int		pressed_key(int keycode, t_var *e)
{
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	if (keycode == 69)
	{
		e->z += 2;
		e->z += 2;
		ft_draw(e->tl, e);
		mlx_put_image_to_window(e->tl->mlx, e->tl->win, e->tl->img, 0, 0);
	}
	if (keycode == 78)
	{
		e->z -= 2;
		e->z -= 2;
		ft_draw(e->tl, e);
		mlx_put_image_to_window(e->tl->mlx, e->tl->win, e->tl->img, 0, 0);
	}
	return (0);
}

int		mouse_zoom()
{
	= (W / 2 - x) / W / 2;
	return (0);
}

int		mouse_position(int x, int y, t_var *e)
{
	if ((x > 0 && x < W) && (y > 0 && y < H))
	{
		e->x1 = x / W;
		e->y1 = y / H;
		ft_draw(e->tl, e);
		mlx_put_image_to_window(e->tl->mlx, e->tl->win, e->tl->img, 0, 0);
	}
	return (0);
}

int		mouse_key(int keycode, int x, int y, t_var *e)
{
	(void)x;
	(void)y;
	(void)e;
	if (keycode == 4)
		e->z += 1;
	if (keycode == 5)
		e->z -= 1;
	ft_draw(e->tl, e);
	mlx_put_image_to_window(e->tl->mlx, e->tl->win, e->tl->img, 0, 0);
	return (0);
}