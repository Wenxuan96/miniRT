/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxi <wxi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 16:17:55 by wxi               #+#    #+#             */
/*   Updated: 2026/01/27 16:21:24 by wxi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/miniRT.h"

t_tuple	normal_object(t_hit *hit, t_tuple unit_hit_p)
{
	t_tuple		norm_unit;
	t_plane		*plane;
	t_object	*obj;

	norm_unit = new_tuple(0, 0, 0, 0);
	obj = hit->object;
	if (obj->type == SPHERE)
		norm_unit = normal_sphere(hit, unit_hit_p);
	else if (obj->type == PLANE)
	{
		plane = (t_plane *)obj;
		norm_unit = plane->normal;
	}
	else if (obj->type == CYLINDER)
	{
		if (fabs(unit_hit_p.y - 1.0) < EPSILON)
			norm_unit = new_tuple(0, 1, 0, 0);
		else if (fabs(unit_hit_p.y + 1.0) < EPSILON)
			norm_unit = new_tuple(0, -1, 0, 0);
		else
			norm_unit = tuple_norm(new_tuple(unit_hit_p.x, 0, unit_hit_p.z, 0));
		if (tuple_dot(norm_unit, hit->ray.direction) > 0)
			norm_unit = tuple_mult(norm_unit, -1);
	}
	return (norm_unit);
}

t_tuple	get_color(t_object *obj, t_ambient world_amb, double intensity)
{
	t_tuple	amb_rgb;
	t_tuple	obj_color;
	t_tuple	rt_color;

	amb_rgb.x = world_amb.color.r / 255.0 * world_amb.ratio;
	amb_rgb.y = world_amb.color.g / 255.0 * world_amb.ratio;
	amb_rgb.z = world_amb.color.b / 255.0 * world_amb.ratio;
	amb_rgb.w = 0;
	obj_color.x = obj->color.r / 255.0;
	obj_color.y = obj->color.g / 255.0;
	obj_color.z = obj->color.b / 255.0;
	obj_color.w = 0;
	rt_color.x = fmin(1.0, obj_color.x * (amb_rgb.x + intensity));
	rt_color.y = fmin(1.0, obj_color.y * (amb_rgb.y + intensity));
	rt_color.z = fmin(1.0, obj_color.z * (amb_rgb.z + intensity));
	rt_color.w = 0;
	return (rt_color);
}
