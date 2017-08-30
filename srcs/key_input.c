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
	printf("keycode == %d\n", keycode);
	return (0);
}

int		mouse_zoom(int keycode, int x, int y, t_var *e)
{
	// (void)x;
	// (void)y;
	// (void)e;
	(void)keycode;
	// if (keycode == 4 || keycode == 5)
	// {
		e->x1 = x / (W / 2 - x) + W / 2;
		e->y1 = y / (W / 2 - y) + W / 2;
	// }
	return (0);
}

int		mouse_position(int x, int y, t_var *e)
{
	(void)e;
	if ((x > 0 && x < W) && (y > 0 && y < H))
	{
		printf("x = %d || y = %d\n", x, y);
	}
	return (0);
}

int		mouse_key(int keycode, int x, int y, t_var *e)
{
	// (void)x;
	// (void)y;
	// (void)e;
	printf("keycode == %d\n", keycode);
	if (keycode == 1)
		mouse_zoom(keycode, x, y, e);
	if (keycode == 2)
		e->z -= 1;
	ft_draw(e->tl, e);
	mlx_put_image_to_window(e->tl->mlx, e->tl->win, e->tl->img, 0, 0);
	return (0);
}