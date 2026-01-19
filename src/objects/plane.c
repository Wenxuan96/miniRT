/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxi <wxi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 12:55:52 by wxi               #+#    #+#             */
/*   Updated: 2026/01/19 14:39:43 by wxi              ###   ########.fr       */
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
	plane->transform = translation(plane->point.x, plane->point.y, plane->point.z);
	plane->transform = multi_mat(plane->transform, R);
	plane->inv_transform = invert_m4(plane->transform);
}

// double	intersect_unit_sphere(t_ray	*ray)
// {
// 	double	a;
// 	double	b;
// 	double	c;
// 	double	discriminant;
// 	t_tuple		origin_center;
// 	t_tuple		zero_pos;
	
// 	zero_pos = new_tuple(0, 0, 0, 1);
// 	origin_center = tuple_sub(ray->origin, zero_pos);
// 	a = tuple_dot(ray->direction, ray->direction);
// 	b = 2.0 * tuple_dot(ray->direction, origin_center);
// 	c = tuple_dot(origin_center, origin_center) - 1.0;
	
// 	discriminant = b * b - 4 * a * c;
// 	if (discriminant < 0)
// 		return (-1);
// 	ray->hit_points[0] = (-b - sqrt(discriminant)) / (2.0 * a);
// 	ray->hit_points[1] = (-b + sqrt(discriminant)) / (2.0 * a);
// 	return (select_t(ray->hit_points[0], ray->hit_points[1]));
// }