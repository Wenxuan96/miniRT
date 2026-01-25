/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxi <wxi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 14:40:25 by lyvan-de          #+#    #+#             */
/*   Updated: 2026/01/25 17:21:39 by wxi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H
# include "vector.h"
# include "graphics.h"
# include "../libft/libft.h"

typedef enum	e_obj_type
{
	SPHERE,
	PLANE,
	CYLINDER,
} t_obj_type;

typedef struct s_object
{
	t_obj_type	type;
	t_matrix4	transform;
	t_matrix4	inv_transform;
	t_rgb		color;
}	t_object;

typedef struct s_sphere
{
	t_object	base;
	t_tuple		position;
	double		diameter;
}	t_sphere;

typedef struct s_plane
{
	t_object	base;
	t_tuple		point;
	t_tuple		normal;

}	t_plane;

typedef struct s_cylinder
{
	t_object	base;
	t_tuple		center;
	t_tuple		axis;
	double		diameter;
	double		heigth;
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

typedef struct s_world
{
	t_ambient	ambient;
	t_camera	camera;
	t_light		light;
	t_viewport	view;
	bool		has_ambient;
	bool		has_camera;
	bool		has_light;
	t_list		*objects;
} 	t_world;

typedef struct s_ray
{
	t_tuple		origin;
	t_tuple		direction;
	double		hit_points[2];
}	t_ray;

typedef struct s_hit
{
	t_object	*object;
	t_ray		ray;
	double		t;
	double		world_dist;
}	t_hit;

void    	set_viewport(t_viewport	*viewport, t_camera camera);
t_matrix4	shearing(t_shearing sh);
t_matrix4	translation(double x, double y, double z);
double 		select_t(double t1, double t2);
double		intersect_unit_sphere(t_ray	*ray);
void		init_sphere_transform(t_sphere *sphere);
void		init_plane_transform(t_plane *pl);
double		intersect_unit_plane(t_ray	*ray);
double		light_intensity(t_tuple hit_point, t_tuple norm_hp,
				t_world *world, t_object *obj);

#endif
