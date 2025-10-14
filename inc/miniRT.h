/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyvan-de <lyvan-de@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 13:31:26 by lyvan-de          #+#    #+#             */
/*   Updated: 2025/10/14 16:29:34 by lyvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdint.h>
# include <stdlib.h>
# include <stdio.h>
# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include "objects.h"
# include "vector.h"
# include "graphics.h"

# define WIDTH 800
# define HEIGHT 400
# define PI 3.14159265358979323846

typedef struct s_context
{
	mlx_t			*mlx;
	mlx_image_t		*image;
	t_viewport		*view;
	t_camera		*cam;
}	t_context;

//ray functions
int		ray_color(t_rgb rgb);
t_vec3	ray_dir(t_viewport *view, t_camera *cam, int x, int y);
t_rgb	ray_rgb(t_vec3 ray, t_camera *cam);

#endif
