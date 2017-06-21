/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_angle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 17:14:37 by ichubare          #+#    #+#             */
/*   Updated: 2017/02/26 14:46:24 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	end_coord_x(t_fdm *mapa, int i, int j, int x_y[2])
{
	mapa->x[1] = cos(mapa->angle) * ++x_y[0] * mapa->zoom - \
	sin(mapa->angle) * x_y[1] * mapa->zoom + mapa->rig_lef;
	mapa->y[1] = sin(mapa->angle) * x_y[0] * mapa->zoom + \
	cos(mapa->angle) * x_y[1] * mapa->zoom - mapa->matrix[j][i + 1] * mapa->z \
	+ mapa->top_bot;
}

void	end_coord_y(t_fdm *mapa, int i, int j, int x_y[2])
{
	mapa->x[1] = cos(mapa->angle) * x_y[0] * mapa->zoom - \
	sin(mapa->angle) * ++x_y[1] * mapa->zoom + mapa->rig_lef;
	mapa->y[1] = sin(mapa->angle) * x_y[0] * mapa->zoom + \
	cos(mapa->angle) * x_y[1] * mapa->zoom - mapa->matrix[j + 1][i] * mapa->z \
	+ mapa->top_bot;
}

void	ft_angle(t_fdm *mapa, int i, int j, int which)
{
	int		x_y[2];

	x_y[0] = i - mapa->columns / 2;
	x_y[1] = j - mapa->rows / 2;
	mapa->x[0] = cos(mapa->angle) * x_y[0] * mapa->zoom - sin(mapa->angle) * \
	x_y[1] * mapa->zoom + mapa->rig_lef;
	mapa->y[0] = sin(mapa->angle) * x_y[0] * mapa->zoom + cos(mapa->angle) * \
	x_y[1] * mapa->zoom - mapa->matrix[j][i] * mapa->z + mapa->top_bot;
	if (which == 0)
		end_coord_x(mapa, i, j, x_y);
	else
		end_coord_y(mapa, i, j, x_y);
	l_draw(mapa);
}
