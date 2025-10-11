/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyvan-de <lyvan-de@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 14:42:08 by lyvan-de          #+#    #+#             */
/*   Updated: 2025/10/11 18:40:18 by lyvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/miniRT.h"
#include "inc/objects.h"
#include "inc/math.h"

double  deg_to_rad(double degrees)
{
    return(degrees * PI / 180);
}

t_vec3	upper_left(t_viewport *viewport, t_camera *cam)
{
	t_vec3	length;
	t_vec3	upper_left;

	length = vec3(0, 0, 1);
	upper_left = vec3_sub(cam->position, length);
	upper_left = vec3_sub(upper_left, vec3_div(viewport->viewport_u, 2.0));
	upper_left = vec3_sub(upper_left, vec3_div(viewport->viewport_v, 2.0));
	return (upper_left);
}

t_viewport  *set_viewport(t_camera *camera)
{
    static t_viewport   viewport;
    double              d;
    double              fov_rad;
    double              aspect_ratio;

    d = 1.0;
    fov_rad = deg_to_rad(camera->fov);
    viewport.plane_width = 2 * d * tan(fov_rad/2);
    aspect_ratio = HEIGHT / WIDTH;
    viewport.plane_height = viewport.plane_width * aspect_ratio;
	viewport.viewport_u = vec3(viewport.plane_width, 0 ,0);
	viewport.viewport_v = vec3(0, -viewport.plane_height, 0);
	viewport.pixel_delta_u = vec3_div(viewport.viewport_u, WIDTH);
	viewport.pixel_delta_v = vec3_div(viewport.viewport_v, HEIGHT);
	viewport.upper_left = upper_left(&viewport, camera);
    return (&viewport);
}

