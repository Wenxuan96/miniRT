/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a12708 <a12708@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 14:40:25 by lyvan-de          #+#    #+#             */
/*   Updated: 2025/11/03 14:08:17 by a12708           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H
# include "vector.h"
# include "graphics.h"

typedef struct s_sphere
{
	t_vec3	position;
	double	diameter;
	t_rgb	color;
}	t_sphere;

typedef struct s_camera
{
	t_vec3	position;
	t_vec3	orientation;
	int		fov;
	t_vec3	world_up;
}	t_camera;

typedef struct	s_viewport
{
	double	plane_width;
	double	plane_height;
	t_vec3	viewport_u;
	t_vec3	viewport_v;
	t_vec3	pixel_delta_u;
	t_vec3	pixel_delta_v;
	t_vec3	upper_left;
}	t_viewport;

typedef struct s_ambient
{
	double	ratio;
	t_rgb	color;
}	t_ambient;

typedef struct t_light
{
	t_vec3	origin;
	double	ratio;
}	t_light;

//fucntions to create mock data
t_camera	*camera(void);
t_sphere	*sphere(void);
t_ambient	*ambient(void);
t_light		*light(void);

t_viewport	*set_viewport(t_camera *camera);

#endif
