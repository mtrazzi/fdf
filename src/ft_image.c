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

	index = (y + 500) * e.d.bpl * e.scale + x * (e.d.depth / 8) * e.scale + e.width * e.scale;
	e.d.data[index] = pix.b;
	e.d.data[index + 1] = pix.g;
	e.d.data[index + 2] = pix.r;
	e.d.data[index + 3] = pix.a;
	return (e.d);
}
