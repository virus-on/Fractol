/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaziuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 16:35:52 by mpaziuk           #+#    #+#             */
/*   Updated: 2017/03/03 16:35:57 by mpaziuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		my_key_func(int key_code, t_env *e)
{
	if (key_code == 53)
	{
		ft_putendl("Exit!");
		exit(0);
	}
	if (key_code == 125)
		e->my -= 0.05 / e->z;
	if (key_code == 126)
		e->my += 0.05 / e->z;
	if (key_code == 123)
		e->mx += 0.05 / e->z;
	if (key_code == 124)
		e->mx -= 0.1 / e->z;
	if (key_code == 24)
		e->z *= 2;
	if (key_code == 27 && e->z > 0.2)
		e->z /= 2;
	if (key_code == 14 && e->iter < 2000)
		e->iter += 10;
	if (key_code == 12 && e->iter > 15)
		e->iter -= 10;
	if (key_code == 8)
		e->inter = !e->inter;
	return (0);
}

int		mouse_move(int x, int y, t_env *e)
{
	if (e->inter)
	{
		e->con.r = 1.5 * (x - e->wd / 2) / (0.5 * e->wd * e->z) + e->mx;
		e->con.im = (y - e->ht / 2) / (0.5 * e->ht * e->z) + e->my;
	}
	return (0);
}

int		mouse_hook(int button, int x, int y, t_env *e)
{
	if (button == 5 && e->z > 0.2)
		e->z /= 2;
	if (button == 4)
	{
		e->z *= 2;
		e->mx += 1.5 * (x - e->wd / 2) / (0.5 * e->z * e->wd);
		e->my += (y - e->ht / 2) / (0.5 * e->z * e->ht);
	}
	return (0);
}
