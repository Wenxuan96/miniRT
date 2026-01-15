/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyvan-de <lyvan-de@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:40:51 by wxi               #+#    #+#             */
/*   Updated: 2026/01/15 18:29:38 by lyvan-de         ###   ########.fr       */
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

void	assign_hit_count(t_ray *r, double hit1, double hit2)
{
	if (hit1 > 0 && hit2 > 0)
	{
		r->hit_count = 2;
	}
	if ((hit1 > 0 && hit2 <= 0) || (hit2 > 0 && hit1 <= 0))
	{
		r->hit_count = 1;
	}
	if (hit1 <= 0 && hit2 <= 0)
		r->hit_count = 0;
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

// ray should be the transformed ray
double	intersect_unit_sphere(t_ray	*ray)
{
	double	a;
	double	b;
	double	c;
	double	discriminant;
	
	printf("unit ray direction : %f, %f, %f\n", ray->direction.x, ray->direction.y, ray->direction.z);
	printf("unit ray origin : %f, %f, %f\n", ray->origin.x, ray->origin.y, ray->origin.z);
	a = tuple_dot(ray->direction, ray->direction);
	b = 2.0 * tuple_dot(ray->direction, ray->origin);
	c = tuple_dot(ray->origin, ray->origin) - 1.0;
	
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		return (-1);
	ray->hit_points[0] = (-b - sqrt(discriminant)) / (2.0 * a);
	ray->hit_points[1] = (-b + sqrt(discriminant)) / (2.0 * a);
	return (select_t(ray->hit_points[0], ray->hit_points[1]));
}

void hit_sphere(t_ray *r, t_sphere *sph)
{
	t_tuple		origin_center;
	double		a;
	double		b;
	double		c;
	double		radius;
	double		discriminant;

	radius = sph->diameter / 2;
	origin_center = tuple_sub(r->origin, sph->position);
	a = tuple_dot(r->direction, r->direction);
	b = 2.0 * tuple_dot(r->direction, origin_center);
	c = tuple_dot(origin_center, origin_center) - (radius * radius);
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		r->hit_count = 0;
	else
	{
		r->hit_points[0] = (-b - sqrt(discriminant)) / (2.0 * a);
		r->hit_points[1] = (-b + sqrt(discriminant)) / (2.0 * a);
		r->hit_count = 2;
		//assign_hit_count(r, r->hit_points[0], r->hit_points[1]);
	}
}

