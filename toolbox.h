/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 20:42:23 by notraore          #+#    #+#             */
/*   Updated: 2017/07/08 20:42:26 by notraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __TOOLBOX_H
# define __TOOLBOX_H

# include "./libft/libft.h"
# include "./minilibx/mlx.h"

# define W 1000
# define H 1000
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define YELLOW 0xFFFF00
# define BLACK 0x000000
# define MAUVE 0xFF00FF

typedef struct s_var	t_var;
typedef struct s_mlx	t_mlx;

struct				s_var
{
	int				i;
	int				x;
	int				y;
	int				it_max;
	double			z;
	double			tmp;
	double			x1;
	double			x2;
	double			y1;
	double			y2;
	double			zoom_x;
	double			zoom_y;
	double			c_r;
	double			c_i;
	double			z_r;
	double			z_i;
	t_mlx			*tl;
};

struct				s_mlx
{
	int				sl;
	int				end;
	int				bpp;
	int				*dta;
	void			*mlx;
	void			*win;
	void			*img;
	t_var			e;
};

int					pressed_key(int keycode, t_var *e);
void				ft_print_err(int argc);
void				ft_draw(t_mlx *tl, t_var *e);
int					mouse_position(int x, int y, t_var *e);
int					mouse_key(int keycde, int x, int y, t_var *e);

#endif
