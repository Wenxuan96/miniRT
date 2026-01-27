/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxi <wxi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 13:31:26 by lyvan-de          #+#    #+#             */
/*   Updated: 2026/01/27 16:24:59 by wxi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include "objects.h"
# include "parsing.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <unistd.h>

# define WIDTH 1600
# define HEIGHT 800
# define PI 3.14159265358979323846
# define EPSILON 1e-6

typedef struct s_context
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	t_world		*world;
}				t_context;

// ray functions
int				ray_color(t_context *context, int x, int y);
t_tuple			find_dir(t_viewport view, t_camera cam, int x, int y);
t_tuple			get_rgb(t_ray *ray, t_list *object, t_context *context);
t_ray			transform_ray(t_ray r, t_matrix4 mat);
void			my_keyhook(mlx_key_data_t keydata, void *param);
t_hit			hit_object(t_ray *world_ray, t_list *object, t_object *ignore);
t_tuple			get_color(t_object *obj, t_ambient world_amb, double intensity);
t_tuple			cy_rgb(t_cylinder *cy, t_hit hit, t_context *context);
t_tuple			color_obj(t_hit *hit, t_world *world, t_tuple *unit_norm);
t_tuple			normal_object(t_hit *hit, t_tuple unit_hit_p);

#endif
