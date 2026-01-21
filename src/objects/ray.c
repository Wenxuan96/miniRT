/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyvan-de <lyvan-de@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:38:19 by lyvan-de          #+#    #+#             */
/*   Updated: 2026/01/21 16:35:43 by lyvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/miniRT.h"

t_hit	hit_object(t_ray *world_ray, t_list *object, t_object *ingore);

double	light_intensity(t_tuple hit_point, t_tuple norm_hit_point, t_world *world, t_object *curr_obj)
{
	t_tuple		light_direction;
	double		light_intensity;
	t_light		li;
	double		distance_to_light;
	t_ray		shadow_ray;
	t_hit		hit;
	
	li = world->light;
	light_direction = tuple_sub(li.origin, hit_point);
	distance_to_light = sqrt(tuple_dot(light_direction, light_direction));
	light_direction = tuple_norm(light_direction);
	light_intensity = fmax(0.0, tuple_dot(norm_hit_point, light_direction)) * li.ratio;
	shadow_ray.origin = tuple_add(hit_point, tuple_mult(norm_hit_point, EPSILON));
	shadow_ray.direction = light_direction;
	hit = hit_object(&shadow_ray, world->objects, curr_obj);
	if (hit.object == NULL)
		return (light_intensity);
	t_tuple shadow_hit_unit =
    tuple_add(hit.ray.origin, tuple_mult(hit.ray.direction, hit.t));
	t_tuple shadow_hit_world =
    matXtuple(hit.object->transform, shadow_hit_unit);
	t_tuple dist_to_hit = tuple_sub(shadow_hit_world, hit_point);
	double lenght_to_hit = sqrt(tuple_dot(dist_to_hit, dist_to_hit));
	if (hit.object != NULL && lenght_to_hit < distance_to_light)
		return (0);
	return (light_intensity);
}

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

t_tuple	normal_object(t_object *obj, t_tuple unit_hit_p)
{
	t_tuple	norm_unit;
	t_plane	*plane;

	norm_unit = new_tuple(0,0,0,0);
	if (obj->type == SPHERE)
	{
		norm_unit = tuple_sub(unit_hit_p, new_tuple(0,0,0,1));
   		norm_unit.w = 0;
    	norm_unit = tuple_norm(norm_unit);
	}
	else if (obj->type == PLANE)
	{
		plane = (t_plane *)obj;
		norm_unit = plane->normal;
	}
	else if (obj->type == CYLINDER)
	{
		norm_unit = new_tuple(unit_hit_p.x, 0, unit_hit_p.z, 0);
		norm_unit = tuple_norm(norm_unit);
	}
	return norm_unit;
}

t_tuple	get_color(t_object *obj, t_ambient world_amb, double intensity)
{
	t_tuple amb_rgb;
	t_tuple	obj_color;
	t_tuple	rt_color;

	amb_rgb.x = world_amb.color.r/255.0 * world_amb.ratio;
	amb_rgb.y = world_amb.color.g/255.0 * world_amb.ratio;
	amb_rgb.z = world_amb.color.b/255.0 * world_amb.ratio;
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

t_tuple color_obj(t_hit *hit, t_world *world)
{
    t_tuple 	unit_hit_p;
    t_tuple 	world_hit_p;
    t_tuple 	norm_unit;
    t_tuple 	norm_world;
    t_tuple 	color;
    double		intensity;

	unit_hit_p = tuple_add( hit->ray.origin, tuple_mult(hit->ray.direction, hit->t));
	world_hit_p = matXtuple(hit->object->transform, unit_hit_p);
	norm_unit = normal_object(hit->object, unit_hit_p);
	norm_world = matXtuple(transpose_mat(hit->object->inv_transform), norm_unit);
	norm_world.w = 0;
	norm_world = tuple_norm(norm_world);
	intensity = light_intensity(world_hit_p, norm_world, world, hit->object);
	color = get_color(hit->object, world->ambient, intensity);
	return color;
}

t_tuple	find_dir(t_viewport view, t_camera cam, int x, int y)
{
	t_tuple	pixel;
	t_tuple	ray_dir;

	view.pixel_delta_u.w = 0;
	view.pixel_delta_v.w = 0;
	view.upper_left.w = 1;
	pixel = tuple_add(
		view.upper_left,
		tuple_add(
			tuple_mult(view.pixel_delta_u, x + 0.5),
			tuple_mult(view.pixel_delta_v, y + 0.5)
		)
	);
	pixel.w = 1;
	ray_dir = tuple_sub(pixel, cam.position);
	ray_dir.w = 0;

	return (tuple_norm(ray_dir));
}

t_hit	hit_object(t_ray *world_ray, t_list *object, t_object *ignore)
{
	t_hit		hit;
	t_list		*current_obj;
	t_object	*obj_base;
	double		t;
	t_ray		unit_ray;
	
	current_obj = object;
	hit.t = INFINITY;
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
		//if (obj_base->type == CYLINDER)
		//	hit.t = intersect_unit_cylinder(&unit_ray);
		if (t > 0 && t < hit.t)
		{
			hit.object = obj_base;
			hit.ray = unit_ray;
			hit.t = t;
		}
		current_obj = current_obj->next;
	}
	return hit;
}

t_tuple	get_rgb(t_ray *world_ray, t_list *object, t_context *context)
{
	t_tuple	rgb;
	t_hit	hit;

	hit = hit_object(world_ray, object, NULL);
	if (hit.object == NULL)
	{
		hit.t = 0.5 * (world_ray->direction.y + 1);
		rgb.x = ((1.0 - hit.t) * 255 + hit.t * 127) / 255;
		rgb.y = ((1.0 - hit.t) * 255 + hit.t * 178) / 255;
		rgb.z = 255 / 255;
	}
	else
		rgb = color_obj(&hit, context->world);
	return (rgb);
}

int	ray_color(t_context	*context, int x, int y)
{
	int		color;
	t_tuple	vec_rgb;
	t_rgb	rgb;
	t_ray	*world_ray;

	world_ray = malloc(sizeof (t_ray));
    world_ray->direction = find_dir(context->world->view, context->world->camera, x, y);
	world_ray->origin = context->world->camera.position;
	world_ray->hit_points[0] = 0;
	world_ray->hit_points[1] = 0;

	vec_rgb = get_rgb(world_ray, context->world->objects, context);
	free(world_ray);
	world_ray = NULL;
	rgb.r = (int)((vec_rgb.x) * 255);
	rgb.g = (int)((vec_rgb.y) * 255);
	rgb.b = (int)((vec_rgb.z) * 255);
	color = get_rgba(rgb.r, rgb.g, rgb.b, 255);
	return (color);
}
