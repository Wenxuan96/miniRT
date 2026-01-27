/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxi <wxi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 16:44:46 by wxi               #+#    #+#             */
/*   Updated: 2026/01/27 14:52:16 by wxi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/miniRT.h"

void	init_cylinder_transform(t_cylinder *cy)
{
	t_matrix4	t;
	t_matrix4	r;
	t_matrix4	s;
	t_tuple		y_axis;
	double		angle;

	y_axis = new_tuple(0, 1, 0, 0);
	s = mat_scaling(cy->diameter / 2, cy->height / 2,
			cy->diameter / 2);
	if (fabs(tuple_dot(y_axis, cy->axis)) > 0.999)
		r = identity_m4();
	else
	{
		angle = acos(tuple_dot(y_axis, cy->axis));
		r = rotation(tuple_norm(tuple_cross(y_axis, cy->axis)), angle);
	}
	t = translation(cy->center.x, cy->center.y, cy->center.z);
	cy->base.transform = multi_mat(t, multi_mat(r, s));
	cy->base.inv_transform = invert_m4(cy->base.transform);
}

double	find_t(double t, t_ray *unit_ray)
{
	double	t_y;

	t_y = unit_ray->origin.y + t * unit_ray->direction.y;
	if (-1.0 < t_y && t_y < 1.0)
		return (t);
	return (-1);
}

bool	check_cap(t_ray *unit_ray, double t)
{
	double	x;
	double	z;

	x = unit_ray->origin.x + t * unit_ray->direction.x;
	z = unit_ray->origin.z + t * unit_ray->direction.z;
	return (((x * x + z * z) <= 1));
}

double	intersect_caps(t_ray *unit_ray, t_cylinder *cy)
{
	double	upper_cap_t;
	double	lower_cap_t;
	double	cap_ts[2];
	double	cap_t;

	cap_ts[0] = -1;
	cap_ts[1] = -1;
	if (fabs(unit_ray->direction.y) < EPSILON)
		return (-1);
	upper_cap_t = (1 - unit_ray->origin.y) / unit_ray->direction.y;
	lower_cap_t = (-1 - unit_ray->origin.y) / unit_ray->direction.y;
	if (check_cap(unit_ray, upper_cap_t))
		cap_ts[0] = upper_cap_t;
	if (check_cap(unit_ray, lower_cap_t))
		cap_ts[1] = lower_cap_t;
	cap_t = select_t(cap_ts[0], cap_ts[1]);
	if (cap_t == upper_cap_t && cap_t != -1)
		cy->hit_location = TOP;
	else if (cap_t == lower_cap_t && cap_t != -1)
		cy->hit_location = BOTTOM;
	return (cap_t);
}

double	intersect_unit_cylinder(t_ray *unit_ray, t_cylinder *cy)
{
	double	a;
	double	b;
	double	c;
	double	disc;
	double	t;

	a = unit_ray->direction.x * unit_ray->direction.x
		+ unit_ray->direction.z * unit_ray->direction.z;
	if (a < EPSILON)
		return (-1.0);
	b = 2 * unit_ray->origin.x * unit_ray->direction.x
		+ 2 * unit_ray->origin.z * unit_ray->direction.z;
	c = unit_ray->origin.x * unit_ray->origin.x
		+ unit_ray->origin.z * unit_ray->origin.z - 1;
	disc = b * b - 4 * a * c;
	if (disc < 0)
		return (-1.0);
	unit_ray->hit_points[0] = find_t((-b - sqrt(disc)) / (2.0 * a), unit_ray);
	unit_ray->hit_points[1] = find_t((-b + sqrt(disc)) / (2.0 * a), unit_ray);
	t = select_t(unit_ray->hit_points[0], unit_ray->hit_points[1]);
	t = select_t(t, intersect_caps(unit_ray, cy));
	if (t != intersect_caps(unit_ray, cy))
		cy->hit_location = CYLINDER;
	return (t);
}

t_tuple	normal_cylinder(t_hit *hit, t_tuple unit_hit_p, t_object *obj)
{
	t_cylinder	*cyl;
	double		half_h;
	t_tuple		norm_unit;

	cyl = (t_cylinder *)obj;
	half_h = cyl->height / 2.0;
	if (fabs(unit_hit_p.y - half_h - EPSILON) < EPSILON)
		norm_unit = new_tuple(0, 1, 0, 0);
	else if (fabs(unit_hit_p.y + half_h + EPSILON) < EPSILON)
		norm_unit = new_tuple(0, -1, 0, 0);
	else
		norm_unit = tuple_norm(new_tuple(unit_hit_p.x, 0, unit_hit_p.z, 0));
	if (tuple_dot(norm_unit, hit->ray.direction) > 0)
		norm_unit = tuple_mult(norm_unit, -1);
	return (norm_unit);
}
