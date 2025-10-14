/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyvan-de <lyvan-de@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:44:46 by lyvan-de          #+#    #+#             */
/*   Updated: 2025/10/14 11:16:00 by lyvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/miniRT.h"
#include <stdio.h>

t_rgb	ray_rgb(t_vec3 ray)
{
	double	t;
	t_rgb	rgb;

	t = 0.5 * (ray.y + 1);
	rgb.r = (int)((1.0 - t) * 255 + t * 127);
	rgb.g = (int)((1.0 - t) * 255 + t * 178);
	rgb.b = 255;
	return (rgb);
}

int	ray_color(t_rgb rgb)
{
	int	color;

	color = get_rgba(rgb.r, rgb.g, rgb.b, 225);
	return (color);
}

t_vec3	ray_dir(t_viewport *view, t_camera *cam, int x, int y)
{
	t_vec3	center;
	t_vec3	u_offset;
	t_vec3	v_offset;
	t_vec3	temp;
	t_vec3	ray_dir;

	u_offset = vec3_mult(view->pixel_delta_u, (double)x + 0.5);
	v_offset = vec3_mult(view->pixel_delta_v, 0.5 + (double)y);
	temp = vec3_add(view->upper_left, u_offset);
	center = vec3_add(temp, v_offset);
	ray_dir = vec3_sub(center, cam->position);
	ray_dir = vec3_norm(ray_dir);
	return (ray_dir);
}

void	put_image(void *param)
{
	mlx_t		*mlx;
	t_context	*context;
	t_camera	*cam;
	t_viewport	*view;
	int			x;
	int			y;

	context = param;
	mlx = context->mlx;
	cam = context->cam;
	view = context->view;
	x = 0;
	y = 0;
	while (x < WIDTH)
	{
		while (y < HEIGHT)
		{
			mlx_put_pixel(context->image, x, y, ray_color(ray_rgb(ray_dir(view, cam, x, y))));
			y ++;
		}
		y = 0;
		x ++;
	}
	printf("image rendered\n");
}

int32_t	main(void)
{
	t_context	*context;

	context = ft_calloc(1, sizeof(t_context));
	if (!context)
		return (1);
	context->mlx = mlx_init(WIDTH, HEIGHT, "miniRT", true);
	if (!context->mlx)
		printf("no window\n");
	context->cam = camera();
	context->view = set_viewport(context->cam);
	context->image = mlx_new_image(context->mlx, WIDTH, HEIGHT);
	mlx_loop_hook(context->mlx, &put_image, context);
	mlx_loop(context->mlx);
	mlx_terminate(context->mlx);
	free(context);
	return (0);
}
