/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaziuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 13:24:53 by mpaziuk           #+#    #+#             */
/*   Updated: 2017/02/23 13:24:55 by mpaziuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_env	*ft_mlx_init(void)
{
	t_env	*e;

	e = (t_env*)malloc(sizeof(t_env));
	e->wd = 1200;
	e->ht = 800;
	e->z = 1;
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, e->wd, e->ht, "Fractol");
	e->img = mlx_new_image(e->mlx, e->wd, e->ht);
	e->mx = -0.5;
	e->my = 0;
	e->con.r = -0.7;
	e->con.im = 0.27015;
	e->iter = 50;
	e->inter = 1;
	return (e);
}

int		main(int ac, char **av)
{
	t_env	*e;

	if (ac == 2)
	{
		e = ft_mlx_init();
		mlx_hook(e->win, 2, 3, my_key_func, e);
		mlx_mouse_hook(e->win, &mouse_hook, e);
		mlx_hook(e->win, 6, 64, &mouse_move, e);
		if (!ft_strcmp(av[1], "Mandelbrot"))
			mlx_loop_hook(e->mlx, &draw_mandel, e);
		else if (!ft_strcmp(av[1], "Julia"))
			mlx_loop_hook(e->mlx, &draw_julia, e);
		else if (!ft_strcmp(av[1], "Burningship"))
			mlx_loop_hook(e->mlx, &draw_ship, e);
		else
		{
			ft_putstr(av[1]);
			ft_putstr(" doesn't exist. Use Mandelbrot, Julia or Burningship\n");
			exit(0);
		}
		mlx_loop(e->mlx);
	}
	write(1, "\n", 1);
	return (0);
}
