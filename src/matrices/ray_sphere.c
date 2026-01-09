/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxi <wxi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:40:51 by wxi               #+#    #+#             */
/*   Updated: 2026/01/09 12:14:00 by wxi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/miniRT.h"

t_intersec	*assign_inter(double t, void *obj_type)
{
	t_intersec *cur_inter_obj;

	cur_inter_obj->t_val = t;
	cur_inter_obj->x_object = obj_type;
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

t_intersec	*first_hit(t_intersec *inter_lst)
{
	t_intersec	*nearest_hit;
	t_intersec	*cur_inter_obj;
	double		smlst_non_neg_t;
	
	cur_inter_obj = inter_lst;
	nearest_hit = cur_inter_obj;
	smlst_non_neg_t = cur_inter_obj->t_val;
	while (cur_inter_obj != NULL)
	{
		while (smlst_non_neg_t < 0)
		{
			cur_inter_obj = cur_inter_obj->next_intersec;
			smlst_non_neg_t = cur_inter_obj->t_val;
		}
		if (cur_inter_obj->next_intersec != NULL
			&& smlst_non_neg_t >= cur_inter_obj->next_intersec->t_val)
		{
			cur_inter_obj = cur_inter_obj->next_intersec;
			smlst_non_neg_t = cur_inter_obj->t_val;
		}					
		cur_inter_obj = cur_inter_obj->next_intersec;
	}
}

t_tuple	position(t_ray r, double t)
{
	t_tuple rt;

	rt = tuple_mult(r.direction, t);
	rt = tuple_add(r.origin, rt);
	return rt;
}

double	*hit_sphere(t_ray r, t_sphere *sph)
{
	t_tuple		origin_center;
	double		a;
	double		b;
	double		c;
	double		radius;
	double		discriminant;
	double		rt[2];

	radius = sph->diameter / 2;
	origin_center = tuple_sub(r.origin, sph->position);
	a = tuple_dot(r.direction, r.direction);
	b = 2.0 * tuple_dot(r.direction, origin_center);
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

	r.origin = new_tuple(0, 0, -5, 1);
	r.direction = new_tuple(0, 0, 1, 0);
	new_pos = position(r, 2.5);
	sph = sphere();
	xs = intersect(sph, r);
	printf("new pos(%f, %f, %f, %f)\n", new_pos.x, new_pos.y, new_pos.z, new_pos.w);
}