/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a12708 <a12708@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:07:10 by lyvan-de          #+#    #+#             */
/*   Updated: 2026/01/10 20:49:51 by a12708           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parsing.h"

//t_world	*parse(int argc, char *argv[])
//{
//	t_world	*scene;

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
//	init_world(scene);
//	if (!read_file(argv, scene))
//		return (free_scene(scene), NULL);
//	if (!check_scene(scene))
//		return (free_scene(scene), NULL);
//	return (scene);
//}

// int	main(int argc, char *argv[])
// {
// 	t_world	*scene;

// 	if (argc != 2)
// 	{
// 		printf("Error\nPlease input .rt file\n");
// 		return (1);
// 	}
// 	if (!check_file_extension(argv[1]))
// 		return (1);
// 	scene = ft_calloc(1, sizeof(*scene));
// 	if (!scene)
// 		return (printf("Error\nMalloc error\n"), 1);
// 	init_world(scene);
// 	if (!read_file(argv, scene))
// 		return (free_scene(scene), 1);
// 	if (!check_scene(scene))
// 		return (free_scene(scene), 1);
// 	return (0);
// }
