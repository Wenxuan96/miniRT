/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a12708 <a12708@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:40:51 by wxi               #+#    #+#             */
/*   Updated: 2026/01/10 21:41:58 by a12708           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/miniRT.h"

t_intersec	*assign_inter(double t[],  int hit_count, void *obj_type)
{
	t_intersec *i1;
	t_intersec *i2;
	
	i1 = malloc(sizeof(t_intersec));
	if (!i1 || hit_count == 0)
		return NULL;
	if (hit_count == 1)
	{
		i1->t_val = t[0];
		i1->x_object = obj_type;
		i1->next_intersec = NULL;
	}
	else if (hit_count == 2)
	{
		i2 = malloc(sizeof(t_intersec));
		if (!i2)
			return i1;
		i1->t_val = t[0];
		i1->x_object = obj_type;
		i2->t_val = t[1];
		i2->x_object = obj_type;
		i2->next_intersec = NULL;
		i1->next_intersec = i2;
	}
	return i1;
}

t_intersec *first_hit(t_intersec *inter_lst)
{
    t_intersec *cur;
    t_intersec *nearest_hit;

	cur = inter_lst;
	nearest_hit = NULL;
    while (cur != NULL)
    {
        if (cur->t_val >= 0)
        {
            if (nearest_hit == NULL
				|| cur->t_val < nearest_hit->t_val)
                nearest_hit = cur;
        }
        cur = cur->next_intersec;
    }
    return nearest_hit;
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

// int	main(void)
// {
// 	t_ray		r;
// 	// t_tuple		new_pos;
// 	t_sphere	*sph;
// 	t_intersec	*xs;
// 	double		test[1];

// 	xs = NULL;
// 	r.origin = new_tuple(0, 0, 5, 1);
// 	r.direction = new_tuple(0, 0, 1, 0);
// 	// new_pos = position(r, 2.5);
// 	sph = sphere();
// 	hit_sphere(r, sph);
// 	printf("hit point[0]: %f, hit point[1]: %f\n", sph->hit_points[0], sph->hit_points[1]);
// 	add_inter(&xs, sph->hit_points, sph->hit_count, sph);
// 	test[0] = 1.5;
// 	add_inter(&xs, test, 1, sph);
// 	test[0] = -2;
// 	add_inter(&xs, test, 1, sph);
// 	test[0] = 2;
// 	add_inter(&xs, test, 1, sph);

// 	xs = first_hit(xs);
// 	printf("first hit point is: %f\n", xs->t_val);
// }