/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyvan-de <lyvan-de@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:38:19 by lyvan-de          #+#    #+#             */
/*   Updated: 2026/01/24 15:20:16 by lyvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/miniRT.h"

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
