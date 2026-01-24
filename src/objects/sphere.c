/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyvan-de <lyvan-de@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:40:51 by wxi               #+#    #+#             */
/*   Updated: 2026/01/24 17:51:42 by lyvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/miniRT.h"

void	init_sphere_transform(t_sphere *sph)
{
	double		radius;
	t_matrix4	scale_mat;
	t_matrix4	trans_mat;

	radius = sph->diameter / 2;
	scale_mat = mat_scaling(radius, radius, radius);
	trans_mat = translation(sph->position.x, sph->position.y, sph->position.z);
	sph->base.transform = multi_mat(trans_mat, scale_mat);
	sph->base.inv_transform = invert_m4(sph->base.transform);
}

double	intersect_unit_sphere(t_ray	*ray)
{
	double	a;
	double	b;
	double	c;
	double	discriminant;
	t_tuple	origin_center;

	origin_center = tuple_sub(ray->origin, new_tuple(0, 0, 0, 1));
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

t_tuple	normal_sphere(t_hit *hit, t_tuple unit_hit_p)
{
	t_tuple	norm_unit;

	norm_unit = tuple_sub(unit_hit_p, new_tuple(0, 0, 0, 1));
	norm_unit.w = 0;
	norm_unit = tuple_norm(norm_unit);
	if (tuple_dot(norm_unit, hit->ray.direction) > 0)
		norm_unit = tuple_mult(norm_unit, -1);
	return (norm_unit);
}
