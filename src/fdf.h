/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrazzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 10:59:32 by mtrazzi           #+#    #+#             */
/*   Updated: 2017/07/18 18:22:06 by mtrazzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include "mlx.h"
#include "libft.h"

typedef struct	s_point
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;
}				t_point;

typedef struct	s_line
{
	int		dx;
	int		dy;
	int		err;
}				t_line;

typedef union			s_pix
{
	unsigned int		n;
	struct
	{
		unsigned char	b;
		unsigned char	g;
		unsigned char	r;
		unsigned char	a;
	};
}						t_pix;

void	line(int x0, int y0, int x1, int y1, void *mlx, void *win);
void	ft_put_pixel(t_point *p, int color);
t_point	*ft_change_point(t_point *s, int x, int y);
t_point	ft_point_init(void *mlx, void *win, int x, int y);
t_pix	ft_pixel_init(unsigned char a, unsigned char r, unsigned char g, unsigned char b);

#endif
