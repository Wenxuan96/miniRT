/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxi <wxi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:32:18 by lyvan-de          #+#    #+#             */
/*   Updated: 2026/01/09 12:18:04 by wxi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parsing.h"

int	add_node(int type, void *content, t_world *scene)
{
	t_list	*node;

	node = ft_lstnew(content);
	if (!node)
		return (printf("Error\nMalloc error\n"), 0);
	node->type = type;
	ft_lstadd_front(&scene->objects, node);
	return (1);
}

int	check_tokens(char **tokens, int expected)
{
	int	i;

	i = 0;
	while (tokens[i])
		i++;
	if (i != expected)
		return (printf("Error\nWrong amount of tokens\n"), 0);
	return (1);
}

int	parse_sphere(char **tokens, t_world *scene)
{
	t_sphere	*sphere;

	if (!check_tokens(tokens, 4))
		return (0);
	sphere = ft_calloc(1, sizeof(*sphere));
	if (!sphere)
		return (printf("Error\nMalloc error\n"), 0);
	if (!parse_tuple(tokens[1], &sphere->position, 1.0))
		return (0);
	if (!check_double(tokens[2]))
		return (printf("Error\nWrong double value sphere diameter\n"), 0);
	sphere->diameter = str_to_double(tokens[2]);
	if (!str_to_rgb(tokens[3], &sphere->color))
		return (printf("Error\nWrong rgb value sphere\n"), 0);
	if (!add_node(SPHERE, sphere, scene))
		return (0);
	return (1);
}

int	parse_plane(char **tokens, t_world *scene)
{
	t_plane	*plane;

	if (!check_tokens(tokens, 4))
		return (0);
	plane = ft_calloc(1, sizeof(*plane));
	if (!plane)
		return (printf("Error\nMalloc error\n"), 0);
	if (!parse_tuple(tokens[1], &plane->point, 1.0))
		return (0);
	if (!parse_norm_tuple(tokens[2], &plane->normal))
		return (0);
	if (!str_to_rgb(tokens[3], &plane->color))
		return (printf("Error\nWrong rgb value plane\n"), 0);
	if (!add_node(PLANE, plane, scene))
		return (0);
	return (1);
}

int	parse_cylinder(char **tokens, t_world *scene)
{
	t_cylinder	*cylinder;

	if (!check_tokens(tokens, 6))
		return (0);
	cylinder = ft_calloc(1, sizeof(*cylinder));
	if (!cylinder)
		return (printf("Error\nMalloc error\n"), 0);
	if (!parse_tuple(tokens[1], &cylinder->center, 1.0))
		return (0);
	if (!parse_norm_tuple(tokens[2], &cylinder->axis))
		return (0);
	if (!check_double(tokens[3]))
		return (printf("Error\nWrong double value cylinder diameter\n"), 0);
	cylinder->diameter = str_to_double(tokens[3]);
	if (!check_double(tokens[4]))
		return (printf("Error\nWrong double value cylinder heigth\n"), 0);
	cylinder->heigth = str_to_double(tokens[4]);
	if (!str_to_rgb(tokens[5], &cylinder->color))
		return (printf("Error\nWrong rgb value cylinder\n"), 0);
	if (!add_node(CYLINDER, cylinder, scene))
		return (0);
	return (1);
}
