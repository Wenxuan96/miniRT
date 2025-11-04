/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a12708 <a12708@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 13:37:41 by lyvan-de          #+#    #+#             */
/*   Updated: 2025/11/04 12:42:49 by a12708           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/objects.h"

t_camera	*camera(void)
{
	static t_camera	cam = {
		.position = {-50.0, 0, 20},
		.orientation = {0, 0, 1},
		.fov = 70,
		.world_up = {0, 1, 0},
	};

	return ((t_camera *)&cam);
}

t_sphere	*sphere(void)
{
	static const t_sphere	sphere = {
		.position = {-50.0, 0.0, 40.0},
		.diameter = 12.4,
		.color = {255, 0, 0},
	};

	return ((t_sphere *)&sphere);
}

t_ambient	*ambient(void)
{
	static const t_ambient	ambient = {
		.ratio = 0.60,
		.color = {255, 255, 255},
	};

	return ((t_ambient *)&ambient);
}

t_light	*light(void)
{
	static const t_light	light = {
		.ratio = 0.9,
		.origin = {70.0, 50.0, 0.0},
	};
	return ((t_light *) & light);
}
