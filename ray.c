/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a12708 <a12708@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:38:19 by lyvan-de          #+#    #+#             */
/*   Updated: 2025/11/04 12:34:35 by a12708           ###   ########.fr       */
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

t_rgb	ambient_rgb(void)//incorrect neeed to modify
{
	t_ambient	*amb;
	t_rgb		rgb;

	amb = ambient();
	rgb.r = amb->ratio * amb->color.r;
	rgb.b = amb->ratio * amb->color.b;
	rgb.g = amb->ratio * amb->color.g;
	return (rgb);
}

t_rgb	color_sphere(t_sphere *sphere, t_vec3 ray, double t, t_camera *cam)
{
	t_vec3	hit_point;
	t_vec3	norm_hit_point;
	t_rgb	color;
	// t_rgb	ambient;

	hit_point = vec3_add(cam->position, vec3_mult(ray, t));
	norm_hit_point = vec3_norm(vec3_sub(hit_point, sphere->position));
	// ambient = ambient_rgb();
	color.r = sphere->color.r* light_intensity(hit_point, norm_hit_point);
	color.g = sphere->color.g* light_intensity(hit_point, norm_hit_point);
	color.b = sphere->color.b* light_intensity(hit_point, norm_hit_point);
	return (color);
}

// returns the distance to the camera and the point where you hit the sphere
double	hit_sphere(t_vec3 ray, t_camera *cam)
{
	t_sphere	*sph;
	t_vec3		origin_center;
	double		a;
	double		b;
	double		c;
	double		radius;
	double		discriminant;

	sph = sphere();
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

t_vec3	ray_dir(t_viewport *view, t_camera *cam, int x, int y)
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

t_rgb	ray_rgb(t_vec3 ray, t_camera *cam)
{
	double		t;
	t_rgb		rgb;
	t_sphere	*sph;

	sph = sphere();
	t = hit_sphere(ray, cam);
	if (t <= 0.0)
	{
		t = 0.5 * (ray.y + 1);
		rgb.r = (unsigned char)((1.0 - t) * 255 + t * 127);
		rgb.g = (unsigned char)((1.0 - t) * 255 + t * 178);
		rgb.b = 255;
	}
	else
	{
		rgb = color_sphere(sph, ray, t, cam);
	}
	return (rgb);
}

int	ray_color(t_rgb rgb)
{
	int	color;

	color = get_rgba(rgb.r, rgb.g, rgb.b, 225);
	return (color);
}