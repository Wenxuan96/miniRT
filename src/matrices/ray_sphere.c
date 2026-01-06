/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxi <wxi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:40:51 by wxi               #+#    #+#             */
/*   Updated: 2026/01/06 18:16:59 by wxi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/miniRT.h"

typedef struct s_ray
{
	t_tuple	point;
	t_tuple	vector;
}	t_ray;

typedef enum e_obj_type 
{ 
	SPHERE, 
	PLANE, 
	CYLINDER 
} t_obj_type; 

typedef struct s_object 
{ 
	t_obj_type	type; 
	void		*data; 
} t_object;

typedef struct s_intersection
{
	double			*t_vals;
	t_obj_type		type;
}	t_intersection;

t_tuple	position(t_ray r, double t)
{
	t_tuple rt;

	rt = tuple_mult(r.vector, t);
	rt = tuple_add(r.point, rt);
	return rt;
}

double	*hit_sphere(t_tuple ray, t_camera *cam, t_sphere	*sph)
{
	t_tuple		origin_center;
	double		a;
	double		b;
	double		c;
	double		radius;
	double		discriminant;
	double		rt[2];

	radius = sph->diameter / 2;
	origin_center = tuple_sub(cam->position, sph->position);
	a = tuple_dot(ray, ray);
	b = 2.0 * tuple_dot(ray, origin_center);
	c = tuple_dot(origin_center, origin_center) - (radius * radius);
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		return NULL;
	else
	{
		rt[0] = (-b - sqrt(discriminant)) / (2.0 * a);
		rt[1] = (-b + sqrt(discriminant)) / (2.0 * a);
	}
	return rt;
}

int	main(void)
{
	t_ray		r;
	t_tuple		new_pos;
	t_sphere	*sph;
	t_sphere	*xs;

	r.point = tuple(0, 0, -5, 1);
	r.vector = tuple(0, 0, 1, 0);
	new_pos = position(r, 2.5);
	sph = sphere();
	xs = intersect(sph, r);
	printf("new pos(%f, %f, %f, %f)\n", new_pos.x, new_pos.y, new_pos.z, new_pos.w);
}