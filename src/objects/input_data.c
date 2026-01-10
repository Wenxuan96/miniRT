// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   input_data.c                                       :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: wxi <wxi@student.42.fr>                    +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/10/10 13:37:41 by lyvan-de          #+#    #+#             */
// /*   Updated: 2025/12/31 14:11:04 by wxi              ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../inc/objects.h"
// #include <stdio.h>

// t_tuple	map(t_tuple *obj_input)
// {
//     obj_input->x = (obj_input->x < 0) ? 0 : (obj_input->x > 255) ? 1 : obj_input->x / 255;
//     obj_input->y = (obj_input->y < 0) ? 0 : (obj_input->y > 255) ? 1 : obj_input->y / 255;
//     obj_input->z = (obj_input->z < 0) ? 0 : (obj_input->z > 255) ? 1 : obj_input->z / 255;
// 	obj_input->w = (obj_input->z < 0) ? 0 : (obj_input->w > 255) ? 1 : obj_input->w / 255;
//     return (*obj_input);
// }

// t_camera	*camera(void)
// {
// 	static t_camera	cam = {
// 		.position = {-50.0, 0, 20, 0},
// 		.orientation = {0, 0, 1, 0},
// 		.fov = 70,
// 		.world_up = {0, 1, 0, 0},
// 	};
// 	return ((t_camera *)&cam);
// }

// t_sphere	*sphere(void)
// {
// 	static int i;
	
// 	static t_sphere	sphere = {
// 		.position = {-50.0, 0.0, 40.0, 0},
// 		.diameter = 12.4,
// 		.color = {255, 0, 0, 0},
// 	};
// 	if (i == 0)
// 	{
// 		sphere.color = map(&sphere.color);
// 		i = 1;
// 	}
// 	// for (int i = 0; i < 2; i++)
// 	// 	printf("%f, %f, %f\n", sphere.color.x, sphere.color.y, sphere.color.z);
// 	return ((t_sphere *)&sphere);
// }

// t_ambient	*ambient(void)
// {
// 	static t_ambient	ambient = {
// 		.ratio = 0.60,
// 		.color = {255, 255, 255, 0},
// 	};
// 	map(&ambient.color);
// 	return ((t_ambient *)&ambient);
// }

// t_light	*light(void)
// {
// 	static t_light	light = {
// 		.ratio = 0.9,
// 		.origin = {70.0, 50.0, 0.0, 0},
// 	};
// 	return ((t_light *) & light);
// }
