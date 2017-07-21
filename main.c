/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrazzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 14:46:11 by mtrazzi           #+#    #+#             */
/*   Updated: 2017/07/21 12:27:27 by mtrazzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_clean(t_env *e)
{
	ft_bzero(e->d.data, e->height * e->width * (e->d.depth / 8));
	if (e->tab)
	{
		ft_free_tab(e->tab, e->height);
		e->tab = NULL;
	}
	if (e->coord)
	{
		ft_free_coord(e->coord, e->height);
		e->coord = NULL;
	}
	mlx_destroy_image(e->mlx, e->d.img_addr);
	e->d = ft_get_img(e->mlx, 2560, 1440);
	mlx_put_image_to_window(e->mlx, e->win, e->d.img_addr, 0, 0);
	e->o.clean = 1;
}

void	ft_update(t_env *e)
{
	if (e->o.clean)
		return ;
	ft_parse(e->o.av[e->o.cursor], e);
	e->d = ft_get_img(e->mlx, 2560, 1440);
	e->scale = 500 / e->width + 1;
	e->coord = ft_init_tab(e->height, e->width);
	ft_iso(e);
}

void	draw(t_env *e)
{
	int i;
	int j;

	ft_update(e);
	if (!e->tab)
		return ;
	i = 0;
	ft_straight_line(ft_pt(0, 0, e->pix), ft_pt(1, 1, e->pix), 0x00FFFFFF, e);
	while (i < e->height)
	{
		j = 0;
		while (j < e->width)
		{
			ft_process_pt(i, j, e);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->d.img_addr, 0, 0);
}

int		expose_hook(t_env *e)
{
	draw(e);
	return (0);
}

int		main(int ac, char **av)
{
	t_env	e;
	int		x;

	if (ac < 2)
		exit(EXIT_FAILURE);
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 2560, 1440, "fdf");
	e.o.ac = ac;
	e.o.av = av;
	e.o.cursor = 1;
	e.o.clean = 0;
	mlx_key_hook(e.win, key_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
	ft_free_coord(e.coord, e.height);
	ft_free_tab(e.tab, e.height);
	mlx_destroy_image(e.mlx, e.d.img_addr);
	while (1) {}
}
