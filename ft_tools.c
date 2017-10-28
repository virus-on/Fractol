/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaziuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 17:30:58 by mpaziuk           #+#    #+#             */
/*   Updated: 2017/02/26 17:30:59 by mpaziuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_ext_r(int clr)
{
	return ((int)(((clr >> 16) & 0xFF)));
}

int		ft_ext_g(int clr)
{
	return ((int)(((clr >> 8) & 0xFF)));
}

int		ft_ext_b(int clr)
{
	return ((int)((clr & 0xFF)));
}

void	mlx_img_clear(t_env *e)
{
	char	*pixel;
	int		p;

	pixel = mlx_get_data_addr(e->img, &p, &p, &p);
	ft_bzero(pixel, e->wd * e->ht * 4);
}

void	mlx_pixput(t_env *e, int x, int y, int color)
{
	char	*pixel;
	int		p;

	if (x > 0 && y > 0 && x < e->wd && y < e->ht)
	{
		pixel = mlx_get_data_addr(e->img, &p, &p, &p);
		p = e->wd * y * 4 + x * 4;
		pixel[p + 0] = ft_ext_b(color);
		pixel[p + 1] = ft_ext_g(color);
		pixel[p + 2] = ft_ext_r(color);
	}
}
