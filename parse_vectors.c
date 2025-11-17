/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_vectors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyvan-de <lyvan-de@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:23:13 by lyvan-de          #+#    #+#             */
/*   Updated: 2025/11/17 17:11:04 by lyvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/parsing.h"

int	parse_vector(char *str, t_vec3	*vec)
{
	char	**split;
	int		i;
	
	split = ft_split(str, ',');
	if (!split)
		return(printf("Error\nMalloc Error\n"), 0);
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
		return(printf("Error\nToo many vector arguments\n"), 0);
	}
	*vec = vec3(str_to_double(split[0]), str_to_double(split[1]), str_to_double(split[2]));
	free_array(split);
	return (1);
}

int	parse_norm_vector(char*str, t_vec3	*vec)
{
	if (!parse_vector(str, vec))
		return(0);
	if (vec->x < -1.0 || vec->x > 1.0)
		return(printf("Error\nExpected normalized vector\n"), 0);
	if (vec->y < -1.0 || vec->y > 1.0)
		return(printf("Error\nExpected normalized vector\n"), 0);
	if (vec->z < -1.0 || vec->z > 1.0)
		return(printf("Error\nExpected normalized vector\n"), 0);
	return(1);
}
