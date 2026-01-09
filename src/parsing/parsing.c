/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyvan-de <lyvan-de@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:07:10 by lyvan-de          #+#    #+#             */
/*   Updated: 2026/01/07 18:14:12 by lyvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parsing.h"

//t_scene	*parse(int argc, char *argv[])
//{
//	t_scene	*scene;

//	if (argc != 2)
//	{
//		printf("Error\nPlease input .rt file\n");
//		return (NULL);
//	}
//	if (!check_file_extension(argv[1]))
//		return (NULL);
//	scene = ft_calloc(1, sizeof(*scene));
//	if (!scene)
//		return (printf("Error\nMalloc error\n"), NULL);
//	init_scene(scene);
//	if (!read_file(argv, scene))
//		return (free_scene(scene), NULL);
//	if (!check_scene(scene))
//		return (free_scene(scene), NULL);
//	return (scene);
//}

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
	return (0);
}
