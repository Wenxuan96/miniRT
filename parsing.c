/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyvan-de <lyvan-de@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:07:10 by lyvan-de          #+#    #+#             */
/*   Updated: 2025/11/20 18:17:40 by lyvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/parsing.h"

int	main(int argc, char *argv[])
{
	t_scene	*scene;

	if (argc != 2)
	{
		printf("Error\nPlease input .rt file\n");
		return (1);
	}
	if (!check_file_extension(argv[1]))
		return (1);
	scene = ft_calloc(1, sizeof(*scene));
	if (!scene)
		return (printf("Error\nMalloc error\n"), 1);
	init_scene(scene);
	if (!read_file(argv, scene))
		return (free_scene(scene), 1);
	if (!check_scene(scene))
		return (free_scene(scene), 1);
	free_scene(scene);
	return (0);
}
