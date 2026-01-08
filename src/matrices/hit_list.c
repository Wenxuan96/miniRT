/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxi <wxi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:40:51 by wxi               #+#    #+#             */
/*   Updated: 2026/01/08 13:27:55 by wxi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/miniRT.h"

t_x_list	*add_x_obj(void *x_obj, double discriminant, double t_val, int n)
{
	t_x_list *new_obj;

	new_obj = malloc(sizeof(t_x_list));
	if (!new_obj)
		return NULL;
	new_obj->cur_x_obj = x_obj;
	new_obj->t = t_val;
	new_obj->hit_count = n;
	new_obj->next_x_obj = NULL;
	
	return new_obj;
}

t_x_list	*x_obj_to_list(t_x_list *i1, t_x_list *i2)
{
	t_x_list *x_obj_lst;

	x_obj_lst = i1;
	x_obj_lst->next_x_obj = i2;
	
	return x_obj_lst;
}

t_x_list	*find_1st_hit(t_x_list *x_obj_lst)
{
	t_x_list	*first_hit;
	t_x_list	*cur_x_obj;
	double		smlst_non_neg_t;
	
	cur_x_obj = x_obj_lst;
	first_hit = cur_x_obj;
	smlst_non_neg_t = cur_x_obj->t;
	while (cur_x_obj != NULL)
	{
		if (cur_x_obj->t >= 0)
		{
			if (smlst_non_neg_t >= cur_x_obj->t)
			{
				smlst_non_neg_t = cur_x_obj->t;
				first_hit = cur_x_obj;
			}
		}
		while (smlst_non_neg_t < 0)//skip negtive ones
			cur_x_obj = cur_x_obj->next_x_obj;
		cur_x_obj = cur_x_obj->next_x_obj;
	}
	return first_hit;
}

t_tuple	position(t_ray r, double t)
{
	t_tuple rt;

	rt = tuple_mult(r.vector, t);
	rt = tuple_add(r.point, rt);
	return rt;
}

double	get_discriminant(t_tuple ray, t_camera *cam, t_sphere *sph)
{
	t_tuple		origin_center;
	double		a;
	double		b;
	double		c;
	double		radius;
	double		discriminant;

	radius = sph->diameter / 2;
	origin_center = tuple_sub(cam->position, sph->position);
	a = tuple_dot(ray, ray);
	b = 2.0 * tuple_dot(ray, origin_center);
	c = tuple_dot(origin_center, origin_center) - (radius * radius);
	discriminant = b * b - 4 * a * c;

	return discriminant;
}

double	*hit_sphere(t_tuple ray, t_camera *cam, t_sphere *sph)
{
	double		discriminant;
	t_x_list	*new_x_obj;
	t_tuple		origin_center;
	double		*t;
	double		a;
	double		b;

	t = malloc(3 * sizeof(double));
	a = tuple_dot(ray, ray);
	b = 2.0 * tuple_dot(ray, origin_center);
	origin_center = tuple_sub(cam->position, sph->position);
	discriminant = get_discriminant(ray, cam, sph);
	if (!t || discriminant < 0)
		return NULL;
	t[0] = (-b - sqrt(discriminant)) / (2.0 * a);
	t[1] = (-b + sqrt(discriminant)) / (2.0 * a);
	return t;
}

// int	main(void)
// {
// 	t_ray		r;
// 	t_tuple		new_pos;
// 	t_sphere	*sph;
// 	t_sphere	*xs;

// 	r.point = tuple(0, 0, -5, 1);
// 	r.vector = tuple(0, 0, 1, 0);
// 	new_pos = position(r, 2.5);
// 	sph = sphere();
// 	xs = intersect(sph, r);
// 	printf("new pos(%f, %f, %f, %f)\n", new_pos.x, new_pos.y, new_pos.z, new_pos.w);
// }