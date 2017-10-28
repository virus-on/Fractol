/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaziuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 15:22:01 by mpaziuk           #+#    #+#             */
/*   Updated: 2017/02/27 15:22:03 by mpaziuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

inline static void	jcalc(t_param *p, t_complex *z, t_complex *c)
{
	register int	i;

	i = -1;
	while (++i < p->e->iter)
	{
		z->r = c->r;
		z->im = c->im;
		c->r = z->r * z->r - z->im * z->im + p->e->con.r;
		c->im = 2.0 * z->r * z->im + p->e->con.im;
		if ((z->r * z->r + z->im * z->im) > 4.0)
			break ;
	}
	if (i == p->e->iter)
		mlx_pixput(p->e, p->x, p->y_min, 0x00ffffff);
	else if (i < p->e->iter / 2)
		mlx_pixput(p->e, p->x, p->y_min, 0xff * i / p->e->iter * 5);
	else
		mlx_pixput(p->e, p->x, p->y_min, 0xff * i / p->e->iter);
}

void				*ft_jdraw(void *args)
{
	t_complex		z;
	t_complex		c;
	register int	x;
	t_param			*p;

	p = (t_param*)args;
	while (p->y_min != p->y_max)
	{
		x = -1;
		while (++x < p->e->wd)
		{
			p->x = x;
			z.r = 0;
			z.im = 0;
			c.r = 1.5 * (x - p->e->wd / 2) / (0.5 * p->e->z * p->e->wd);
			c.r += p->e->mx;
			c.im = (p->y_min - p->e->ht / 2) / (0.5 * p->e->z * p->e->ht);
			c.im += p->e->my;
			jcalc(p, &z, &c);
		}
		p->y_min += 1;
	}
	pthread_exit(NULL);
}

int					draw_julia(t_env *e)
{
	pthread_t	threads[THREAD];
	t_param		params[THREAD];
	int			i;

	mlx_img_clear(e);
	i = -1;
	while (++i < THREAD)
	{
		params[i].e = e;
		params[i].y_min = e->ht / THREAD * i;
		params[i].y_max = e->ht / THREAD * (i + 1);
		pthread_create(threads + i, NULL, ft_jdraw, &(params[i]));
	}
	i = -1;
	while (++i < THREAD)
		pthread_join(threads[i], NULL);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}
