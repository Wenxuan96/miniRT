/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tuple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a12708 <a12708@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:23:13 by lyvan-de          #+#    #+#             */
/*   Updated: 2026/01/11 21:01:16 by a12708           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parsing.h"

int	parse_tuple(char *str, t_tuple	*tuple, double w)
{
	char	**split;
	int		i;

	split = ft_split(str, ',');
	if (!split)
		return (printf("Error\nMalloc Error\n"), 0);
	i = 0;
	while (i < 3)
	{
		if (!check_double(split[i]))
		{
			free_array(split);
			return (printf("Error\nWrong double value\n"), 0);
		}
		i ++;
	}
	if (split[i] != NULL)
	{
		free_array(split);
		return (printf("Error\nToo many vector arguments\n"), 0);
	}
	*tuple = new_tuple(str_to_double(split[0]), str_to_double(split[1]),
			str_to_double(split[2]), w);
	free_array(split);
	return (1);
}

int	parse_norm_tuple(char	*str, t_tuple	*tuple)
{
	if (!parse_tuple(str, tuple, 0.0))
		return (0);
	if (tuple->x < -1.0 || tuple->x > 1.0)
		return (printf("Error\nExpected normalized vector\n"), 0);
	if (tuple->y < -1.0 || tuple->y > 1.0)
		return (printf("Error\nExpected normalized vector\n"), 0);
	if (tuple->z < -1.0 || tuple->z > 1.0)
		return (printf("Error\nExpected normalized vector\n"), 0);
	if (tuple->w != 0)
		return (printf("Error\nExpected a vector tuple, not a point. (w is not 0)\n"), 0);
	return (1);
}
