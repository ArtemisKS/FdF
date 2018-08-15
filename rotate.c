/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 19:04:19 by akupriia          #+#    #+#             */
/*   Updated: 2018/02/28 19:04:19 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "points.h"

void		free_arr(void ***arr, size_t i)
{
	while (i != 0)
	{
		free((*arr)[--i]);
		(*arr)[i] = NULL;
	}
	free(*arr);
	*arr = NULL;
}

int			exit_x(t_graf *par)
{
	free_arr((void ***)&(par->tp), par->ny);
	free_arr((void ***)&(par->tp_z), par->ny);
	ft_memdel((void **)&par);
	exit(1);
	return (0);
}

t_point		rotate_x(t_point point, double ang, t_point centre)
{
	t_point new_point;

	new_point.y = (point.y - centre.y) * cos(ang) -
	(point.z) * sin(ang) + centre.y;
	new_point.z = (point.z) * cos(ang) +
	(point.y - centre.y) * sin(ang);
	new_point.x = point.x;
	new_point.color = point.color;
	return (new_point);
}

t_point		rotate_y(t_point point, double ang, t_point centre)
{
	t_point new_point;

	new_point.x = (point.x - centre.x) * cos(ang) +
	(point.z) * sin(ang) + centre.x;
	new_point.z = (point.z) * cos(ang) -
	(point.x - centre.x) * sin(ang);
	new_point.y = point.y;
	new_point.color = point.color;
	return (new_point);
}

t_point		rotate_z(t_point point, double ang, t_point centre)
{
	t_point new_point;

	new_point.x = (point.x - centre.x) * cos(ang) -
	(point.y - centre.y) * sin(ang) + centre.x;
	new_point.y = (point.y - centre.y) * cos(ang) +
	(point.x - centre.x) * sin(ang) + centre.y;
	new_point.z = point.z;
	new_point.color = point.color;
	return (new_point);
}
