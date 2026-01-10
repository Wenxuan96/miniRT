/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a12708 <a12708@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 13:31:26 by lyvan-de          #+#    #+#             */
/*   Updated: 2026/01/10 20:08:59 by a12708           ###   ########.fr       */
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
# include "../../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include "objects.h"
# include "parsing.h"

# define WIDTH 800
# define HEIGHT 400
# define PI 3.14159265358979323846

typedef struct s_context
{
	mlx_t			*mlx;
	mlx_image_t		*image;
	t_world			*world;
}	t_context;

//ray functions
int		ray_color(t_context	*context, int x, int y);
t_tuple	find_dir(t_viewport *view, t_camera *cam, int x, int y);
t_tuple	get_rgb(t_tuple ray, t_camera *cam);
t_tuple	map(t_tuple *obj_input);

// int		ray_color(t_context	*context, int x, int y);
// t_tuple	find_dir(t_viewport *view, t_camera *cam, int x, int y);
// t_tuple	get_rgb(t_tuple ray, t_camera *cam);
// t_tuple	map(t_tuple *obj_input);

#endif
