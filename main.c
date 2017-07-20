/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrazzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 14:46:11 by mtrazzi           #+#    #+#             */
/*   Updated: 2017/07/20 22:42:24 by mtrazzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_hook(int keycode, t_env *e)
{
	if (keycode == 53)
		exit(EXIT_FAILURE);
	return (0);
}

void	draw(t_env *e)
{
	int i;
	int j;

	i = 0;
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
	ft_parse(av[1], &e);
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 2560, 1440, "this is my window");
	e.d = ft_get_img(e.mlx, 2560, 1440);
	e.scale = 500 / e.width + 1;
	e.coord = ft_init_tab(e.height, e.width);
	e.o.av = av;
	ft_iso(&e);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
	ft_free_coord(e.coord, e.height);
	ft_free_tab(e.tab, e.height);
	mlx_destroy_image(e.mlx, e.d.img_addr);
}
