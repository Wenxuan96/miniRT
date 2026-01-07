/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxi <wxi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:40:51 by wxi               #+#    #+#             */
/*   Updated: 2026/01/07 15:08:54 by wxi              ###   ########.fr       */
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

typedef struct s_intersec
{
	double		t_val;
	t_obj_type	type;
	t_intersec	*next_intersec;
}	t_intersec;

t_intersec	*assign_inter(double t, t_obj_type obj_type)
{
	t_intersec *cur_inter_obj;

	cur_inter_obj->t_val = t;
	cur_inter_obj->type = obj_type;
	cur_inter_obj->next_intersec = NULL;
	
	return cur_inter_obj;
}

t_intersec	*add_inter(t_intersec *i1, t_intersec *i2)
{
	t_intersec *inter_lst;
	
	inter_lst = i1;
	inter_lst->next_intersec = i2;
	
	return inter_lst;
}

t_intersec	*hit(t_intersec *inter_lst)
{
	t_intersec	*nearest_hit;
	t_intersec	*cur_inter_obj;
	double		smlst_non_neg_t;
	
	cur_inter_obj = inter_lst;
	nearest_hit = cur_inter_obj;
	smlst_non_neg_t = cur_inter_obj->t_val;
	while (cur_inter_obj != NULL)
	{
		if (cur_inter_obj->t_val >= 0)
		{
			if (smlst_non_neg_t >= cur_inter_obj->t_val)
			{
				smlst_non_neg_t = cur_inter_obj->t_val;
				nearest_hit = cur_inter_obj;
			}
		}
		while (smlst_non_neg_t < 0)//skip negtive ones
			cur_inter_obj = cur_inter_obj->next_intersec;
		cur_inter_obj = cur_inter_obj->next_intersec;
	}
	return nearest_hit;
}

t_tuple	position(t_ray r, double t)
{
	t_tuple rt;

	rt = tuple_mult(r.vector, t);
	rt = tuple_add(r.point, rt);
	return rt;
}

double	*hit_sphere(t_tuple ray, t_camera *cam, t_sphere *sph)
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