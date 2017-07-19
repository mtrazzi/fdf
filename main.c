/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrazzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 14:46:11 by mtrazzi           #+#    #+#             */
/*   Updated: 2017/07/19 19:21:07 by mtrazzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int     key_hook(int keycode, t_env *e)
{
    printf("keycode %d\n", keycode);
    if (keycode == 53)
        exit(EXIT_FAILURE);
    return (0);
}

int main(int ac, char **av)
{
    t_env   e;
	int		**tab;
	int		x;

	if (ac != 2)
		exit(EXIT_FAILURE);
	ft_parse(av[1], &e);
	e.mlx = mlx_init();
    e.win = mlx_new_window(e.mlx, e.width, e.height, "this is my window");
	e.d = ft_get_img(e.mlx, e.width, e.height);
	e.pix = ft_pixel_init(0, 255, 0, 0);
	for (int i = 0; i < e.height; i++)
	{
		for (int j = 0; j < e.width; j++)
			e.d = ft_change_pix(ft_pixel_init(e.tab[j][i], 0, 0, 0), i, j, e.d);
	}
	mlx_key_hook(e.win, key_hook, &e);
	mlx_put_image_to_window(e.mlx, e.win, e.d.img_addr, 0, 0);
    mlx_loop(e.mlx);
}
