/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyvan-de <lyvan-de@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:40:51 by wxi               #+#    #+#             */
/*   Updated: 2026/01/20 15:18:25 by lyvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/miniRT.h"

void	init_sphere_transform(t_sphere *sphere)
{
	double		radius;
	t_matrix4	scale_mat;
	t_matrix4	trans_mat;
	
	radius = sphere->diameter / 2;
	scale_mat = mat_scaling(radius, radius, radius);
	trans_mat = translation(sphere->position.x, sphere->position.y, sphere->position.z);
	sphere->base.transform = multi_mat(trans_mat, scale_mat);
	sphere->base.inv_transform = invert_m4(sphere->base.transform);
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


