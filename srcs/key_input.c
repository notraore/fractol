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
	man_ft_draw(env->tl, env);
	mlx_put_image_to_window(env->tl->mlx, env->tl->win, env->tl->img, 0, 0);
}

void	get_mouse_position_in(t_var *e)
{
	e->diff_y = (e->y2 - e->y1) * 0.1;
	e->diff_x = (e->x2 - e->x1) * 0.1;
	e->y1 = (e->y1 + e->diff_y * e->mod_y);
	e->y2 = (e->y2 - e->diff_y * (1 - e->mod_y));
	e->x1 = (e->x1 + e->diff_x * e->mod_x);
	e->x2 = (e->x2 - e->diff_x * (1 - e->mod_x));
}

void	get_mouse_position_out(t_var *e)
{
	e->diff_y = (e->y2 - e->y1) * 0.1;
	e->diff_x = (e->x2 - e->x1) * 0.1;
	e->y1 = (e->y1 - e->diff_y * e->mod_y);
	e->y2 = (e->y2 + e->diff_y * (1 - e->mod_y));
	e->x1 = (e->x1 - e->diff_x * e->mod_x);
	e->x2 = (e->x2 + e->diff_x * (1 - e->mod_x));
}

void		reset_all(t_var *e)
{
	e->y1 = -1.2;
	e->y2 = 1.2;
	e->x1 = -2.1;
	e->x2 = 0.6;
	e->it_max = 50;
	e->z = 0;
}

int		pressed_key(int keycode, t_var *e)
{
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	if (keycode == 69)
	{
		get_mouse_position_in(e);
		// e->diff_y = (e->y2 - e->y1) * 0.1;
		// e->diff_x = (e->x2 - e->x1) * 0.1;
		// printf("x = %f || y = %f || mod_x = %f || mod_y = %f\n",
		// e->mouse_x, e->mouse_y, e->mod_x, e->mod_y);
		// e->y1 = (e->y1 + e->diff_y * e->mod_y);
		// e->y2 = (e->y2 - e->diff_y * (1 - e->mod_y));
		// e->x1 = (e->x1 + e->diff_x * e->mod_x);
		// e->x2 = (e->x2 - e->diff_x * (1 - e->mod_x));
		// printf("diff = %f\n", e->diff);
		// printf("y1 = %f, new_y1 = %f\n", e->y1, (e->y1 + e->diff_y * e->mod_y));
		// printf("y2 = %f, new_y2 = %f\n", e->y2, (e->y2 - e->diff_y * (1 - e->mod_y)));
		// printf("x1 = %f, new_x1 = %f\n", e->x1, (e->x1 + e->diff_x * e->mod_x));
		// printf("x2 = %f, new_x2 = %f\n", e->x2, (e->x2 - e->diff_x * (1 - e->mod_x)));
		// printf("after :\n y1 = %f, y2 = %f\n", e->y1, e->y2);
		e->z += 10;
		e->it_max += 0.5;
		// e->mouse_y += 5;
	}
	if (keycode == 78)
	{
		get_mouse_position_out(e);
		// e->diff_y = (e->y2 - e->y1) * 0.1;
		// e->diff_x = (e->x2 - e->x1) * 0.1;
		// e->y1 = (e->y1 - e->diff_y * e->mod_y);
		// e->y2 = (e->y2 + e->diff_y * (1 - e->mod_y));
		// e->x1 = (e->x1 - e->diff_x * e->mod_x);
		// e->x2 = (e->x2 + e->diff_x * (1 - e->mod_x));
		e->z -= 10;
		e->it_max -= 0.5;
	}
	if (keycode == 15)
		reset_all(e);
	man_ft_draw(e->tl, e);
	mlx_put_image_to_window(e->tl->mlx, e->tl->win, e->tl->img, 0, 0);
	// printf("keycode == %d\n", keycode);
	return (0);
}

int		mouse_position(int x, int y, t_var *e)
{
	if ((x > 0 && x < W) && (y > 0 && y < H))
	{
		e->mouse_x = (double)x / W;
		e->mouse_y = (double)y / H;
		e->mod_x = (double)x / W;
		e->mod_y = (double)y / H;
		// printf("x = %f || y = %f || mod_x = %f || mod_y = %f\n",
		// e->mouse_x, e->mouse_y, e->mod_x, e->mod_y);
		// printf("diff = %f\n", e->diff);
		// printf("y1 = %f, new_y1 = %f\n", e->y1, (e->y1 + e->diff * e->mod_y));
		// printf("y2 = %f, minus2 = %f, new_y2 = %f\n", e->y2, e->diff * (1 - e->mod_y), (e->y2 - e->diff * (1 - e->mod_y)));
		// man_ft_draw(e->tl, e);
		// mlx_put_image_to_window(e->tl->mlx, e->tl->win, e->tl->img, 0, 0);
	}
	return (0);
}

int		mouse_key(int keycode, int x, int y, t_var *e)
{
	(void)x;
	(void)y;
	(void)e;
	printf("keycode == %d\n", keycode);
	// if (keycode == 1 || keycode == 4)
	// 	e->z += 1;
	// if (keycode == 2 || keycode == 5)
	// 	e->mouse_x -= 1;
	// man_ft_draw(e->tl, e);
	// mlx_put_image_to_window(e->tl->mlx, e->tl->win, e->tl->img, 0, 0);
	return (0);
}