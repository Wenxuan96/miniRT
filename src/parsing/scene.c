/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxi <wxi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 17:52:22 by lyvan-de          #+#    #+#             */
/*   Updated: 2026/01/09 12:18:04 by wxi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/miniRT.h"

static void	del_node(void *content)
{
	free(content);
}

void	free_scene(t_world *scene)
{
	ft_lstclear(&scene->objects, del_node);
	free(scene);
}

int	check_scene(t_world *scene)
{
	if (!scene->has_ambient && !scene->has_camera
		&& !scene->has_ambient && ft_lstsize(scene->objects) == 0)
		return (printf("Error\nNo file contents\n"), 0);
	if (!scene->has_ambient)
		return (printf("Error\nNo ambient input\n"), 0);
	if (!scene->has_camera)
		return (printf("Error\nNo ambient input\n"), 0);
	if (!scene->has_light)
		return (printf("Error\nNo ambient input\n"), 0);
	return (1);
}

void	init_world(t_world *scene)
{
	scene->ambient = (t_ambient){0};
	scene->camera = (t_camera){0};
	scene->light = (t_light){0};
	scene->has_ambient = false;
	scene->has_camera = false;
	scene->has_light = false;
	scene->objects = NULL;
}
