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

# include <pthread.h>
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
# define GAY 0xFFC0CB

typedef struct s_var	t_var;
typedef struct s_mlx	t_mlx;

struct				s_var
{
	int				i;
	int				x;
	int				y;
	int				mov_flag;
	char			*argv;
	int				image_x;
	int				image_y;
	double			mov_x;
	double			mov_y;
	double			clr;
	double			it_max;
	double			diff_x;
	double			diff_y;
	double			new_1;
	double			new_2;
	double			z;
	double			mouse_x;
	double			mouse_y;
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
	double			mod_x;
	double			mod_y;
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

/*
**key_input.c
*/
int					pressed_key(int keycode, t_var *e);
int					mouse_position(int x, int y, t_var *e);
int					mouse_key(int keycode, int x, int y, t_var *e);

/*
**man_init
*/
void				m_draw_var_init(t_var *e);
void				m_var_reset(t_var *e);
void				m_first_init(t_var *e);

/*
**jul_init
*/
void				j_draw_var_init(t_var *e);
void				j_var_reset(t_var *e);
void				j_first_init(t_var *e);

/*
**nob_init
*/
void				n_draw_var_init(t_var *e);
void				n_var_reset(t_var *e);
void				n_first_init(t_var *e);
/*
**main.c
*/
void				man_ft_draw(t_mlx *tl, t_var *e);
void				jul_ft_draw(t_mlx *tl, t_var *e);

/*
**error.c
*/
void				ft_help(void);
void				ft_print_err(int argc);
int					check_argv(char *argv);

/*
**fractals.c
*/
void				man_ft_draw(t_mlx *min, t_var *e);
void				jul_ft_draw(t_mlx *min, t_var *e);
void				nob_ft_draw(t_mlx *min, t_var *e);


#endif
