/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxi <wxi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:40:51 by wxi               #+#    #+#             */
/*   Updated: 2026/01/09 14:51:58 by wxi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/miniRT.h"

t_intersec	*assign_inter(double t[],  int hit_count, void *obj_type)
{
	t_intersec *i1;
	t_intersec *i2;
	
	if (hit_count == 0)
		return NULL;
	if (hit_count == 1)
	{
		i1->t_val = t[0];
		i1->x_object = obj_type;
		i1->next_intersec = NULL;
	}
	else if (hit_count == 2)
	{
		i1->t_val = t[0];
		i1->x_object = obj_type;
		i1->t_val = t[1];
		i2->x_object = obj_type;
		i2->next_intersec = NULL;
		i1->next_intersec = i2;
	}
	return i1;
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

void hit_sphere(t_ray r, t_sphere *sph)
{
	t_tuple		origin_center;
	double		a;
	double		b;
	double		c;
	double		radius;
	double		discriminant;

	radius = sph->diameter / 2;
	origin_center = tuple_sub(r.origin, sph->position);
	a = tuple_dot(r.direction, r.direction);
	b = 2.0 * tuple_dot(r.direction, origin_center);
	c = tuple_dot(origin_center, origin_center) - (radius * radius);
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		sph->hit_count = 0;
	else
	{
		sph->hit_points[0] = (-b - sqrt(discriminant)) / (2.0 * a);
		sph->hit_points[1] = (-b + sqrt(discriminant)) / (2.0 * a);
		if (sph->hit_points[0] == sph->hit_points[1])
			sph->hit_count = 1;
		else
			sph->hit_count = 2;
	}
}

void add_inter(t_intersec **i1, double t[], int hit_count, void *obj_type)
{
	t_intersec	*current;
	t_intersec	*nxt_inter;

	if (*i1 == NULL)
		*i1 = assign_inter(t, hit_count, obj_type);
	else
	{
		current = *i1;
		nxt_inter = assign_inter(t, hit_count, obj_type);
		while (current->next_intersec != NULL)
			current = current->next_intersec;
		current->next_intersec= nxt_inter;
	}
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