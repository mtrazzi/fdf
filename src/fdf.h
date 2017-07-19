/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrazzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 10:59:32 by mtrazzi           #+#    #+#             */
/*   Updated: 2017/07/19 17:47:21 by mtrazzi          ###   ########.fr       */
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

typedef	struct	s_img_d
{
	char	*data;
	void	*img_addr;
	int		depth;
	int		bpl;
	int		end;
}				t_img_d;

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	t_img_d	d;
	t_pix	pix;
	int		width;
	int		height;
	int		**tab;
}				t_env;

typedef struct	s_tab
{
	int **tab;
	int	nb_raw;
	int	nb_col;
}				t_tab;

void	ft_put_pixel(t_point *p, int color);
t_point	*ft_change_point(t_point *s, int x, int y);
t_point	ft_pt(int x, int y);
t_pix	ft_pixel_init(unsigned char a, unsigned char r, unsigned char g, unsigned char b);
t_img_d	ft_get_img(void *mlx, int width, int height);
t_img_d	ft_change_pix(t_pix pix, int x, int y, t_img_d d);
void	ft_put_line(t_point p1, t_point p2, t_env *e);
int		ft_number_of_lines(char *file_name);
void	ft_parse(char *file_name, t_env *e);

#endif
