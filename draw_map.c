/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 17:20:30 by ichubare          #+#    #+#             */
/*   Updated: 2017/02/26 14:44:36 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	img_init(t_fdm *mapa)
{
	int		l_len;
	int		bites_p_p;
	int		endian;

	mapa->img = mlx_new_image(mapa->mlx, 1920, 1080);
	mapa->current = mlx_get_data_addr(mapa->img, &bites_p_p, &l_len, &endian);
}

void	draw_pxl(t_fdm *mapa, int x, int y)
{
	int		bl;
	int		rd;
	int		gr;

	if (mapa->psihodel == 0)
		norm(mapa);
	else
		psihodel_col(mapa);
	bl = mapa->blue;
	gr = mapa->green;
	rd = mapa->red;
	if (((x > 0) && (y > 0)) && ((x < 1920) && (y < 1080)))
	{
		mapa->current[(x * 4) + (y * 1920 * 4)] = bl;
		mapa->current[(x * 4) + (y * 1920 * 4) + 1] = gr;
		mapa->current[(x * 4) + (y * 1920 * 4) + 2] = rd;
	}
}

void	img_destr(t_fdm *map)
{
	mlx_put_image_to_window(map->mlx, map->win, map->img, 0, 0);
	mlx_destroy_image(map->mlx, map->img);
}

void	l_draw(t_fdm *mapa)
{
	double	beg_x;
	double	beg_y;
	double	end_x;
	double	end_y;
	double	vect;

	beg_x = mapa->x[0];
	beg_y = mapa->y[0];
	end_x = mapa->x[1] - beg_x;
	end_y = mapa->y[1] - beg_y;
	vect = sqrt(end_y * end_y + end_x * end_x);
	end_x /= vect;
	end_y /= vect;
	while (vect >= 0)
	{
		draw_pxl(mapa, beg_x, beg_y);
		beg_x += end_x;
		beg_y += end_y;
		vect--;
	}
}

int		draw_map(t_fdm *mapa)
{
	int		i;
	int		j;

	i = 0;
	img_init(mapa);
	while (i != mapa->rows)
	{
		j = 0;
		while (j != mapa->columns)
		{
			mapa->x[0] = j;
			mapa->y[0] = i;
			if (j + 1 < mapa->columns)
				ft_angle(mapa, j, i, 0);
			if (i + 1 < mapa->rows)
				ft_angle(mapa, j, i, 1);
			j++;
		}
		i++;
	}
	img_destr(mapa);
	return (0);
}
