/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a12708 <a12708@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:38:19 by lyvan-de          #+#    #+#             */
/*   Updated: 2026/01/17 23:24:05 by a12708           ###   ########.fr       */
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


t_tuple color_sphere(t_sphere *sph, t_ray *world_ray, double t, t_world *world)
{
    t_tuple unit_hit_p;
    t_tuple world_hit_p;
    t_tuple norm_unit;
    t_tuple norm_world;
    t_tuple color;
    double intensity;
    // t_ambient amb;

    // 1. Hit point in object space
    unit_hit_p = tuple_add(
        world_ray->origin,       // <- should this be the object-space ray?
        tuple_mult(world_ray->direction, t)
    );

    // 2. Hit point in world space
    world_hit_p = matXtuple(sph->transform, unit_hit_p);

    // 3. Normal in object space (from center to hit point)
    norm_unit = tuple_sub(unit_hit_p, new_tuple(0,0,0,1));
    norm_unit.w = 0;
    norm_unit = tuple_norm(norm_unit);

    // 4. Normal in world space
    norm_world = matXtuple(transpose_mat(sph->inv_transform), norm_unit);
    norm_world.w = 0;
    norm_world = tuple_norm(norm_world);

    // 5. Lighting
    intensity = light_intensity(world_hit_p, norm_world, world);
    
    // Ambient light: object_color * ambient_color * ambient_ratio
    // Diffuse light: object_color * diffuse_intensity
    // Combined: object_color * (ambient_color * ambient_ratio + diffuse_intensity)
    double obj_r = sph->color.r / 255.0;
    double obj_g = sph->color.g / 255.0;
    double obj_b = sph->color.b / 255.0;
    
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

t_tuple	get_rgb(t_ray *world_ray, t_list *object, t_context *context)
{
	double		unit_t;
	double		smallest_t;
	t_tuple		rgb;
	t_sphere	*sph;
	int			closest_obj = -1;
	t_list		*current_obj;
	t_sphere	*closest_sph;
	t_ray		unit_ray;
	
	(void)context;
	current_obj = object;
	unit_t = INFINITY;
	smallest_t = INFINITY;
	closest_sph = NULL;
	while (current_obj != NULL)
	{
		if (current_obj->type == SPHERE)
		{
			sph = (t_sphere *)current_obj->content;
			unit_ray = transform_ray(*world_ray, sph->inv_transform);
			unit_t = intersect_unit_sphere(&unit_ray);
		}
		if (unit_t > 0 && unit_t < smallest_t)
		{
			smallest_t = unit_t;
			closest_obj = current_obj->id;
			closest_sph = sph;
		}
		current_obj = current_obj->next;
	}
	if (closest_obj == -1)
	{
		unit_t = 0.5 * (world_ray->direction.y + 1);
		rgb.x = ((1.0 - unit_t) * 255 + unit_t * 127) / 255;
		rgb.y = ((1.0 - unit_t) * 255 + unit_t * 178) / 255;
		rgb.z = 255 / 255;
	}
	else
		// rgb = color_sphere(closest_sph, &unit_ray, unit_t, context->world);
	{
		unit_ray = transform_ray(*world_ray, closest_sph->inv_transform);
		rgb = color_sphere(closest_sph, &unit_ray, smallest_t, context->world);
	}
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
