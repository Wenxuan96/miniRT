/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyvan-de <lyvan-de@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:40:51 by wxi               #+#    #+#             */
/*   Updated: 2026/01/14 15:55:11 by lyvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/miniRT.h"

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

void	assign_hit_count(t_ray *r, double hit1, double hit2)
{
	if (hit1 > 0 && hit2 > 0)
	{
		r->hit_count = 2;
	}
	if ((hit1 > 0 && hit2 <= 0) || (hit2 > 0 && hit1 <= 0))
	{
		r->hit_count = 1;
	}
	if (hit1 <= 0 && hit2 <= 0)
		r->hit_count = 0;
}

void hit_sphere(t_ray *r, t_sphere *sph)
{
	t_tuple		origin_center;
	double		a;
	double		b;
	double		c;
	double		radius;
	double		discriminant;

	radius = sph->diameter / 2;
	origin_center = tuple_sub(r->origin, sph->position);
	a = tuple_dot(r->direction, r->direction);
	b = 2.0 * tuple_dot(r->direction, origin_center);
	c = tuple_dot(origin_center, origin_center) - (radius * radius);
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		r->hit_count = 0;
	else
	{
		r->hit_points[0] = (-b - sqrt(discriminant)) / (2.0 * a);
		r->hit_points[1] = (-b + sqrt(discriminant)) / (2.0 * a);
		r->hit_count = 2;
		//assign_hit_count(r, r->hit_points[0], r->hit_points[1]);
	}
}

