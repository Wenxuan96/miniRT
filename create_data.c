/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyvan-de <lyvan-de@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 13:37:41 by lyvan-de          #+#    #+#             */
/*   Updated: 2025/10/15 11:35:45 by lyvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/objects.h"

t_camera	*camera(void)
{
	static const t_camera	cam = {
		.position = {-50.0, 0, 20},
		.orientation = {0, 0, 1},
		.fov = 90,
	};

	return ((t_camera *)&cam);
}

t_sphere	*sphere(void)
{
	static const t_sphere	sphere = {
		.position = {-50.0, 0.0, 50.0},
		.diameter = 12.4,
		.color = {10, 0, 255},
	};

	return ((t_sphere *)&sphere);
}

t_ambient	*ambient(void)
{
	static const t_ambient	ambient = {
		.ratio = 0.2,
		.color = {255, 255, 255},
	};

	return ((t_ambient *)&ambient);
}
