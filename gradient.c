/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 19:02:01 by akupriia          #+#    #+#             */
/*   Updated: 2018/02/28 19:02:02 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "points.h"

float			mod(float x)
{
	return ((x < 0) ? -x : x);
}

unsigned int	grad(t_point point1, t_point point2, float x, char c)
{
	unsigned int color;

	color = point1.color;
	if (c == 'x')
		color = grad_x(point1, point2, x, color);
	else
		color = grad_y(point1, point2, x, color);
	return (color);
}

unsigned int	grad_x(t_point point1, t_point point2,
float x, unsigned int color)
{
	color += (long)(((long)(point2.color % 256) - (long)(point1.color % 256)) /
	mod(point2.x - point1.x) * mod(x - point1.x));
	color += (long)(((long)((point2.color / 256) % 256) - (long)((point1.color /
	256) % 256)) / mod(point2.x - point1.x) * mod(x - point1.x)) * 256;
	color += (long)(((long)((point2.color / 256 / 256) % 256) -
	(long)((point1.color / 256 / 256) % 256)) / mod(point2.x - point1.x) *
	mod(x - point1.x)) * 256 * 256;
	return (color);
}

unsigned int	grad_y(t_point point1, t_point point2,
float x, unsigned int color)
{
	color += (long)(((long)(point2.color % 256) - (long)(point1.color % 256)) /
	mod(point2.y - point1.y) * mod(x - point1.y));
	color += (long)(((long)((point2.color / 256) % 256) - (long)((point1.color /
	256) % 256)) / mod(point2.y - point1.y) * mod(x - point1.y)) * 256;
	color += (long)(((long)((point2.color / 256 / 256) % 256) -
	(long)((point1.color / 256 / 256) % 256)) / mod(point2.y - point1.y) *
	mod(x - point1.y)) * 256 * 256;
	return (color);
}

void			calc_scale(t_graf *tg)
{
	tg->scale = 1.1 * SCREEN / (tg->nx + tg->ny);
}
