/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxi <wxi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 14:40:25 by lyvan-de          #+#    #+#             */
/*   Updated: 2026/01/08 12:23:25 by wxi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H
# include "vector.h"
# include "graphics.h"

#define MAX_OBJECTS 100

typedef struct s_sphere
{
	t_tuple         position;
	double          diameter;
	t_tuple         color;
    t_matrix4       transform;       // translation, scaling, rotation
	// t_tuple      origin;          // center of sphere
    // t_matrix4    inverse_transform;
    // int          material_id;     // optional, points to material properties
}	t_sphere;

typedef struct s_plane
{
    t_tuple      origin;          // a point on the plane
    t_tuple      normal;          // normalized direction
    t_matrix4    transform;
    t_matrix4    inverse_transform;
    int          material_id;
}   t_plane;

typedef struct s_cylinder
{
    t_tuple      origin;          // base center
    double       radius;
    double       height;          // could be infinite
    t_matrix4    transform;
    t_matrix4    inverse_transform;
    int          material_id;
}   t_cylinder;

typedef struct s_ray
{
	t_tuple	point;
	t_tuple	vector;
}	t_ray;

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
	t_tuple	color;
}	t_ambient;

typedef struct t_light
{
	t_tuple	origin;
	double	ratio;
}	t_light;

typedef struct s_x_list
{
	void			*cur_x_obj;
	double			t;
	int				hit_count;
	struct s_x_list	*next_x_obj;
}	t_x_list;

typedef struct s_scene
{
	t_ambient	ambient;
	t_camera	camera;
	t_light		light;
	bool		has_ambient;
	bool		has_camera;
	bool		has_light;
	t_list		*objects;
	t_list		*x_objs;
} 	t_scene;

//fucntions to create mock data
t_camera	*camera(void);
t_sphere	*sphere(void);
t_ambient	*ambient(void);
t_light		*light(void);
t_viewport	*set_viewport(t_camera *camera);

#endif
