/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 15:55:31 by ichubare          #+#    #+#             */
/*   Updated: 2017/02/26 14:58:14 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "ft_printf/ft_printf.h"
# include "mlx.h"
# include "math.h"

typedef struct		s_fdm
{
	char			**map;
	int				**matrix;
	struct s_fdm	*next;
	int				rows;
	int				red;
	int				green;
	int				blue;
	int				zoom;
	int				z;
	int				top_bot;
	int				rig_lef;
	int				x[2];
	int				y[2];
	float			angle;
	int				columns;
	void			*mlx;
	void			*win;
	void			*img;
	char			*current;
	int				psihodel;
}					t_fdm;

int					draw_map(t_fdm *mapa);
void				ft_angle(t_fdm *mapa, int i, int j, int which);
void				l_draw(t_fdm *mapa);
int					init_mapa(t_fdm **mapa, char *argv);
int					press_key(int key_code, t_fdm *mapa);
void				img_destr(t_fdm *map);
void				draw_pxl(t_fdm *mapa, int x, int y);
void				img_init(t_fdm *mapa);
void				end_coord_y(t_fdm *mapa, int i, int j, int x_y[2]);
void				end_coord_x(t_fdm *mapa, int i, int j, int x_y[2]);
char				**take_map(char *argv, t_fdm *mapa);
void				make_matrix(t_fdm *mapa);
int					color_change(int key_code, t_fdm *mapa);
void				psihodel_col(t_fdm *mapa);
void				norm(t_fdm *mapa);

#endif
