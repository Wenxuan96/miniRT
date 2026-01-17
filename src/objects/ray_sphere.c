/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxi <wxi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:40:51 by wxi               #+#    #+#             */
/*   Updated: 2026/01/17 17:21:48 by wxi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/miniRT.h"

t_tuple	position(t_ray r, double t)
{
	t_tuple rt;

	rt = tuple_mult(r.direction, t);
	rt = tuple_add(r.origin, rt);
	return rt;
}

void	init_sphere_transform(t_sphere *sphere)
{
	double		radius;
	t_matrix4	scale_mat;
	t_matrix4	trans_mat;
	
	radius = sphere->diameter / 2;
	scale_mat = mat_scaling(radius, radius, radius);
	trans_mat = translation(sphere->position.x, sphere->position.y, sphere->position.z);
	sphere->transform = multi_mat(trans_mat, scale_mat);
	sphere->inv_transform = invert_m4(sphere->transform);
}

double	intersect_unit_sphere(t_ray	*ray)
{
	double	a;
	double	b;
	double	c;
	double	discriminant;
	t_tuple		origin_center;
	t_tuple		zero_pos;
	
	zero_pos = new_tuple(0, 0, 0, 1);
	origin_center = tuple_sub(ray->origin, zero_pos);
	a = tuple_dot(ray->direction, ray->direction);
	b = 2.0 * tuple_dot(ray->direction, origin_center);
	c = tuple_dot(origin_center, origin_center) - 1.0;
	
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		return (-1);
	ray->hit_points[0] = (-b - sqrt(discriminant)) / (2.0 * a);
	ray->hit_points[1] = (-b + sqrt(discriminant)) / (2.0 * a);
	return (select_t(ray->hit_points[0], ray->hit_points[1]));
}


