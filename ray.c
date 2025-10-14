/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyvan-de <lyvan-de@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:38:19 by lyvan-de          #+#    #+#             */
/*   Updated: 2025/10/14 15:38:49 by lyvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/miniRT.h"

t_rgb	ray_rgb(t_vec3 ray)
{
	double	t;
	t_rgb	rgb;

	t = 0.5 * (ray.y + 1);
	rgb.r = (int)((1.0 - t) * 255 + t * 127);
	rgb.g = (int)((1.0 - t) * 255 + t * 178);
	rgb.b = 255;
	return (rgb);
}

int	ray_color(t_rgb rgb)
{
	int	color;

	color = get_rgba(rgb.r, rgb.g, rgb.b, 225);
	return (color);
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
