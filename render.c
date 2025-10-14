/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyvan-de <lyvan-de@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:40:15 by lyvan-de          #+#    #+#             */
/*   Updated: 2025/10/14 15:40:29 by lyvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/miniRT.h"

void	put_image(void *param)
{
	t_context	*context;
	t_camera	*cam;
	t_viewport	*view;
	int			x;
	int			y;

	context = param;
	cam = context->cam;
	view = context->view;
	x = 0;
	y = 0;
	while (x < WIDTH)
	{
		while (y < HEIGHT)
		{
			mlx_put_pixel(context->image, x, y,
				ray_color(ray_rgb(ray_dir(view, cam, x, y))));
			y ++;
		}
		y = 0;
		x ++;
	}
	mlx_image_to_window(context->mlx, context->image, 0, 0);
}
