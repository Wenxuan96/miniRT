/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyvan-de <lyvan-de@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 12:55:52 by wxi               #+#    #+#             */
/*   Updated: 2026/01/21 16:49:17 by lyvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/miniRT.h"

void	init_plane_transform(t_plane *plane)
{
	t_tuple	axis;
	t_matrix4 R;
	double angle;

	axis = tuple_cross((t_tuple){0, 1, 0, 0}, plane->normal);
	angle = acos(tuple_dot((t_tuple){0, 1, 0, 0}, plane->normal));
	R = rotation(axis, angle);
	plane->base.transform = translation(plane->point.x, plane->point.y, plane->point.z);
	plane->base.transform = multi_mat(plane->base.transform, R);
	plane->base.inv_transform = invert_m4(plane->base.transform);
}

 double	intersect_unit_plane(t_ray	*ray)
 {
 	double	denom;
	double	t;

	denom = ray->direction.y;
	if (fabs(denom) < EPSILON)
		return (-1.0);
	t = -ray->origin.y / ray->direction.y;
	if (t < EPSILON)
		return (-1.0);
	return (t);
 }
 