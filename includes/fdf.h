/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szheng <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 20:16:12 by szheng            #+#    #+#             */
/*   Updated: 2018/10/02 22:33:08 by szheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include "../minilibx_macos/mlx.h"

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
	int		**map;
	int		col;
	int		row;
}				t_mlx;

void			read_input(t_mlx *m, char *filename, int fd);
void			print_map(t_mlx *m, int c, int r, int swap);
void			rotation(int *pt1, int *pt2, float rad);

#endif
