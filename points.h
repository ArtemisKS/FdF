/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 19:11:44 by akupriia          #+#    #+#             */
/*   Updated: 2018/02/15 19:11:45 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINTS_H
# define POINTS_H

# include "libft/libft.h"
# include "get_next_line.h"
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# define SCREEN 1200

typedef struct	s_point
{
	double		x;
	double		y;
	double		z;
	long int	color;
}				t_point;

typedef struct	s_graf
{
	double		nx;
	double		ny;
	double		scale;
	double		angle;
	double		angle1;
	double		angle2;
	int			fd;
	void		*win;
	void		*mlx;
	t_point		centre;
	t_point		**tp;
	t_point		**tp_z;
}				t_graf;

int				open_read(char *file, t_graf *tg);
int				is_valid(t_list *tl);
t_graf			*graf_init();
int				is_hex(char c);
t_list			*gnl_read(int *j, int *i, t_graf *tg);
void			free_list(t_list *tl);
void			calc_scale(t_graf *tg);
int				skip_parse(t_list *tl, int x);
unsigned int	grad(t_point point1, t_point point2, float x, char c);
unsigned int	grad_y(t_point p1, t_point p2, float x, unsigned int c);
unsigned int	grad_x(t_point p1, t_point p2, float x, unsigned int c);
void			free_arr(void ***arr, size_t i);
void			parse_incycle(t_graf *tg, t_list *tl, int j1, int x);
int				key_part1(int key, t_graf *tg1);
int				key_part2(int key, t_graf *tg1);
void			key_part3(int key, t_graf *tg1);
void			fill_tp_z(t_graf *tg);
void			ch_scale_z1(t_graf *tg1, double scale1);
int				exit_x(t_graf *par);
void			mult_zet(int value, t_graf *tg1);
t_graf			*move_y(t_graf *tg1, int key);
t_graf			*move_x(t_graf *tg1, int key);
void			draw_map(t_graf *tg);
void			parse(t_graf *tg, t_list *tl);
void			ch_scale(t_graf *tg, double scale1);
void			line_draw(t_point p1, t_point p2, t_graf *tg);
void			make_central(t_graf *tg);
void			map_rotate(t_graf *tg1);
t_point			rotate_x(t_point point, double ang, t_point centre);
t_point			rotate_y(t_point point, double ang, t_point centre);
t_point			rotate_z(t_point point, double ang, t_point centre);
int				handle_events(int key, t_graf *tg1);
t_graf			*mult_z(double value, t_graf *tg1);

#endif
