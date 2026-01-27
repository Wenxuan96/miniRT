/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxi <wxi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 13:34:28 by lyvan-de          #+#    #+#             */
/*   Updated: 2026/01/27 14:46:12 by wxi              ###   ########.fr       */
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
		// In unit space, cylinder extends from -1 to 1 in y direction
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

t_tuple	color_obj(t_hit *hit, t_world *world, t_tuple *unit_norm)
{
	t_tuple	unit_hit_p;
	t_tuple	world_hit_p;
	t_tuple	norm_unit;
	t_tuple	norm_world;
	t_tuple	color;
	double	intensity;

	unit_hit_p = tuple_add(hit->ray.origin, tuple_mult(hit->ray.direction,
				hit->t));
	world_hit_p = matxtuple(hit->object->transform, unit_hit_p);
	if (unit_norm)
		norm_unit = *unit_norm;
	else
		norm_unit = normal_object(hit, unit_hit_p);
	norm_world = matxtuple(transpose_mat(hit->object->inv_transform),
			norm_unit);
	norm_world.w = 0;
	norm_world = tuple_norm(norm_world);
	intensity = light_intensity(world_hit_p, norm_world, world, hit->object);
	color = get_color(hit->object, world->ambient, intensity);
	return (color);
}

t_tuple	get_rgb(t_ray *world_ray, t_list *object, t_context *context)
{
	t_tuple		rgb;
	t_hit		hit;
	t_cylinder	*cy;
	t_tuple		norm;

	hit = hit_object(world_ray, object, NULL);
	if (hit.object == NULL)
	{
		// hit.t = 0.5 * (world_ray->direction.y + 1);
		// rgb.x = ((1.0 - hit.t) * 255 + hit.t * 127) / 255;
		// rgb.y = ((1.0 - hit.t) * 255 + hit.t * 178) / 255;
		// rgb.z = 255 / 255;
		rgb.x = 0;
		rgb.y = 0;
		rgb.z = 0;
		return (rgb);
	}
	if (hit.object->type == CYLINDER)
	{
		cy = (t_cylinder *)hit.object;
		if (cy->hit_location == TOP)
		{
			norm = new_tuple(0, 1, 0, 0);
			rgb = color_obj(&hit, context->world, &norm);
		}
		else if (cy->hit_location == BOTTOM)
		{
			norm = new_tuple(0, -1, 0, 0);
			rgb = color_obj(&hit, context->world, &norm);
		}
		else
		{
			// Hit on the side of the cylinder
			rgb = color_obj(&hit, context->world, NULL);
		}
	}
	else
		rgb = color_obj(&hit, context->world, NULL);
	return (rgb);
}
