/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_copy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxi <wxi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:38:19 by lyvan-de          #+#    #+#             */
/*   Updated: 2025/12/19 19:48:33 by wxi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/miniRT.h"

double	light_intensity(t_vec4 hit_point, t_vec4 norm_hit_point)
{
	t_vec4		light_direction;
	double		light_intensity;
	t_light		*li;

	li = light();
	light_direction = vec4_sub(li->origin, hit_point);
	light_direction = vec4_norm(light_direction);
	light_intensity = fmax(0.0, vec4_dot(norm_hit_point, light_direction)) * li->ratio;
	return (light_intensity);
}

t_vec4	ambient_rgb(void)//incorrect neeed to modify
{
	t_ambient	*amb;
	t_vec4		rgb;

	amb = ambient();
	rgb.x = amb->ratio * amb->color.x;
	rgb.y = amb->ratio * amb->color.y;
	rgb.z = amb->ratio * amb->color.z;
	return (rgb);
}

t_vec4	color_sphere(t_sphere *sphere, t_vec4 ray, double t, t_camera *cam)
{
	t_vec4	hit_point;
	t_vec4	norm_hit_point;
	t_vec4	color;
	// t_vec4	ambient;

	hit_point = vec4_add(cam->position, vec4_mult(ray, t));
	norm_hit_point = vec4_norm(vec4_sub(hit_point, sphere->position));
	// ambient = ambient_rgb();
	//printf("sphere color (x = %f, y = %f, z = %f)\n", sphere->color.x, sphere->color.y ,sphere->color.z);
	color.x = sphere->color.x * light_intensity(hit_point, norm_hit_point);
	color.y = sphere->color.y * light_intensity(hit_point, norm_hit_point);
	color.z = sphere->color.z * light_intensity(hit_point, norm_hit_point);
	return (color);
}

// returns the distance to the camera and the point where you hit the sphere
double	hit_sphere(t_vec4 ray, t_camera *cam, t_sphere	*sph)
{
	t_vec4		origin_center;
	double		a;
	double		b;
	double		c;
	double		radius;
	double		discriminant;

	radius = sph->diameter / 2;
	origin_center = vec4_sub(cam->position, sph->position);
	a = vec4_dot(ray, ray);
	b = 2.0 * vec4_dot(ray, origin_center);
	c = vec4_dot(origin_center, origin_center) - (radius * radius);
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		return (-1.0);
	else
		return ((-b - sqrt(discriminant)) / (2.0 * a));
}

t_vec4	find_dir(t_viewport *view, t_camera *cam, int x, int y)
{
	t_vec4	center;
	t_vec4	u_offset;
	t_vec4	v_offset;
	t_vec4	temp;
	t_vec4	ray_dir;

	u_offset = vec4_mult(view->pixel_delta_u, (double)x + 0.5);
	v_offset = vec4_mult(view->pixel_delta_v, 0.5 + (double)y);
	temp = vec4_add(view->upper_left, u_offset);
	center = vec4_add(temp, v_offset);
	ray_dir = vec4_sub(center, cam->position);
	ray_dir = vec4_norm(ray_dir);
	return (ray_dir);
}

t_vec4	get_rgb(t_vec4 ray_dir, t_camera *cam)
{
	double		t;
	t_vec4		rgb;
	t_sphere	*sph;

	sph = sphere();
	t = hit_sphere(ray_dir, cam, sph);
	if (t <= 0.0)
	{
		t = 0.5 * (ray_dir.y + 1);
		rgb.x = ((1.0 - t) * 255 + t * 127) / 255;
		rgb.y = ((1.0 - t) * 255 + t * 178) / 255;
		rgb.z = 255 / 255;
	}
	else
		rgb = color_sphere(sph, ray_dir, t, cam);
	return (rgb);
}

int	ray_color(t_context	*context, int x, int y)
{
	int		color;
	t_vec4	ray_dir;
	t_vec4	vec_rgb;
	t_rgb	rgb;

	ray_dir = find_dir(context->view, context->cam, x, y);
	vec_rgb = get_rgb(ray_dir, context->cam);
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