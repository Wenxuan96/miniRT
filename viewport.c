/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyvan-de <lyvan-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 14:42:08 by lyvan-de          #+#    #+#             */
/*   Updated: 2025/10/10 15:24:01 by lyvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/miniRT.h"
#include "inc/objects.h"

double  deg_to_rad(double degrees)
{
    return(degrees * PI / 180);
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

    return (&viewport);
}

