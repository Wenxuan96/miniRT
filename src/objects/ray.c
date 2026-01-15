/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyvan-de <lyvan-de@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:38:19 by lyvan-de          #+#    #+#             */
/*   Updated: 2026/01/15 12:02:34 by lyvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/miniRT.h"

double	light_intensity(t_tuple hit_point, t_tuple norm_hit_point, t_light li)
{
	t_tuple		light_direction;
	double		light_intensity;

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
    if (t1 > EPSILON && t2 > EPSILON)
        return fmin(t1, t2);
    if (t1 > EPSILON)
        return t1;
    if (t2 > EPSILON)
        return t2;
    return (-1);
}

t_tuple	color_sphere(t_sphere *sphere, t_ray *ray, t_light li)
{
	t_tuple	hit_point;
	t_tuple	norm_hit_point;
	t_tuple	color;
	double	t;
	// t_tuple	ambient;

	t = select_t(ray->hit_points[0], ray->hit_points[1]);
	if (t == -1)
		return (new_tuple(0,0,0,0));
	hit_point = tuple_add(ray->origin, tuple_mult(ray->direction, t));
	norm_hit_point = tuple_norm(tuple_sub(hit_point, sphere->position));
	color.x = (sphere->color.r / 255) * light_intensity(hit_point, norm_hit_point, li);
	color.y = (sphere->color.g / 255) * light_intensity(hit_point, norm_hit_point, li);
	color.z = (sphere->color.b / 255) * light_intensity(hit_point, norm_hit_point, li);
	return (color);
}

t_tuple	find_dir(t_viewport view, t_camera cam, int x, int y)
{
	t_tuple	pixel;
	t_tuple	ray_dir;

	// Ensure pixel deltas are vectors
	view.pixel_delta_u.w = 0;
	view.pixel_delta_v.w = 0;

	// Ensure upper_left is a point
	view.upper_left.w = 1;

	// Compute pixel position on the viewport (a POINT)
	pixel = tuple_add(
		view.upper_left,
		tuple_add(
			tuple_mult(view.pixel_delta_u, x + 0.5),
			tuple_mult(view.pixel_delta_v, y + 0.5)
		)
	);
	pixel.w = 1;

	// Direction = point - point => VECTOR
	ray_dir = tuple_sub(pixel, cam.position);
	ray_dir.w = 0;

	return (tuple_norm(ray_dir));
}

//t_sphere	unit_sphere(void)
//{
	
//}

//t_sphere	unit_plane(void)
//{
	
//}

//t_sphere	unit_cylinder(void)
//{
	
//}

//double transform(t_ray org_r, void *obj_type)
//{
	
//}

t_tuple	get_rgb(t_ray *ray, t_list *object, t_context *context)
{
	double		t;
	double		smallest_t;
	t_tuple		rgb;
	t_sphere	*sph;
	int			closest_obj = -1;
	t_list		*current_obj;
	t_sphere	*closest_sph;
	
	// find closest object
	current_obj = object;
	t = INFINITY;
	smallest_t = INFINITY;
	closest_sph = NULL;
	while (current_obj != NULL)
	{
		if (current_obj->type == SPHERE)
		{
			sph = (t_sphere *)current_obj->content;
			hit_sphere(ray, sph);
			t = select_t(ray->hit_points[0], ray->hit_points[1]);
		}
		if (t > 0 && t < smallest_t)
		{
			smallest_t = t;
			closest_obj = current_obj->id;
			closest_sph = sph;
			printf("closest ID: %i\n", closest_obj);
			printf("closest t: %f\n", t);
		}
		current_obj = current_obj->next;
	}
	//calculate the color, if no hittable object ->background color
	//for the closest object, do the matrixtransformations needed for the closest object
	//make a t_tuple?double transform(t_ray org_r, void *obj_type); function
	if (closest_sph == NULL)
	{
		t = 0.5 * (ray->direction.y + 1);
		rgb.x = ((1.0 - t) * 255 + t * 127) / 255;
		rgb.y = ((1.0 - t) * 255 + t * 178) / 255;
		rgb.z = 255 / 255;
	}
	else
		//sph = find_obj_id(object, closest_obj);
		rgb = color_sphere(closest_sph, ray, context->world->light);
		//rgb = color_sphere(*change sph to unit_sph*, ray, context->world->light);
	return (rgb);
}

int	ray_color(t_context	*context, int x, int y)
{
	int		color;
	t_tuple	vec_rgb;
	t_rgb	rgb;
	t_ray	*ray;

	ray = malloc(sizeof (t_ray));
    ray->direction = find_dir(context->world->view, context->world->camera, x, y);
	ray->hit_count = 0;
	ray->hit_points[0] = 0;
	ray->hit_points[1] = 0;

	// printf("x:%d, y:%d\nrdir: %f, %f, %f, %f\n", x, y, ray_dir.x, ray_dir.y, ray_dir.z, ray_dir.w);
    ray->origin = context->world->camera.position;
	vec_rgb = get_rgb(ray, context->world->objects, context);
	// make it  0-255 again
	//rgb.r = (int)fmin(255, fmax(0, vec_rgb.x));
	//rgb.g = (int)fmin(255, fmax(0, vec_rgb.y));
	//rgb.b = (int)fmin(255, fmax(0, vec_rgb.z));
	rgb.r = (int)((vec_rgb.x) * 255);
	rgb.g = (int)((vec_rgb.y) * 255);
	rgb.b = (int)((vec_rgb.z) * 255);
	color = get_rgba(rgb.r, rgb.g, rgb.b, 255);
	return (color);
}
