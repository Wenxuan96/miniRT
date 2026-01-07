// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   viewport.c                                         :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: lyvan-de <lyvan-de@student.codam.nl>       +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/10/10 14:42:08 by lyvan-de          #+#    #+#             */
// /*   Updated: 2025/10/15 14:17:10 by lyvan-de         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "inc/miniRT.h"
// #include "inc/objects.h"

// double	deg_to_rad(double tuplerees)
// {
// 	return (degrees * PI / 180);
// }

// t_vec3	upper_left(t_viewport *viewport, t_camera *cam)
// {
// 	t_vec3	upper_left;

// 	upper_left = vec3_add(cam->position, cam->orientation);
// 	upper_left = vec3_sub(upper_left, vec3_div(viewport->viewport_u, 2.0));
// 	upper_left = vec3_sub(upper_left, vec3_div(viewport->viewport_v, 2.0));
// 	return (upper_left);
// }

// void compute_viewport_axis(t_viewport *view, t_camera *cam)
// {
// 	t_vec3	right;
// 	t_vec3	up;

// 	if (fabs(vec3_dot(cam->orientation, cam->world_up)) > 0.999)
//         cam->world_up = vec3(1, 0, 0);
// 	right = vec3_norm(vec3_cross(cam->orientation, cam->world_up));
// 	up = vec3_cross(right, cam->orientation);
//     view->viewport_u = vec3_mult(right, view->plane_width);
//     view->viewport_v = vec3_mult(up, view->plane_height);
// }

// //not sure if this should be part of the camera struct or not
// t_viewport	*set_viewport(t_camera *camera)
// {
// 	static t_viewport	viewport;
// 	double				d;
// 	double				fov_rad;
// 	double				aspect_ratio;

// 	d = 1.0;
// 	fov_rad = deg_to_rad(camera->fov);
// 	viewport.plane_width = 2 * d * tan(fov_rad / 2);
// 	aspect_ratio = (double)HEIGHT / (double)WIDTH;
// 	viewport.plane_height = viewport.plane_width * aspect_ratio;
// 	compute_viewport_axis(&viewport, camera);
// 	viewport.pixel_delta_u = vec3_div(viewport.viewport_u, WIDTH);
// 	viewport.pixel_delta_v = vec3_div(viewport.viewport_v, HEIGHT);
// 	viewport.upper_left = upper_left(&viewport, camera);
// 	return (&viewport);
// }
