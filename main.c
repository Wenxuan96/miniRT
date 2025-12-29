// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   main.c                                             :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: lyvan-de <lyvan-de@student.codam.nl>       +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/10/01 16:44:46 by lyvan-de          #+#    #+#             */
// /*   Updated: 2025/12/17 14:18:59 by lyvan-de         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "inc/miniRT.h"
// #include <stdio.h>

// int32_t	main(void)
// {
// 	t_context	*context;

// 	context = ft_calloc(1, sizeof(t_context));
// 	if (!context)
// 		return (1);
// 	context->mlx = mlx_init(WIDTH, HEIGHT, "miniRT", true);
// 	if (!context->mlx)
// 		printf("no window\n");
// 	context->cam = camera();
// 	context->view = set_viewport(context->cam);
// 	context->image = mlx_new_image(context->mlx, WIDTH, HEIGHT);
// 	put_image(context);
// 	mlx_loop(context->mlx);
// 	mlx_terminate(context->mlx);
// 	free(context);
// 	return (0);
// }
