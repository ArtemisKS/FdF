/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 19:12:26 by akupriia          #+#    #+#             */
/*   Updated: 2018/02/28 19:12:27 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "points.h"

void	line_draw(t_point p1, t_point p2, t_graf *tg)
{
	float			x;
	float			y;

	x = p1.x;
	y = p1.y;
	mlx_pixel_put(tg->mlx, tg->win, x, y, p1.color);
	if (fabs(p1.x - p2.x) > fabs(p1.y - p2.y))
		while (p1.x > p2.x ? x > p2.x : x < p2.x)
		{
			x > p2.x ? x-- : x++;
			y = ((x - p1.x) / (p2.x - p1.x)) * (p2.y - p1.y) + p1.y;
			mlx_pixel_put(tg->mlx, tg->win, x, y, grad(p1, p2, x, 'x'));
		}
	else
		while (p1.y > p2.y ? y > p2.y : y < p2.y)
		{
			y > p2.y ? y-- : y++;
			x = ((y - p1.y) * (p2.x - p1.x) / (p2.y - p1.y)) + p1.x;
			mlx_pixel_put(tg->mlx, tg->win, x, y, grad(p1, p2, y, 'y'));
		}
}

void	make_central(t_graf *tg)
{
	int i;
	int j;

	j = 0;
	while (j < tg->ny)
	{
		i = 0;
		while (i < tg->nx)
		{
			tg->tp[j][i].x = (tg->tp[j][i].x - tg->nx / 2)
			* tg->scale + SCREEN / 2;
			tg->tp[j][i].y = (tg->tp[j][i].y - tg->ny / 2)
			* tg->scale + SCREEN / 2;
			i++;
		}
		j++;
	}
	tg->centre.x = (tg->centre.x - tg->nx / 2) * tg->scale + SCREEN / 2;
	tg->centre.y = (tg->centre.y - tg->ny / 2) * tg->scale + SCREEN / 2;
}

void	ch_scale(t_graf *tg, double scale1)
{
	int i1;
	int j1;

	j1 = 0;
	while (j1 < tg->ny)
	{
		i1 = 0;
		while (i1 < tg->nx)
		{
			tg->tp[j1][i1].z *= tg->scale / scale1;
			tg->tp[j1][i1].x = (tg->tp[j1][i1].x - tg->centre.x)
			* (tg->scale / scale1) + tg->centre.x;
			tg->tp[j1][i1].y = (tg->tp[j1][i1].y - tg->centre.y)
			* (tg->scale / scale1) + tg->centre.y;
			i1++;
		}
		j1++;
	}
}

int		is_hex(char c)
{
	int		i;
	char	*ar;

	ar = "0123456789ABCDEFabcdef";
	i = 0;
	while (ar[i])
	{
		if (ar[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		skip_parse(t_list *tl, int x)
{
	while ((((char *)tl->content)[x] >= '0' && ((char *)tl->content)[x] <= '9')
		|| (((char *)tl->content)[x] == '-'))
		x++;
	while (((char *)tl->content)[x] == ' ')
		x++;
	return (x);
}
