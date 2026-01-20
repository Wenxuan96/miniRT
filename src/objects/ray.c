/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyvan-de <lyvan-de@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:38:19 by lyvan-de          #+#    #+#             */
/*   Updated: 2026/01/20 18:16:18 by lyvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/miniRT.h"

double	light_intensity(t_tuple hit_point, t_tuple norm_hit_point, t_world *world)
{
	t_tuple		light_direction;
	double		light_intensity;
	t_light		li;
	
	li = world->light;
	light_direction = tuple_sub(li.origin, hit_point);
	light_direction = tuple_norm(light_direction);
	light_intensity = fmax(0.0, tuple_dot(norm_hit_point, light_direction)) * li.ratio;
	return (light_intensity);
}

// t_tuple	ambient_rgb(t_world	scene)
// {
// 	t_tuple		rgb;

// 	rgb.x = scene.ambient.ratio * scene.ambient.color.r;
// 	rgb.y = scene.ambient.ratio * scene.ambient.color.g;
// 	rgb.z = scene.ambient.ratio * scene.ambient.color.b;
// 	return (rgb);
// }

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

// t_tuple color_sphere(t_sphere *sph, t_ray *world_ray, double t)
// {
//     t_tuple world_hit_p;
//     t_tuple unit_hit_p;
//     t_tuple norm_unit;
//     t_tuple norm_world;
//     t_tuple color;

//     world_hit_p = tuple_add(
//         world_ray->origin,
//         tuple_mult(world_ray->direction, t)
//     );
//     unit_hit_p = matXtuple(sph->inv_transform, world_hit_p);
// 	norm_unit = tuple_sub(unit_hit_p, new_tuple(0,0,0,1));
// 	norm_unit.w = 0;
// 	norm_unit = tuple_norm(norm_unit);
//     norm_world = matXtuple(
//         transpose_mat(sph->inv_transform),
//         norm_unit
//     );
//     norm_world.w = 0;
//     norm_world = tuple_norm(norm_world);
//     color.x = sph->color.r / 255.0;
//     color.y = sph->color.g / 255.0;
//     color.z = sph->color.b / 255.0;
//     color.w = 0;
//     return color;
// }

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

t_tuple color_sphere(t_hit *hit, t_world *world)
{
    t_tuple 	unit_hit_p;
    t_tuple 	world_hit_p;
    t_tuple 	norm_unit;
    t_tuple 	norm_world;
    t_tuple 	color;
    double		intensity;

    // 1. Hit point in object space
    unit_hit_p = tuple_add(
        hit->ray.origin,       // <- should this be the object-space ray?
        tuple_mult(hit->ray.direction, hit->t)
    );

    // 2. Hit point in world space
    world_hit_p = matXtuple(hit->object->transform, unit_hit_p);

    // 3. Normal in object space (from center to hit point)
    norm_unit = normal_object(hit->object, unit_hit_p);

    // 4. Normal in world space
    norm_world = matXtuple(transpose_mat(hit->object->inv_transform), norm_unit);
    norm_world.w = 0;
    norm_world = tuple_norm(norm_world);

    // 5. Lighting
    intensity = light_intensity(world_hit_p, norm_world, world);
    
    // Ambient light: object_color * ambient_color * ambient_ratio
    // Diffuse light: object_color * diffuse_intensity
    // Combined: object_color * (ambient_color * ambient_ratio + diffuse_intensity)
    double obj_r = hit->object->color.r / 255.0;
    double obj_g = hit->object->color.g / 255.0;
    double obj_b = hit->object->color.b / 255.0;
    
    double amb_r = (world->ambient.color.r / 255.0) * world->ambient.ratio;
    double amb_g = (world->ambient.color.g / 255.0) * world->ambient.ratio;
    double amb_b = (world->ambient.color.b / 255.0) * world->ambient.ratio;
    
    // Apply ambient and diffuse: object_color * (ambient + diffuse)
    // Clamp to ensure values stay in [0,1] range
    color.x = fmin(1.0, obj_r * (amb_r + intensity));
    color.y = fmin(1.0, obj_g * (amb_g + intensity));
    color.z = fmin(1.0, obj_b * (amb_b + intensity));
    color.w = 0;

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

//double	unit_plane(void)
//{
	
//}

//double	unit_cylinder(void)
//{
	
//}

t_hit	hit_object(t_ray *world_ray, t_list *object)
{
	t_hit		hit;
	t_list		*current_obj;
	t_object	*obj_base;
	double		t;
	t_ray		unit_ray;
	
	t = -1;
	current_obj = object;
	hit.t = INFINITY;
	hit.object = NULL;
	while (current_obj != NULL)
	{
		obj_base = current_obj->content;
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

	hit = hit_object(world_ray, object);
	if (hit.object == NULL)
	{
		hit.t = 0.5 * (world_ray->direction.y + 1);
		rgb.x = ((1.0 - hit.t) * 255 + hit.t * 127) / 255;
		rgb.y = ((1.0 - hit.t) * 255 + hit.t * 178) / 255;
		rgb.z = 255 / 255;
	}
	else
		rgb = color_sphere(&hit, context->world);
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
