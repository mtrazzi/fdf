/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrazzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 14:46:11 by mtrazzi           #+#    #+#             */
/*   Updated: 2017/07/20 15:23:01 by mtrazzi          ###   ########.fr       */
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
	int		x;

	if (ac != 2)
		exit(EXIT_FAILURE);
	ft_parse(av[1], &e);
	e.mlx = mlx_init();
    e.win = mlx_new_window(e.mlx, 2560, 1440, "this is my window");
	e.d = ft_get_img(e.mlx, 2560, 1440);
	e.scale = ft_min(1280 / e.width, 720 / e.height);;
	e.pix = ft_pixel_init(0, 255, 0, 0);
	e.coord = ft_init_tab(e.width, e.height);
	ft_iso(&e);
	//for (int i = 1; i < e.height - 1; i++)
	//{
	//	for (int j = 1; j < e.width - 1; j++)
	//		ft_process_pt(i, j, &e);
	//}
	for (int i = 0; i < e.height; i++)
	{
		for (int j = 0; j < e.width; j++)
		{
			if (e.tab[i][j] < 5)
				e.d = ft_change_pix(e, ft_pixel_init(0, 0, 0, 255), j, i);
			else if (e.tab[i][j] < 50)
				e.d = ft_change_pix(e, ft_pixel_init(0, 0, 255, 0), j, i);
			else if (e.tab[i][j] < 500)
				e.d = ft_change_pix(e, ft_pixel_init(0, 255, 0, 0), j, i);
		}
	}
	mlx_key_hook(e.win, key_hook, &e);
	mlx_put_image_to_window(e.mlx, e.win, e.d.img_addr, 0, 0);
    mlx_loop(e.mlx);
}
