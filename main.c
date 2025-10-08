/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyvan-de <lyvan-de@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:44:46 by lyvan-de          #+#    #+#             */
/*   Updated: 2025/10/08 15:52:02 by lyvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/miniRT.h"
#include <stdio.h>
#define WIDTH 256
#define HEIGHT 256

int32_t	main(void)
{
	mlx_t	*mlx;

	mlx = mlx_init(WIDTH, HEIGHT, "miniRT", true);
	if (!mlx)
		printf("no window\n");
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}
