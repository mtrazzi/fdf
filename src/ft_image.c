/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrazzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 19:55:29 by mtrazzi           #+#    #+#             */
/*   Updated: 2017/07/21 16:12:15 by mtrazzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_img_d	ft_get_img(void *mlx, int width, int height)
{
	void	*img_addr;
	t_img_d	d;

	img_addr = mlx_new_image(mlx, width, height);
	d.img_addr = img_addr;
	d.data = mlx_get_data_addr(img_addr, &d.depth, &d.bpl, &d.end);
	return (d);
}

t_img_d	ft_change_pix(t_env e, t_pix pix, int x, int y)
{
	int		index;

	index = (y + e.h + ft_max(1440 - e.height - e.width, 0) / 2) * e.d.bpl * \
	e.scale + (x + 800 / e.scale + 100 * e.pad) * (e.d.depth / 8) * e.scale;
	if (index >= 1440 * (e.d.bpl) || index <= 0)
		return (e.d);
	e.d.data[index] = pix.b;
	e.d.data[index + 1] = pix.g;
	e.d.data[index + 2] = pix.r;
	e.d.data[index + 3] = pix.a;
	return (e.d);
}
