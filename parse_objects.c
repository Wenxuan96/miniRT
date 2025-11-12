/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyvan-de <lyvan-de@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:32:18 by lyvan-de          #+#    #+#             */
/*   Updated: 2025/11/12 19:24:46 by lyvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/parsing.h"

int	parse_ambient(char **tokens, t_scene *scene)
{
	int i;

	if (scene->ambient)
	{
		printf("Error\nDuplicate ambient input\n");
		return (0);
	}
	scene->ambient = ft_calloc(1, sizeof(t_ambient));
	if (!scene->ambient)
	{
		printf("Error\nMalloc Error\n");
		return (0);
	}
	i = 1;
	scene->ambient->ratio = str_to_double(tokens[i]);
	while (tokens[i] != NULL)
	{
		printf("token %d: %s\n", i, tokens[i]);
		i ++;
	}
	return (1);
}

int	parse_camera(char **tokens, t_scene *scene)
{
	int i;

	i = 0;
	scene = (void *)scene;
	printf("camera\n");
	while (tokens[i] != NULL)
	{
		printf("token %d: %s\n", i, tokens[i]);
		i ++;
	}
	return (1);
}

int	parse_light(char **tokens, t_scene *scene)
{
	int i;

	scene = (void *)scene;
	i = 0;
	printf("light\n");
	while (tokens[i] != NULL)
	{
		printf("token %d: %s\n", i, tokens[i]);
		i ++;
	}
	return (1);
}

int	parse_sphere(char **tokens, t_scene *scene)
{
	int i;

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
	int i;

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
	int i;

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
