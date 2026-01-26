/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_objects.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxi <wxi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 13:34:17 by lyvan-de          #+#    #+#             */
/*   Updated: 2026/01/26 16:25:05 by wxi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/miniRT.h"

double select_t(double t1, double t2)
{
	if (t1 == t2)
		return (t1);
	if (t1 > EPSILON && t2 > EPSILON)
		return fmin(t1, t2);
	if (t1 > EPSILON)
		return t1;
	if (t2 > EPSILON)
		return t2;
	return (-1);
}

double	world_distance(t_object	*object, double t, t_ray unit_ray, t_ray *world_ray)
{
	double	distance;
	t_tuple	obj_point;
	t_tuple	world_point;

	obj_point = tuple_add(unit_ray.origin, tuple_mult(unit_ray.direction, t));
	obj_point.w = 1;
	world_point = matXtuple(object->transform, obj_point);
	distance = tuple_length(tuple_sub(world_point, world_ray->origin));
	return (distance);
}

t_hit	hit_object(t_ray *world_ray, t_list *object, t_object *ignore)
{
	t_hit		hit;
	t_list		*current_obj;
	t_object	*obj_base;
	double		t;
	t_ray		unit_ray;
	double		distance;
	double		shortest_distance;
	
	current_obj = object;
	shortest_distance = INFINITY;
	hit.object = NULL;
	while (current_obj != NULL)
	{
		t = -1;
		obj_base = current_obj->content;
		if (obj_base == ignore)
		{
			current_obj = current_obj->next;
			continue ;
		}
		unit_ray = transform_ray(*world_ray, obj_base->inv_transform);
		if (obj_base->type == SPHERE)
			t = intersect_unit_sphere(&unit_ray);
		if (obj_base->type == PLANE)
			t = intersect_unit_plane(&unit_ray);
		if (obj_base->type == CYLINDER)
			t = intersect_unit_cylinder(&unit_ray, (t_cylinder *)current_obj->content);
		if (t > 0)
		{
			distance = world_distance(obj_base, t, unit_ray, world_ray);
			if (distance < shortest_distance)
			{
				hit.object = obj_base;
				hit.ray = unit_ray;
				hit.t = t;
				hit.world_dist = distance;
				shortest_distance = distance;
			}
		}
		current_obj = current_obj->next;
	}
	return hit;
}
