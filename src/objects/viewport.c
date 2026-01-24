/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyvan-de <lyvan-de@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 14:42:08 by lyvan-de          #+#    #+#             */
/*   Updated: 2026/01/21 16:55:43 by lyvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/miniRT.h"
#include "../inc/objects.h"

double	deg_to_rad(double degrees)
{
	return (degrees * PI / 180);
}

t_tuple	upper_left(t_viewport *viewport, t_camera cam)
{
	t_tuple	upper_left;

	upper_left = tuple_add(cam.position, cam.orientation);
	upper_left = tuple_sub(upper_left, tuple_div(viewport->viewport_u, 2.0));
	upper_left = tuple_sub(upper_left, tuple_div(viewport->viewport_v, 2.0));
	return (upper_left);
}

void compute_viewport_axis(t_viewport *view, t_camera cam)
{
	t_tuple	right;
	t_tuple	up;

	if (fabs(tuple_dot(cam.orientation, cam.world_up)) > 0.999)
        cam.world_up = new_tuple(1, 0, 0, 0);
	right = tuple_norm(tuple_cross(cam.world_up, cam.orientation));
	up = tuple_cross(right, cam.orientation);
    view->viewport_u = tuple_mult(right, view->plane_width);
    view->viewport_v = tuple_mult(up, view->plane_height);
}

void set_viewport(t_viewport *viewport, t_camera camera)
{
	double d;
	double fov_rad;
	double aspect_ratio;

	d = 1.0;
	fov_rad = deg_to_rad(camera.fov);

	viewport->plane_height = 2.0 * d * tan(fov_rad / 2.0);
	aspect_ratio = (double)WIDTH / (double)HEIGHT;
	viewport->plane_width = viewport->plane_height * aspect_ratio;
	compute_viewport_axis(viewport, camera);
	viewport->pixel_delta_u = tuple_div(viewport->viewport_u, WIDTH);
	viewport->pixel_delta_v = tuple_div(viewport->viewport_v, HEIGHT);
	viewport->upper_left = upper_left(viewport, camera);
}
