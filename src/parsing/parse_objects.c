/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxi <wxi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:32:18 by lyvan-de          #+#    #+#             */
/*   Updated: 2026/01/27 16:26:57 by wxi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parsing.h"

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
	if (!str_to_rgb(tokens[3], &sphere->base.color))
		return (printf("Error\nWrong rgb value sphere\n"), 0);
	if (!init_base(&sphere->base, SPHERE, sphere->base.color))
		return (printf("Error\nInit base sphere failed\n"));
	init_sphere_transform(sphere);
	if (!add_node(sphere, scene))
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
	if (!str_to_rgb(tokens[3], &plane->base.color))
		return (printf("Error\nWrong rgb value plane\n"), 0);
	if (!add_node(plane, scene))
		return (0);
	init_base(&plane->base, PLANE, plane->base.color);
	init_plane_transform(plane);
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
	cylinder->height = str_to_double(tokens[4]);
	cylinder->hit_location = CYLINDER;
	if (!str_to_rgb(tokens[5], &cylinder->base.color))
		return (printf("Error\nWrong rgb value cylinder\n"), 0);
	init_base(&cylinder->base, CYLINDER, cylinder->base.color);
	init_cylinder_transform(cylinder);
	if (!add_node(cylinder, scene))
		return (0);
	return (1);
}
