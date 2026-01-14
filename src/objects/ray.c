/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxi <wxi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:38:19 by lyvan-de          #+#    #+#             */
/*   Updated: 2026/01/13 15:31:12 by wxi              ###   ########.fr       */
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

t_tuple	color_sphere(t_sphere *sphere, t_ray ray, double t, t_light li)
{
	t_tuple	hit_point;
	t_tuple	norm_hit_point;
	t_tuple	color;

	hit_point = tuple_add(ray.origin, tuple_mult(ray.direction, t));
	norm_hit_point = tuple_norm(tuple_sub(hit_point, sphere->position));
	color.x = sphere->color.r * light_intensity(hit_point, norm_hit_point, li);
	color.y = sphere->color.g * light_intensity(hit_point, norm_hit_point, li);
	color.z = sphere->color.b * light_intensity(hit_point, norm_hit_point, li);
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

t_tuple	get_rgb(t_ray ray, void *object, t_context *context)
{
	double		t;
	t_tuple		rgb;
	t_sphere	*sph;

    t = 0.0;
	sph = (t_sphere *)object;
	hit_sphere(ray, sph);
	if (sph->hit_count == 0)
	{
		t = 0.5 * (ray.direction.y + 1);
		rgb.x = ((1.0 - t) * 255 + t * 127) / 255;
		rgb.y = ((1.0 - t) * 255 + t * 178) / 255;
		rgb.z = 255 / 255;
	}
	else
		rgb = color_sphere(sph, ray, t, context->world->light);
	return (rgb);
}

int	ray_color(t_context	*context, int x, int y)
{
	int		color;
	t_tuple	ray_dir;
	t_tuple	vec_rgb;
	t_rgb	rgb;
    t_ray   ray;

	ray_dir = find_dir(context->world->view, context->world->camera, x, y);
    ray.direction = ray_dir;
	// printf("x:%d, y:%d\nrdir: %f, %f, %f, %f\n", x, y, ray_dir.x, ray_dir.y, ray_dir.z, ray_dir.w);
    ray.origin = context->world->camera.position;
	vec_rgb = get_rgb(ray, context->world->objects->content, context);
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
