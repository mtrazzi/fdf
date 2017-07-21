/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrazzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 14:52:17 by mtrazzi           #+#    #+#             */
/*   Updated: 2017/07/21 16:18:52 by mtrazzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_open(char *file_name)
{
	int fd;

	if ((fd = open(file_name, O_RDONLY)) == -1)
	{
		ft_putstr("Error : cannot open file\n");
		exit(EXIT_FAILURE);
	}
	return (fd);
}

int		ft_nb_lines(char *file_name)
{
	int		fd;
	int		sum;
	char	*line;

	sum = 0;
	fd = ft_open(file_name);
	while (get_next_line(fd, &line) > 0)
		sum++;
	if (close(fd) == -1)
		exit(EXIT_FAILURE);
	return (sum);
}

int		ft_tab_length(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int		*ft_parse_aux(int fd, char **tab, t_env *e)
{
	int		i;
	int		j;
	int		*tmp;

	j = -1;
	e->width = ft_tab_length(tab);
	if (!(tmp = (int *)malloc(sizeof(int) * ft_tab_length(tab))))
		exit(EXIT_FAILURE);
	while (++j < ft_tab_length(tab))
		tmp[j] = ft_atoi(tab[j]);
	e->width = j;
	ft_free_char_tab(tab, e->width);
	return (tmp);
}

void	ft_parse(char *file_name, t_env *e)
{
	int		fd;
	char	*line;
	int		**result;
	int		i;

	if (!(result = (int **)malloc(sizeof(int *) * ft_nb_lines(file_name))))
		exit(EXIT_FAILURE);
	i = -1;
	fd = ft_open(file_name);
	while (get_next_line(fd, &line) > 0)
		result[++i] = ft_parse_aux(fd, ft_strsplit(line, ' '), e);
	if (close(fd) == -1)
		exit(EXIT_FAILURE);

	e->height = ft_nb_lines(file_name);
	e->tab = result;
}
