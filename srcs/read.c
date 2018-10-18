/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szheng <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 20:25:54 by szheng            #+#    #+#             */
/*   Updated: 2018/10/02 22:31:55 by szheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	append(int fd, t_mlx *m, char **tmp, char *filename)
{
	char	*line;
	int		i;
	int		j;

	fd = open(filename, O_RDONLY);
	j = 0;
	while (get_next_line(fd, &line) > 0)
	{
		tmp = ft_strsplit(line, ' ');
		free(line);
		i = -1;
		while (tmp[++i])
		{
			m->map[j][i] = ft_atoi(tmp[i]);
			if (m->map[j][i] > 100000)
				m->map[j][i] = 100000;
			else if (m->map[j][i] < -100000)
				m->map[j][i] = -100000;
		}
		ft_free_2d((void**)tmp);
		if (i != m->col)
			ft_puterror("Error, check file lengths!\n");
		j++;
	}
	close(fd);
}

void	read_input(t_mlx *m, char *filename, int fd)
{
	int		count;
	char	*line;
	char	**tmp;

	count = 0;
	if (!(get_next_line(fd, &line)))
		ft_puterror("Error, invalid file\n");
	if (!(tmp = ft_strsplit(line, ' ')))
		ft_puterror("Error, invalid file\n");
	free(line);
	while (tmp[count])
		count++;
	ft_free_2d((void**)tmp);
	m->col = count;
	count = 1;
	while ((get_next_line(fd, &line) > 0) && ++count)
		free(line);
	m->row = count;
	if (!(m->map = (int **)ft_memalloc(sizeof(int *) * m->row)))
		ft_puterror("Error, no map");
	count = -1;
	while (++count < m->row)
		m->map[count] = (int *)ft_memalloc(sizeof(int) * m->col);
	close(fd);
	append(fd, m, tmp, filename);
}
