/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_copy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxi <wxi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:38:19 by lyvan-de          #+#    #+#             */
/*   Updated: 2025/12/10 15:50:03 by wxi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/miniRT.h"

double	light_intensity(t_vec3 hit_point, t_vec3 norm_hit_point)
{
	t_vec3		light_direction;
	double		light_intensity;
	t_light		*li;

	li = light();
	light_direction = vec3_sub(li->origin, hit_point);
	light_direction = vec3_norm(light_direction);
	light_intensity = fmax(0.0, vec3_dot(norm_hit_point, light_direction)) * li->ratio;
	return (light_intensity);
}

t_vec3	ambient_rgb(void)//incorrect neeed to modify
{
	t_ambient	*amb;
	t_vec3		rgb;

	amb = ambient();
	rgb.x = amb->ratio * amb->color.x;
	rgb.y = amb->ratio * amb->color.y;
	rgb.z = amb->ratio * amb->color.z;
	return (rgb);
}

t_vec3	color_sphere(t_sphere *sphere, t_vec3 ray, double t, t_camera *cam)
{
	t_vec3	hit_point;
	t_vec3	norm_hit_point;
	t_vec3	color;
	t_vec3	ambient;

	hit_point = vec3_add(cam->position, vec3_mult(ray, t));
	norm_hit_point = vec3_norm(vec3_sub(hit_point, sphere->position));
	ambient = ambient_rgb();
	color.x = sphere->color.x * light_intensity(hit_point, norm_hit_point);
	color.y = sphere->color.y * light_intensity(hit_point, norm_hit_point);
	color.z = sphere->color.z * light_intensity(hit_point, norm_hit_point);
	return (color);
}

// returns the distance to the camera and the point where you hit the sphere
double	hit_sphere(t_vec3 ray, t_camera *cam, t_sphere	*sph)
{
	t_vec3		origin_center;
	double		a;
	double		b;
	double		c;
	double		radius;
	double		discriminant;

	radius = sph->diameter / 2;
	origin_center = vec3_sub(cam->position, sph->position);
	a = vec3_dot(ray, ray);
	b = 2.0 * vec3_dot(ray, origin_center);
	c = vec3_dot(origin_center, origin_center) - (radius * radius);
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		return (-1.0);
	else
		return ((-b - sqrt(discriminant)) / (2.0 * a));
}

t_vec3	find_dir(t_viewport *view, t_camera *cam, int x, int y)
{
	t_vec3	center;
	t_vec3	u_offset;
	t_vec3	v_offset;
	t_vec3	temp;
	t_vec3	ray_dir;

	u_offset = vec3_mult(view->pixel_delta_u, (double)x + 0.5);
	v_offset = vec3_mult(view->pixel_delta_v, 0.5 + (double)y);
	temp = vec3_add(view->upper_left, u_offset);
	center = vec3_add(temp, v_offset);
	ray_dir = vec3_sub(center, cam->position);
	ray_dir = vec3_norm(ray_dir);
	return (ray_dir);
}

t_vec3	get_rgb(t_vec3 ray_dir, t_camera *cam)
{
	double		t;
	t_vec3		rgb;
	t_sphere	*sph;

	sph = sphere();
	t = hit_sphere(ray_dir, cam, sph);
	if (t <= 0.0)
	{
		t = 0.5 * (ray_dir.y + 1);
		rgb.x = (unsigned char)((1.0 - t) * 255 + t * 127);
		rgb.y = (unsigned char)((1.0 - t) * 255 + t * 178);
		rgb.z = 255;
	}
	else
		rgb = color_sphere(sph, ray_dir, t, cam);
	return (rgb);
}

int	ray_color(t_context	*context, int x, int y)
{
	int		color;
	t_vec3	ray_dir;
	t_vec3	vec_rgb;
	t_rgb	rgb;

	ray_dir = find_dir(context->view, context->cam, x, y);
	vec_rgb = get_rgb(ray_dir, context->cam);
	// make it  0-255 again
	rgb.r = (int)fmin(255, fmax(0, vec_rgb.x * 255));
	rgb.g = (int)fmin(255, fmax(0, vec_rgb.y * 255));
	rgb.b = (int)fmin(255, fmax(0, vec_rgb.z * 255));
	color = get_rgba(rgb.r, rgb.g, rgb.b, 255);
	return (color);
}