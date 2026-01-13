/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxi <wxi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 14:40:25 by lyvan-de          #+#    #+#             */
/*   Updated: 2026/01/13 13:25:33 by wxi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H
# include "vector.h"
# include "graphics.h"
# include "../libft/libft.h"

typedef struct s_sphere
{
	t_tuple		position;
	double		diameter;
	t_rgb		color;
	t_matrix4	transform;
	double		hit_points[2];
	int			hit_count;
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
	t_tuple	origin;
	t_tuple	direction;
}	t_ray;

typedef struct s_intersec
{
	double		t_val;
	void		*x_object;
	struct s_intersec	*next_intersec;
}	t_intersec;

//fucntions to create mock data
// t_camera	*camera(void);
// t_sphere	*sphere(void);
// t_ambient	*ambient(void);
// t_light		*light(void);


void    set_viewport(t_viewport	*viewport, t_camera camera);

//ray_sphere
void hit_sphere(t_ray r, t_sphere *sph);
void populate_i_list(t_intersec **i1, double t[], int hit_count, void *obj_type);
t_intersec *first_hit(t_intersec *inter_lst);
t_intersec	*assign_inter(double t[],  int hit_count, void *obj_type);
//transformation
t_ray	transform_ray(t_ray r, t_matrix4 mat);
t_matrix4 rotation_z(double radians);
t_matrix4 rotation_y(double radians);
t_matrix4 rotation_x(double radians);
t_matrix4 shearing(t_shearing sh);
t_matrix4 translation(double x, double y, double z);

#endif
