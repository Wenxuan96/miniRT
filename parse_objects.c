/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyvan-de <lyvan-de@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:32:18 by lyvan-de          #+#    #+#             */
/*   Updated: 2025/11/06 17:37:02 by lyvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/parsing.h"

int	parse_ambient(char **tokens)
{
	int i;

	i = 0;
	while (tokens[i] != NULL)
	{
		printf("token %d: %s\n", i, tokens[i]);
		i ++;
	}
	return (1);
}

int	parse_camera(char **tokens)
{
	int i;

	i = 0;
	while (tokens[i] != NULL)
	{
		printf("token %d: %s\n", i, tokens[i]);
		i ++;
	}
	return (1);
}

int	parse_light(char **tokens)
{
	int i;

	i = 0;
	while (tokens[i] != NULL)
	{
		printf("token %d: %s\n", i, tokens[i]);
		i ++;
	}
	return (1);
}

int	parse_sphere(char **tokens)
{
	int i;

	i = 0;
	while (tokens[i] != NULL)
	{
		printf("token %d: %s\n", i, tokens[i]);
		i ++;
	}
	return (1);
}

int	parse_plane(char **tokens)
{
	int i;

	i = 0;
	while (tokens[i] != NULL)
	{
		printf("token %d: %s\n", i, tokens[i]);
		i ++;
	}
	return (1);
}

int	parse_cylinder(char **tokens)
{
	int i;

	i = 0;
	while (tokens[i] != NULL)
	{
		printf("token %d: %s\n", i, tokens[i]);
		i ++;
	}
	return (1);
}
