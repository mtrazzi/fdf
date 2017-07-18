/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrazzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 14:46:11 by mtrazzi           #+#    #+#             */
/*   Updated: 2017/07/18 18:33:54 by mtrazzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

typedef struct  s_env
{
    void    *mlx;
    void    *win;
}               t_env;

void    draw(void *mlx, void *win)
{
    int     x;
    int     y;
	t_point p;
	void	*img_addr;
	t_pix	pix;

	img_addr = mlx_new_image(mlx,200, 400);
    y = 0;
    p = ft_point_init(mlx, win, 0, 0);
	while (y < 600)
    {
        x = 0;
        while (x < 200)
        {
			ft_change_point(&p, x, y);
			pix = ft_pixel_init(0, 0, 0, 255);
			ft_put_pixel(&p, pix.n);
			x++;
        }
        while (x < 400)
        {
			ft_change_point(&p, x, y);
			pix = ft_pixel_init(0, 255, 255, 255);
			ft_put_pixel(&p, pix.n);
			x++;
        }
        while (x < 600)
        {
			ft_change_point(&p, x, y);
			pix = ft_pixel_init(0, 255, 0, 0);
			ft_put_pixel(&p, pix.n);
			x++;
        }
        y++;
    }
}

int     expose_hook(t_env *e)
{
    draw(e->mlx, e->win);
    return (0);
}

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
	void	*img_addr;
	char	*data;
	int		depth;
	int		bpl;
	int		*depth_ptr;
	int		*bpl_ptr;
	int connard;

	depth = 32;
	bpl = 3200;

	depth_ptr = &depth;
	bpl_ptr = &bpl;
    e.mlx = mlx_init();
    e.win = mlx_new_window(e.mlx, 800, 800, "this is my window");
	
	img_addr = mlx_new_image(e.mlx, 800, 800);
	data = mlx_get_data_addr(img_addr, &depth, &bpl, &connard);
   
	mlx_key_hook(e.win, key_hook, &e);
    mlx_expose_hook(e.win, expose_hook, &e);
    mlx_loop(e.mlx);
}
