/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyvan-de <lyvan-de@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 13:34:26 by lyvan-de          #+#    #+#             */
/*   Updated: 2026/01/24 15:13:37 by lyvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/miniRT.h"

bool	in_shadow(t_ray shadow_ray, t_object *obj, t_world *world)
{
	t_hit	shadow_hit;
	double	distance_to_light;

	shadow_hit = hit_object(&shadow_ray, world->objects, obj);
	if (shadow_hit.object == NULL)
		return (false);
	distance_to_light = tuple_lenght(
			tuple_sub(world->light.origin, shadow_ray.origin));
	if (shadow_hit.object != NULL && shadow_hit.world_dist < distance_to_light)
		return (true);
	return (false);
}

double	light_intensity(t_tuple hit_point, t_tuple norm_hp,
	t_world *world, t_object *obj)
{
	t_tuple		light_direction;
	double		light_intensity;
	t_light		li;
	t_ray		shadow_ray;
	double		distance_to_light;

	li = world->light;
	light_direction = tuple_sub(li.origin, hit_point);
	light_direction = tuple_norm(light_direction);
	light_intensity = fmax(0.0, tuple_dot(norm_hp, light_direction))
		* li.ratio;
	distance_to_light = tuple_lenght(light_direction);
	shadow_ray.origin = tuple_add(hit_point, tuple_mult(norm_hp, EPSILON));
	shadow_ray.direction = light_direction;
	if (in_shadow(shadow_ray, obj, world))
		return (0);
	return (light_intensity);
}
