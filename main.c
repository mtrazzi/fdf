/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrazzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 14:46:11 by mtrazzi           #+#    #+#             */
/*   Updated: 2017/07/19 16:35:24 by mtrazzi          ###   ########.fr       */
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

	if (ac != 2)
		exit(EXIT_FAILURE);
	printf("%d\n", ft_number_of_lines(av[1]));
	tab = ft_parse(av[1]);
	e.mlx = mlx_init();
    e.win = mlx_new_window(e.mlx, 800, 800, "this is my window");
	e.d = ft_get_img(e.mlx, 400, 400);
	
	for (int x = 0; x < 300; x++)
	{
		if (x % 30 < 10)
			e.pix = ft_pixel_init(0, 255, 0, 0);
		else if (x % 30 < 20)
			e.pix = ft_pixel_init(0, 0, 255, 0);
		else
			e.pix = ft_pixel_init(0, 0, 0, 255);
		ft_put_line(ft_pt(x, 0), ft_pt(x, 400), &e);
	}
	mlx_key_hook(e.win, key_hook, &e);
	mlx_put_image_to_window(e.mlx, e.win, e.d.img_addr, 0, 0);
    mlx_loop(e.mlx);
}
