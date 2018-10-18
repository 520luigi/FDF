/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szheng <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 20:35:14 by szheng            #+#    #+#             */
/*   Updated: 2018/10/02 22:31:17 by szheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	bresen_draw_line(t_mlx *m, int *pt1, int *pt2, int swap)
{
	int d[2];
	int s[2];
	int p;

	d[0] = abs(pt2[0] - pt1[0]);
	d[1] = abs(pt2[1] - pt1[1]);
	s[0] = (pt2[0] > pt1[0]) ? 1 : -1;
	s[1] = (pt2[1] > pt1[1]) ? 1 : -1;
	if (d[1] > d[0])
	{
		ft_swap(&(d[0]), &(d[1]));
		swap = 1;
	}
	p = 2 * d[1] - d[0];
	while (pt1[0] != pt2[0] || pt1[1] != pt2[1])
	{
		mlx_pixel_put(m->mlx, m->win, pt1[0], pt1[1], 0xff0000);
		while (p >= 0)
		{
			p = p - 2 * d[0];
			swap ? (pt1[0] += s[0]) : (pt1[1] += s[1]);
		}
		p = p + 2 * d[1];
		swap ? (pt1[1] += s[1]) : (pt1[0] += s[0]);
	}
}

void	ft_fill_columns(int *pt1, int *pt2, int x, int y)
{
	int offset;

	offset = 130;
	pt1[0] = x * 15 + offset * 4;
	pt1[1] = y * 15 + offset;
	pt2[0] = x * 15 + 15 + offset * 4;
	pt2[1] = y * 15 + offset;
	rotation(pt1, pt2, (0.25));
}

void	ft_fill_rows(int *pt1, int *pt2, int x, int y)
{
	int offset;

	offset = 130;
	pt1[0] = x * 15 + offset * 4;
	pt1[1] = y * 15 + offset;
	pt2[0] = x * 15 + offset * 4;
	pt2[1] = y * 15 + 15 + offset;
	rotation(pt1, pt2, (0.25));
}

void	print_map(t_mlx *m, int c, int r, int swap)
{
	int pt1[2];
	int pt2[2];

	while (++r < m->row)
	{
		c = -1;
		while (++c < m->col)
		{
			ft_fill_columns(pt1, pt2, c, r);
			pt1[1] -= m->map[r][c];
			if (c != m->col - 1)
			{
				pt2[1] -= m->map[r][c + 1];
				bresen_draw_line(m, pt1, pt2, swap);
			}
			ft_fill_rows(pt1, pt2, c, r);
			pt1[1] -= m->map[r][c];
			if (r != m->row - 1)
			{
				pt2[1] -= m->map[r + 1][c];
				bresen_draw_line(m, pt1, pt2, swap);
			}
		}
	}
}
