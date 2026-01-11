/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a12708 <a12708@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:38:19 by lyvan-de          #+#    #+#             */
/*   Updated: 2026/01/11 22:35:56 by a12708           ###   ########.fr       */
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

// t_tuple	ambient_rgb(void)//incorrect neeed to modify
// {
// 	t_ambient	*amb;
// 	t_tuple		rgb;

// 	amb = ambient();
// 	rgb.x = amb->ratio * amb->color.x;
// 	rgb.y = amb->ratio * amb->color.y;
// 	rgb.z = amb->ratio * amb->color.z;
// 	return (rgb);
// }

t_tuple	color_sphere(t_sphere *sphere, t_ray ray, double t, t_light li)
{
	t_tuple	hit_point;
	t_tuple	norm_hit_point;
	t_tuple	color;
	// t_tuple	ambient;

	hit_point = tuple_add(ray.origin, tuple_mult(ray.direction, t));
	norm_hit_point = tuple_norm(tuple_sub(hit_point, sphere->position));
	// ambient = ambient_rgb();
	//printf("sphere color (x = %f, y = %f, z = %f)\n", sphere->color.x, sphere->color.y ,sphere->color.z);
	color.x = sphere->color.r * light_intensity(hit_point, norm_hit_point, li);
	color.y = sphere->color.g * light_intensity(hit_point, norm_hit_point, li);
	color.z = sphere->color.b * light_intensity(hit_point, norm_hit_point, li);
	return (color);
}

// returns the distance to the camera and the point where you hit the sphere
// double	hit_sphere(t_tuple ray, t_camera cam, t_sphere	*sph)
// {
// 	t_tuple		origin_center;
// 	double		a;
// 	double		b;
// 	double		c;
// 	double		radius;
// 	double		discriminant;

// 	radius = sph->diameter / 2;
// 	origin_center = tuple_sub(cam.position, sph->position);
// 	a = tuple_dot(ray, ray);
// 	b = 2.0 * tuple_dot(ray, origin_center);
// 	c = tuple_dot(origin_center, origin_center) - (radius * radius);
// 	discriminant = b * b - 4 * a * c;
// 	if (discriminant < 0)
// 		return (-1.0);
// 	else
// 		return ((-b - sqrt(discriminant)) / (2.0 * a));
// }

t_tuple	find_dir(t_viewport view, t_camera cam, int x, int y)
{
	t_tuple	center;
	t_tuple	u_offset;
	t_tuple	v_offset;
	t_tuple	temp;
	t_tuple	ray_dir;

	u_offset = tuple_mult(view.pixel_delta_u, (double)x + 0.5);
	v_offset = tuple_mult(view.pixel_delta_v, 0.5 + (double)y);
	temp = tuple_add(view.upper_left, u_offset);
	center = tuple_add(temp, v_offset);
	ray_dir = tuple_sub(center, cam.position);
	ray_dir = tuple_norm(ray_dir);
	return (ray_dir);
}

t_tuple	get_rgb(t_ray ray, void *object, t_context *context)
{
	double		t;
	t_tuple		rgb;
	t_sphere	*sph;

    t = 0.0;
	sph = (t_sphere *)object;
	hit_sphere(ray, sph);
	if (sph->hit_points[0])
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
