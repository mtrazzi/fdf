/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrazzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 10:59:32 by mtrazzi           #+#    #+#             */
/*   Updated: 2017/07/20 22:42:26 by mtrazzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <mlx.h>
# include <libft.h>

typedef struct	s_line
{
	int		dx;
	int		dy;
	int		err;
}				t_line;
typedef struct	s_pix
{
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;
	unsigned char	a;
}				t_pix;
typedef struct	s_point
{
	int		x;
	int		y;
	t_pix	pix;
}				t_point;
typedef	struct	s_img_d
{
	char	*data;
	void	*img_addr;
	int		depth;
	int		bpl;
	int		end;
}				t_img_d;
typedef struct	s_opt
{
	char	**av;
	int		ac;
	int		cursor;
}				t_opt;
typedef struct	s_env
{
	void	*mlx;
	void	*win;
	t_img_d	d;
	t_pix	pix;
	int		width;
	int		height;
	int		**tab;
	int		scale;
	t_point	**coord;
	t_opt	o;
}				t_env;
void			ft_put_pixel(t_point *p, int color);
t_point			*ft_change_point(t_point *s, int x, int y);
t_point			ft_pt(int x, int y, t_pix pix);
t_pix			ft_pixel_init(unsigned char a, unsigned char r, \
				unsigned char g, unsigned char b);
t_img_d			ft_get_img(void *mlx, int width, int height);
t_img_d			ft_change_pix(t_env e, t_pix pix, int x, int y);
void			ft_put_line(t_point p1, t_point p2, t_env *e);
int				ft_nb_lines(char *file_name);
void			ft_parse(char *file_name, t_env *e);
t_point			**ft_init_tab(int n, int p);
void			ft_iso(t_env *e);
void			ft_process_pt(int x, int y, t_env *e);
void			ft_free_tab(int **tab, int size);
void			ft_free_coord(t_point **tab, int size);
t_pix			ft_mix(t_pix p1, t_pix p2);
void			ft_free_char_tab(char **tab, int size);

#endif
