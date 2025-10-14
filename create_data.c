/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyvan-de <lyvan-de@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 13:37:41 by lyvan-de          #+#    #+#             */
/*   Updated: 2025/10/14 10:56:55 by lyvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/objects.h"

t_camera	*camera(void)
{
	static const t_camera	cam = {
		.position = {-50.0, 0, 20},
		.orientation = {0, 0, 1},
		.fov = 70,
	};

	return ((t_camera *)&cam);
}

t_sphere	*sphere(void)
{
	static const t_sphere	sphere = {
		.position = {0.0, 0.0, 20.6},
		.diameter = 12.4,
		.color = {10, 0, 255},
	};

	return ((t_sphere *)&sphere);
}
