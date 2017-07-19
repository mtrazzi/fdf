/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrazzi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 14:52:17 by mtrazzi           #+#    #+#             */
/*   Updated: 2017/07/19 16:40:42 by mtrazzi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_number_of_lines(char *file_name)
{
	int		fd;
	int		sum;
	char	*line;

	sum = 0;
	if ((fd = open(file_name, O_RDONLY)) == -1)
	{
		ft_putstr("Error : cannot open file\n");
		exit(EXIT_FAILURE);
	}
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

int		**ft_parse(char *file_name)
{
	int		fd;
	char	*line;
	char	**tab;
	int		**result;
	int		i;
	int		j;
	int		*tmp;

	if (!(result = (int **)malloc(sizeof(int *) * ft_number_of_lines(file_name))))
		exit(EXIT_FAILURE);
	i = 0;
	if ((fd = open(file_name, O_RDONLY)) == -1)
	{
		ft_putstr("Error : cannot open file\n");
		exit(EXIT_FAILURE);
	}
	while (get_next_line(fd, &line) > 0) {}
	{
		j = -1;
		tab = ft_strsplit(line, ' ');
		tmp = (int *)malloc(sizeof(int *));
		while (++j < ft_tab_length(tab))
			tmp[j] = ft_atoi(tab[j]);
		result[i] = tmp;
		i++;
	}
	if (close(fd) == -1)
		exit(EXIT_FAILURE);
	return (result);
}

int main(int ac, char **av)
{
	ft_parse(av[1]);
	return (0);
}
