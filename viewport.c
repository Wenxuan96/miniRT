/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxi <wxi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 14:42:08 by lyvan-de          #+#    #+#             */
/*   Updated: 2025/12/19 19:48:11 by wxi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/miniRT.h"
#include "inc/objects.h"

double	deg_to_rad(double degrees)
{
	return (degrees * PI / 180);
}

t_vec4	upper_left(t_viewport *viewport, t_camera *cam)
{
	t_vec4	upper_left;

	upper_left = vec4_add(cam->position, cam->orientation);
	upper_left = vec4_sub(upper_left, vec4_div(viewport->viewport_u, 2.0));
	upper_left = vec4_sub(upper_left, vec4_div(viewport->viewport_v, 2.0));
	return (upper_left);
}

void compute_viewport_axis(t_viewport *view, t_camera *cam)
{
	t_vec4	right;
	t_vec4	up;

	if (fabs(vec4_dot(cam->orientation, cam->world_up)) > 0.999)
        cam->world_up = vec4(1, 0, 0, 0);
	right = vec4_norm(vec4_cross(cam->orientation, cam->world_up));
	up = vec4_cross(right, cam->orientation);
    view->viewport_u = vec4_mult(right, view->plane_width);
    view->viewport_v = vec4_mult(up, view->plane_height);
}

//not sure if this should be part of the camera struct or not
t_viewport	*set_viewport(t_camera *camera)
{
	static t_viewport	viewport;
	double				d;
	double				fov_rad;
	double				aspect_ratio;

	d = 1.0;
	fov_rad = deg_to_rad(camera->fov);
	viewport.plane_width = 2 * d * tan(fov_rad / 2);
	aspect_ratio = (double)HEIGHT / (double)WIDTH;
	viewport.plane_height = viewport.plane_width * aspect_ratio;
	compute_viewport_axis(&viewport, camera);
	viewport.pixel_delta_u = vec4_div(viewport.viewport_u, WIDTH);
	viewport.pixel_delta_v = vec4_div(viewport.viewport_v, HEIGHT);
	viewport.upper_left = upper_left(&viewport, camera);
	return (&viewport);
}
