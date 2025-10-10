/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyvan-de <lyvan-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 14:40:25 by lyvan-de          #+#    #+#             */
/*   Updated: 2025/10/10 15:05:47 by lyvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

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
}	t_camera;

typedef struct	s_viewport
{
	double	plane_width;
	double	plane_height;
} t_viewport;

#endif
