/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyvan-de <lyvan-de@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:32:18 by lyvan-de          #+#    #+#             */
/*   Updated: 2025/11/20 18:15:04 by lyvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/parsing.h"

int	parse_ambient(char **tokens, t_scene *scene)
{
	int	i;

	i = 0;
	while (tokens[i])
		i++;
	if (i != 3)
		return (printf("Error\nWrong amount of ambient tokens\n"), 0);
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

int	parse_camera(char **tokens, t_scene *scene)
{
	int	i;

	i = 0;
	while (tokens[i])
		i++;
	if (i != 4)
		return (printf("Error\nWrong amount of camera tokens\n"), 0);
	if (scene->has_camera)
		return (printf("Error\nDuplicate camera input\n"), 0);
	if (!parse_vector(tokens[1], &scene->camera.position))
		return (0);
	if (!parse_norm_vector(tokens[2], &scene->camera.orientation))
		return (0);
	scene->camera.fov = ft_atoi(tokens[3]);
	if (scene->camera.fov < 0 || scene->camera.fov > 180)
		return (printf("Error\nFOV should be between 0 and 180"), 0);
	scene->camera.world_up = vec3(0, 1, 0);
	scene->has_camera = true;
	return (1);
}

int	parse_light(char **tokens, t_scene *scene)
{
	int	i;

	i = 0;
	while (tokens[i])
		i++;
	if (i != 3)
		return (printf("Error\nWrong amount of light tokens\n"), 0);
	if (scene->has_light)
		return (printf("Error\nDuplicate light input\n"), 0);
	if (!parse_vector(tokens[1], & scene->light.origin))
		return (0);
	if (!check_double(tokens[2]))
		return (printf("Error\nWrong double value light ratio\n"), 0);
	scene->light.ratio = str_to_double(tokens[2]);
	if (scene->light.ratio < 0.0 || scene->light.ratio > 1.0)
		return (printf("Error\nLight ratio not in range\n"), 0);
	scene->has_light = true;
	return (1);
}

int	parse_sphere(char **tokens, t_scene *scene)
{
	int			i;
	t_sphere	*sphere;
	t_list		*node;

	i = 0;
	while (tokens[i])
		i++;
	if (i != 4)
		return (printf("Error\nWrong amount of sphere tokens\n"), 0);
	sphere = ft_calloc(1, sizeof(*sphere));
	if (!sphere)
		return (printf("Error\nMalloc error\n"), 0);
	if (!parse_vector(tokens[1], &sphere->position))
		return (0);
	if (!check_double(tokens[2]))
		return (printf("Error\nWrong double value sphere diameter\n"), 0);
	sphere->diameter = str_to_double(tokens[2]);
	if (!str_to_rgb(tokens[3], &sphere->color))
		return (printf("Error\nWrong rgb value sphere\n"), 0);
	node = ft_lstnew(sphere);
	if (!node)
		return (printf("Error\nMalloc error\n"), 0);
	node->type = SPHERE;
	ft_lstadd_front(&scene->objects, node);
	return (1);
}

int	parse_plane(char **tokens, t_scene *scene)
{
	int		i;
	t_plane	*plane;
	t_list	*node;

	i = 0;
	while (tokens[i])
		i++;
	if (i != 4)
		return (printf("Error\nWrong amount of plane tokens\n"), 0);
	plane = ft_calloc(1, sizeof(*plane));
	if (!plane)
		return (printf("Error\nMalloc error\n"), 0);
	if (!parse_vector(tokens[1], &plane->point))
		return (0);
	if (!parse_norm_vector(tokens[2], &plane->point))
		return (0);
	if (!str_to_rgb(tokens[3], &plane->color))
		return (printf("Error\nWrong rgb value plane\n"), 0);
	node = ft_lstnew(plane);
	if (!node)
		return (printf("Error\nMalloc error\n"), 0);
	node->type = PLANE;
	ft_lstadd_front(&scene->objects, node);
	return (1);
}

int	parse_cylinder(char **tokens, t_scene *scene)
{
	int			i;
	t_cylinder	*cylinder;
	t_list		*node;

	i = 0;
	while (tokens[i])
		i++;
	if (i != 6)
		return (printf("Error\nWrong amount of cylinder tokens\n"), 0);
	cylinder = ft_calloc(1, sizeof(*cylinder));
	if (!cylinder)
		return (printf("Error\nMalloc error\n"), 0);
	if (!parse_vector(tokens[1], &cylinder->center))
		return (0);
	if (!parse_norm_vector(tokens[2], &cylinder->axis))
		return (0);
	if (!check_double(tokens[3]))
		return (printf("Error\nWrong double value cylinder diameter\n"), 0);
	cylinder->diameter = str_to_double(tokens[3]);
	if (!check_double(tokens[4]))
		return (printf("Error\nWrong double value cylinder heigth\n"), 0);
	cylinder->heigth = str_to_double(tokens[4]);
	if (!str_to_rgb(tokens[5], &cylinder->color))
		return (printf("Error\nWrong rgb value cylinder\n"), 0);
	node = ft_lstnew(cylinder);
	if (!node)
		return (printf("Error\nMalloc error\n"), 0);
	node->type = CYLINDER;
	ft_lstadd_front(&scene->objects, node);
	return (1);
}
