/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene_setup.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxi <wxi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 18:23:45 by lyvan-de          #+#    #+#             */
/*   Updated: 2026/01/09 12:18:04 by wxi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parsing.h"

int	parse_ambient(char **tokens, t_world *scene)
{
	if (!check_tokens(tokens, 3))
		return (0);
	if (scene->has_ambient)
		return (printf("Error\nDuplicate ambient input\n"), 0);
	if (!check_double(tokens[1]))
		return (printf("Error\nWrong double value ambient ratio\n"), 0);
	scene->ambient.ratio = str_to_double(tokens[1]);
	if (scene->ambient.ratio < 0.0 || scene->ambient.ratio > 1.0)
		return (printf("Error\nAmbient ratio not in range\n"), 0);
	if (!check_rgb(tokens[2]))
		return (printf("Error\nWrong rgb value ambient\n"), 0);
	if (!str_to_rgb(tokens[2], &scene->ambient.color))
		return (0);
	scene->has_ambient = true;
	return (1);
}

int	parse_camera(char **tokens, t_world *scene)
{
	if (!check_tokens(tokens, 4))
		return (0);
	if (scene->has_camera)
		return (printf("Error\nDuplicate camera input\n"), 0);
	if (!parse_tuple(tokens[1], &scene->camera.position, 1.0))
		return (0);
	if (!parse_norm_tuple(tokens[2], &scene->camera.orientation))
		return (0);
	scene->camera.fov = ft_atoi(tokens[3]);
	if (scene->camera.fov < 0 || scene->camera.fov > 180)
		return (printf("Error\nFOV should be between 0 and 180"), 0);
	scene->camera.world_up = new_tuple(0, 1, 0, 0);
	scene->has_camera = true;
	return (1);
}

int	parse_light(char **tokens, t_world *scene)
{
	if (!check_tokens(tokens, 3))
		return (0);
	if (scene->has_light)
		return (printf("Error\nDuplicate light input\n"), 0);
	if (!parse_tuple(tokens[1], & scene->light.origin, 1.0))
		return (0);
	if (!check_double(tokens[2]))
		return (printf("Error\nWrong double value light ratio\n"), 0);
	scene->light.ratio = str_to_double(tokens[2]);
	if (scene->light.ratio < 0.0 || scene->light.ratio > 1.0)
		return (printf("Error\nLight ratio not in range\n"), 0);
	scene->has_light = true;
	return (1);
}
