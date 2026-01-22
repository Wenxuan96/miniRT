/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyvan-de <lyvan-de@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 12:23:13 by lyvan-de          #+#    #+#             */
/*   Updated: 2026/01/22 18:00:05 by lyvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/miniRT.h"

double	compute_cylinder_angle(t_tuple axis)
{
	t_tuple	up;
	double	angle;
	double	cos_theta;

	up = new_tuple(0,1,0,0);
	axis = tuple_norm(axis);
	cos_theta = tuple_dot(up, axis);
	cos_theta = fmin(1.0, fmax(-1.0, cos_theta));
	angle = acos(cos_theta);
	return (angle);
}

t_matrix4	cylinder_rotation(t_cylinder *cylinder)
{
	t_tuple		rotation_axis;
	double		angle;
	double		axis_lenght;
	t_matrix4	rotation_mat;
	
	angle = compute_cylinder_angle(cylinder->axis);
	rotation_axis = tuple_cross(new_tuple(0,1,0,0), cylinder->axis);
	axis_lenght = sqrt(tuple_dot(rotation_axis, rotation_axis));
	if (axis_lenght < EPSILON)
	{
		if (tuple_dot(new_tuple(0,1,0,0), cylinder->axis) > 0)
		rotation_mat = identity_m4();
		else
		rotation_mat = rotation(new_tuple(1,0,0,0), PI);
	}
	else
	{
		rotation_axis = tuple_norm(rotation_axis);
		rotation_mat = rotation(rotation_axis, angle);
	}
		return (rotation_mat);
}

void	init_cylinder_transform(t_cylinder *cylinder)
{
	t_matrix4	scale_mat;
	t_matrix4	rotate_mat;
	t_matrix4	trans_mat;
	double		radius;
	
	radius = cylinder->diameter / 2.0;
	scale_mat = mat_scaling(radius, 1.0, radius);
	rotate_mat = cylinder_rotation(cylinder);
	trans_mat = translation(cylinder->center.x, cylinder->center.y, cylinder->center.z);
	cylinder->base.transform = multi_mat(trans_mat, multi_mat(rotate_mat, scale_mat));
	cylinder->base.inv_transform = invert_m4(cylinder->base.transform);
}

double	intersect_top_bottom(t_ray *ray, double t)
{
	double	t_top;
	double	t_bottom;
	double	x_hit;
	double	z_hit;

	if (fabs(ray->direction.y) > EPSILON)
	{
		t_top = (1.0 - ray->origin.y) / ray->direction.y;
		x_hit = ray->origin.x + t_top * ray->direction.x;
		z_hit = ray->origin.z + t_top * ray->direction.z;
		if (x_hit*x_hit + z_hit*z_hit <= 1)
			t = select_t(t, t_top); 
	}
	if (fabs(ray->direction.y) > EPSILON)
	{
		t_bottom = (-1.0 - ray->origin.y) / ray->direction.y;
		x_hit = ray->origin.x + t_bottom * ray->direction.x;
		z_hit = ray->origin.z + t_bottom * ray->direction.z;
		if (x_hit*x_hit + z_hit*z_hit <= 1)
			t = select_t(t, t_bottom);
	}
	return (t);
}

double	intersect_unit_cylinder(t_ray *ray)
{
	double	a;
	double	b;
	double	c;
	double	discriminant;
	double	t;

	a = pow(ray->direction.x, 2.0) + pow(ray->direction.z, 2.0);
	if (fabs(a) < EPSILON)
		return (-1);
	b = 2 * ray->origin.x * ray->direction.x + 2 * ray->origin.z * ray->direction.z;
	c = pow(ray->origin.x, 2.0) + pow(ray->origin.z, 2.0) -1;
	discriminant = pow(b, 2.0) - 4 * a * c;
	if (discriminant < 0)
		return (-1);
	ray->hit_points[0] = (-b - sqrt(discriminant)) / (2.0 * a);
	ray->hit_points[1] = (-b + sqrt(discriminant)) / (2.0 * a);
	t = select_t(ray->hit_points[0], ray->hit_points[1]);
	t = intersect_top_bottom(ray, t);
	return (t);
}
