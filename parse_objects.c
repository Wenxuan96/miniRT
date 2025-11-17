/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyvan-de <lyvan-de@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:32:18 by lyvan-de          #+#    #+#             */
/*   Updated: 2025/11/17 17:31:59 by lyvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/parsing.h"

int	parse_ambient(char **tokens, t_scene *scene)
{
	int	i;

	i = 0;
	while(tokens[i])
		i++;
	if (i > 3)
		return (printf("Error\nToo many ambient tokens\n"), 0);
	if (scene->ambient)
		return (printf("Error\nDuplicate ambient input\n"), 0);
	scene->ambient = ft_calloc(1, sizeof(t_ambient));
	if (!scene->ambient)
		return (printf("Error\nMalloc Error\n"), 0);
	if (!check_double(tokens[1]))
		return (printf("Error\nWrong double value ambient ratio\n"), 0);
	scene->ambient->ratio = str_to_double(tokens[1]);
	if (scene->ambient->ratio < 0.0 || scene->ambient->ratio > 1.0)
		return (printf("Error\nAmbient ratio not in range\n"), 0);
	if (!check_rgb(tokens[2]))
		return (printf("Error\nWrong rgb value\n"), 0);
	if (!str_to_rgb(tokens[2], &scene->ambient->color))
		return (0);
	return (1);
}

int	parse_camera(char **tokens, t_scene *scene)
{
	int	i;

	i = 0;
	while(tokens[i])
		i++;
	if (i > 4)
		return (printf("Error\nToo many camera tokens\n"), 0);
	if (scene->camera)
		return (printf("Error\nDuplicate camera input\n"), 0);
	scene->camera = ft_calloc(1, sizeof(t_camera));
	if (!scene->camera)
		return (printf("Error\nMalloc Error\n"), 0);
	if (!parse_vector(tokens[1], &scene->camera->position))
		return (0);
	if (!parse_norm_vector(tokens[2], &scene->camera->orientation))
		return (0);
	scene->camera->fov = ft_atoi(tokens[3]);
	if (scene->camera->fov < 0 || scene->camera->fov > 180)
		return(printf("Error\nFOV should be between 0 and 180"), 0);
	scene->camera->world_up = vec3(0, 1, 0);
	return (1);
}

int	parse_light(char **tokens, t_scene *scene)
{
	int	i;

	i = 0;
	while(tokens[i])
		i++;
	if (i > 3)
		return (printf("Error\nToo many light tokens\n"), 0);	
	if (scene->light)
		return (printf("Error\nDuplicate light input\n"), 0);
	scene->light = ft_calloc(1, sizeof(t_light));
	if (!scene->light)
		return (printf("Error\nMalloc Error\n"), 0);
	if (!parse_vector(tokens[1], & scene->light->origin))
		return (0);
	if (!check_double(tokens[2]))
		return (printf("Error\nWrong double value light ratio\n"), 0);
	scene->light->ratio = str_to_double(tokens[2]);
	if (scene->light->ratio < 0.0 || scene->light->ratio > 1.0)
		return (printf("Error\nLight ratio not in range\n"), 0);
	return (1);
}

int	parse_sphere(char **tokens, t_scene *scene)
{
	int	i;

	scene = (void *)scene;
	i = 0;
	printf("sphere\n");
	while (tokens[i] != NULL)
	{
		printf("token %d: %s\n", i, tokens[i]);
		i ++;
	}
	return (1);
}

int	parse_plane(char **tokens, t_scene *scene)
{
	int	i;

	scene = (void *)scene;
	i = 0;
	printf("plane\n");
	while (tokens[i] != NULL)
	{
		printf("token %d: %s\n", i, tokens[i]);
		i ++;
	}
	return (1);
}

int	parse_cylinder(char **tokens, t_scene *scene)
{
	int	i;

	scene = (void *)scene;
	i = 0;
	printf("cylinder\n");
	while (tokens[i] != NULL)
	{
		printf("token %d: %s\n", i, tokens[i]);
		i ++;
	}
	return (1);
}
