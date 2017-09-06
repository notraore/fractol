/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 20:42:23 by notraore          #+#    #+#             */
/*   Updated: 2017/09/06 15:44:47 by notraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __TOOLBOX_H
# define __TOOLBOX_H

# include <pthread.h>
# include "./libft/libft.h"
# include "./minilibx/mlx.h"

# define W 800
# define H 800
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GREEN 0x00FF00
# define B 0x0000FF
# define YELLOW 0xFFFF00
# define BLACK 0x000000
# define MAUVE 0xFF00FF
# define RO 0xFFC0CB
# define HL 0xEE4848
# define MINE 0x13879C

typedef struct s_var	t_var;
typedef struct s_mlx	t_mlx;

struct					s_var
{
	int					i;
	int					x;
	int					y;
	int					mov_flag;
	char				*argv;
	int					start;
	int					end;
	int					hide;
	double				clr;
	double				mi;
	double				diff_x;
	double				diff_y;
	double				mouse_x;
	double				mouse_y;
	double				tmp;
	double				tmp2;
	double				x1;
	double				x2;
	double				y1;
	double				y2;
	double				zoom_x;
	double				zoom_y;
	double				c_r;
	double				c_i;
	double				z_r;
	double				z_i;
	double				mod_x;
	double				mod_y;
	t_mlx				*tl;
};

struct					s_mlx
{
	int					sl;
	int					end;
	int					bpp;
	int					*dta;
	void				*mlx;
	void				*win;
	void				*img;
	t_var				e;
};

/*
**key_input.c
*/
int						pressed_key(int keycode, t_var *e);
int						mouse_position(int x, int y, t_var *e);
int						mouse_key(int keycode, int x, int y, t_var *e);

/*
**man_init
*/
void					m_draw_var_init(t_var *e);
void					m_var_reset(t_var *e);
void					m_first_init(t_var *e);

/*
**jul_init
*/
void					j_draw_var_init(t_var *e);
void					j_var_reset(t_var *e);
void					j_first_init(t_var *e);

/*
**nob_init
*/
void					n_draw_var_init(t_var *e);
void					n_var_reset(t_var *e);
void					n_first_init(t_var *e);

/*
**error.c
*/
void					ft_help(void);
void					ft_print_err(int argc);
int						check_argv(char *argv);
void					show_input(void);

/*
**fractals.c
*/
void					*man_ft_draw(void *e);
void					*jul_ft_draw(void *e);
void					*nob_ft_draw(void *e);

/*
**multithread.c
*/
void					ft_pthread(t_var *data, void *(*f)(void *param));

/*
**mouse_reset.c
*/
void					get_mouse_position_in(t_var *e);
void					get_mouse_position_out(t_var *e);
void					the_one(t_var *e);
void					reset_the_one(t_var *e);

/*
**fractals_calc.c
*/
void					man_calc(t_var *e);
void					jul_calc(t_var *e);
void					nob_calc(t_var *e);

/*
**main.c
*/
void					display_info(t_var *e, char *argv);

/*
**bonus_1.c
*/

void					one_calc(t_var *e);
void					two_calc(t_var *e);
void					three_calc(t_var *e);
void					four_calc(t_var *e);
void					five_calc(t_var *e);
/*
**bonus_2.c
*/

void					*one_ft_draw(void *e);
void					*two_ft_draw(void *e);
void					*three_ft_draw(void *e);
void					*four_ft_draw(void *e);
void					*five_ft_draw(void *e);

#endif
