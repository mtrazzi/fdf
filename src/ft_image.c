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

t_img_d	ft_change_pix(t_pix pix, int x, int y, t_img_d d)
{
	int		index;

	index = y * d.bpl + x * (d.depth / 8);
	d.data[index] = pix.b;
	d.data[index + 1] = pix.g;
	d.data[index + 2] = pix.r;
	d.data[index + 3] = pix.a;
	return (d);
}
