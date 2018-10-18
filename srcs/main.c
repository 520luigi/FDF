/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szheng <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 20:19:12 by szheng            #+#    #+#             */
/*   Updated: 2018/10/02 22:31:32 by szheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		key_handler(int key)
{
	if (key == 53)
		exit(0);
	return (0);
}

void	rotation(int *pt1, int *pt2, float rad)
{
	pt1[0] = (int)(pt1[0] * cos(rad) - pt1[1] * sin(rad));
	pt1[1] = (int)(pt1[0] * sin(rad) + pt1[1] * cos(rad));
	pt2[0] = (int)(pt2[0] * cos(rad) - pt2[1] * sin(rad));
	pt2[1] = (int)(pt2[0] * sin(rad) + pt2[1] * cos(rad));
}

int		main(int ac, char **av)
{
	t_mlx	m;
	int		fd;

	if (ac != 2)
		ft_puterror("Usage: ./fdf <filename>\n");
	if ((fd = open(av[1], O_RDONLY)) < 0)
		ft_puterror("Error, no file exist\n");
	read_input(&m, av[1], fd);
	m.mlx = mlx_init();
	m.win = mlx_new_window(m.mlx, 1920, 1080, "Funky Disco Fun");
	print_map(&m, -1, -1, 0);
	mlx_key_hook(m.win, key_handler, &m);
	mlx_loop(m.mlx);
	return (0);
}
