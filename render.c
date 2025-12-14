/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxi <wxi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:40:15 by lyvan-de          #+#    #+#             */
/*   Updated: 2025/12/10 14:47:54 by wxi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/miniRT.h"
#include "inc/graphics.h"

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
			// mlx_put_pixel(context->image, x, y,
			// 	ray_color(ray_rgb(ray_dir(view, cam, x, y),cam)));
			mlx_put_pixel(context->image, x, y, color);
			y++;
		}
		y = 0;
		x++;
	}
	mlx_image_to_window(context->mlx, context->image, 0, 0);
}
