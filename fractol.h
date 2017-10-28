/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaziuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 13:26:15 by mpaziuk           #+#    #+#             */
/*   Updated: 2017/02/23 13:26:16 by mpaziuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <unistd.h>
# include <pthread.h>
# include "minilibx/mlx.h"
# include "libft/libft.h"

# define THREAD 200

typedef struct s_complex	t_complex;
struct						s_complex
{
	double					r;
	double					im;
};

typedef struct s_env		t_env;
struct						s_env
{
	void					*mlx;
	void					*win;
	void					*img;
	int						wd;
	int						ht;
	double					z;
	double					mx;
	double					my;
	int						iter;
	t_complex				con;
	int						inter;
};

typedef struct s_param		t_param;
struct						s_param
{
	t_env					*e;
	int						y_min;
	int						y_max;
	int						x;
};

void						*ft_draw(void *args);
void						mlx_img_clear(t_env *e);
int							ft_ext_r(int clr);
int							ft_ext_g(int clr);
int							ft_ext_b(int clr);
void						mlx_pixput(t_env *e, int x, int y, int color);
void						mlx_img_clear(t_env *e);
void						*ft_draw(void *args);
int							draw_mandel(t_env *e);
int							draw_julia(t_env *e);
void						*ft_jdraw(void *args);
void						*ft_sdraw(void *args);
int							draw_ship(t_env *e);
int							my_key_func(int key_code, t_env *e);
int							mouse_move(int x, int y, t_env *e);
int							mouse_hook(int button, int x, int y, t_env *e);

#endif
