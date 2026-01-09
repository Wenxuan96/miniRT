/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyvan-de <lyvan-de@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 14:40:25 by lyvan-de          #+#    #+#             */
/*   Updated: 2026/01/07 18:11:24 by lyvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H
# include "vector.h"
# include "graphics.h"
# include "../libft/libft.h"

typedef struct s_sphere
{
	t_tuple	position;
	double	diameter;
	t_rgb	color;
}	t_sphere;

typedef struct s_plane
{
	t_tuple	point;
	t_tuple	normal;
	t_rgb	color;
}	t_plane;

typedef struct s_cylinder
{
	t_tuple	center;
	t_tuple	axis;
	double	diameter;
	double	heigth;
	t_rgb	color;
}	t_cylinder;


typedef struct s_camera
{
	t_tuple	position;
	t_tuple	orientation;
	int		fov;
	t_tuple	world_up;
}	t_camera;

typedef struct	s_viewport
{
	double	plane_width;
	double	plane_height;
	t_tuple	viewport_u;
	t_tuple	viewport_v;
	t_tuple	pixel_delta_u;
	t_tuple	pixel_delta_v;
	t_tuple	upper_left;
}	t_viewport;

typedef struct s_ambient
{
	double	ratio;
	t_rgb	color;
}	t_ambient;

typedef struct t_light
{
	t_tuple	origin;
	double	ratio;
}	t_light;

typedef struct s_scene
{
	t_ambient	ambient;
	t_camera	camera;
	t_light		light;
	bool		has_ambient;
	bool		has_camera;
	bool		has_light;
	t_list		*objects;
} 	t_scene;

//fucntions to create mock data
t_camera	*camera(void);
t_sphere	*sphere(void);
t_ambient	*ambient(void);
t_light		*light(void);

t_viewport	*set_viewport(t_camera camera);

#endif
