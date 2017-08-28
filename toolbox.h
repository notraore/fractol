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

# define W 400
# define H 400
# define LEN 2
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GREEN 0x21610B
# define BLUE 0x0000FF
# define YELLOW 0xFFFF00
# define BLACK 0x000000

typedef struct		s_mlx
{
	int				sl;
	int				end;
	int				bpp;
	int				*dta;
	void			*mlx;
	void			*win;
	void			*img;
}					t_mlx;

typedef struct		s_var
{
	int				i;
	int				x;
	int				y;
	int				it_max;
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
}					t_var;

int					pressed_key(int keycode);
void				ft_print_err(int argc);

#endif
