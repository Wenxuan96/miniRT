/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyvan-de <lyvan-de@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 14:40:25 by lyvan-de          #+#    #+#             */
/*   Updated: 2025/11/06 15:00:32 by lyvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H
# include "vector.h"
# include "graphics.h"

typedef	struct s_list
{
	void			*object;
	struct s_list	*next;
}	t_list;

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

typedef struct s_scene
{
	t_ambient	ambient;
	t_camera	camera;
	t_list		lights;
	t_list		objects;
} 	t_scene;

//fucntions to create mock data
t_camera	*camera(void);
t_sphere	*sphere(void);
t_ambient	*ambient(void);
t_light		*light(void);
t_viewport	*set_viewport(t_camera *camera);

#endif
