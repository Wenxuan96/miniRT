/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyvan-de <lyvan-de@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 13:31:26 by lyvan-de          #+#    #+#             */
/*   Updated: 2026/01/24 13:47:53 by lyvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdint.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <errno.h>
# include <string.h>
# include <math.h>
# include "../../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include "objects.h"
# include "parsing.h"

# define WIDTH 1600
# define HEIGHT 800
# define PI 3.14159265358979323846
# define EPSILON 1e-6

typedef struct s_context
{
	mlx_t			*mlx;
	mlx_image_t		*image;
	t_world			*world;
}	t_context;

//ray functions
int		ray_color(t_context	*context, int x, int y);
t_tuple	find_dir(t_viewport view, t_camera cam, int x, int y);
t_tuple	get_rgb(t_ray *ray, t_list *object, t_context *context);
t_ray	transform_ray(t_ray r, t_matrix4 mat);
void	my_keyhook(mlx_key_data_t keydata, void *param);
t_hit	hit_object(t_ray *world_ray, t_list *object, t_object *ignore);

#endif
