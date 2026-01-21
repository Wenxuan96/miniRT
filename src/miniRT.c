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

#include "inc/miniRT.h"
#include "inc/graphics.h"
#include <stdio.h>

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_context *context = (t_context *)param;

	if (keydata.key == MLX_KEY_ESCAPE &&
        keydata.action == MLX_PRESS)
	{
		mlx_terminate(context->mlx);
		free(context);
		exit (EXIT_SUCCESS);
	}
}

int	get_rgba(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	put_image(void *param)
{
	t_context	*context;
	int			color;
	int			x;
	int			y;

	context = param;
	x = 0;
	y = 0;
	while (x < WIDTH)
	{
		while (y < HEIGHT)
		{
			color = ray_color(context, x, y);
			mlx_put_pixel(context->image, x, y, color);
			y++;
		}
		y = 0;
		x++;
	}
	mlx_image_to_window(context->mlx, context->image, 0, 0);
}

t_world	*parse(int argc, char *argv[])
{
	t_world	*world;

	if (argc != 2)
	{
		printf("Error\nPlease input .rt file\n");
		return (NULL);
	}
	if (!check_file_extension(argv[1]))
		return (NULL);
	world = ft_calloc(1, sizeof(*world));
	if (!world)
		return (printf("Error\nMalloc error\n"), NULL);
	init_world(world);
	if (!read_file(argv, world))
		return (free_scene(world), NULL);
	if (!check_scene(world))
		return (free_scene(world), NULL);
	return (world);
}

int	main(int argc, char *argv[])
{
	t_world		*world;
	t_context	*context;

	if (!(world = parse(argc, argv)))
		return (1);
	context = ft_calloc(1, sizeof(t_context));
	if (!context)
		return (1);
	if (!(context->mlx = mlx_init(WIDTH, HEIGHT, "miniRT", true)))
		printf("no window\n");
	context->world = world;
	set_viewport(&context->world->view, context->world->camera);
	context->image = mlx_new_image(context->mlx, WIDTH, HEIGHT);
	// setup_default();
	put_image(context);
	mlx_key_hook(context->mlx, my_keyhook, context);
	mlx_loop(context->mlx);
	return (0);
}
