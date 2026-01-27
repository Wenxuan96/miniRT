/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxi <wxi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 13:34:28 by lyvan-de          #+#    #+#             */
/*   Updated: 2026/01/27 16:23:17 by wxi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/miniRT.h"

t_tuple	color_obj(t_hit *hit, t_world *world, t_tuple *unit_norm)
{
	t_tuple	unit_hit_p;
	t_tuple	world_hit_p;
	t_tuple	norm_unit;
	t_tuple	norm_world;
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
	return (get_color(hit->object, world->ambient, intensity));
}

t_tuple	cy_rgb(t_cylinder *cy, t_hit hit, t_context *context)
{
	t_tuple	norm;
	t_tuple	rgb;

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
		rgb = color_obj(&hit, context->world, NULL);
	return (rgb);
}

t_tuple	get_rgb(t_ray *world_ray, t_list *object, t_context *context)
{
	t_tuple		rgb;
	t_hit		hit;
	t_cylinder	*cy;

	hit = hit_object(world_ray, object, NULL);
	if (hit.object == NULL)
	{
		rgb.x = 0;
		rgb.y = 0;
		rgb.z = 0;
		return (rgb);
	}
	if (hit.object->type == CYLINDER)
	{
		cy = (t_cylinder *)hit.object;
		rgb = cy_rgb(cy, hit, context);
	}
	else
		rgb = color_obj(&hit, context->world, NULL);
	return (rgb);
}
