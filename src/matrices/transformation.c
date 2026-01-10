/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a12708 <a12708@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 13:41:18 by wxi               #+#    #+#             */
/*   Updated: 2026/01/10 21:51:30 by a12708           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/miniRT.h"

t_matrix4 translation(double x, double y, double z)
{
	t_matrix4 rt_matrix;
	
	rt_matrix = identity_m4();
	rt_matrix.m4[0][3] = x;
	rt_matrix.m4[1][3] = y;
	rt_matrix.m4[2][3] = z;
	return rt_matrix;
}

t_matrix4 scaling(double x, double y, double z)
{
	t_matrix4 rt_matrix;
	
	rt_matrix = identity_m4();
	rt_matrix.m4[0][0] = x;
	rt_matrix.m4[1][1] = y;
	rt_matrix.m4[2][2] = z;
	return rt_matrix;
}

t_matrix4 shearing(t_shearing sh)
{
	t_matrix4 rt_matrix;
	
	rt_matrix = identity_m4();
	rt_matrix.m4[0][1] = sh.x_y;
	rt_matrix.m4[0][2] = sh.x_z;
	rt_matrix.m4[1][0] = sh.y_x;
	rt_matrix.m4[1][2] = sh.y_z;
	rt_matrix.m4[2][0] = sh.z_x;
	rt_matrix.m4[2][1] = sh.z_y;
	return rt_matrix;
}

t_matrix4 rotation_x(double radians)
{
	t_matrix4 rt_matrix;
	
	rt_matrix = identity_m4();
	rt_matrix.m4[1][1] = cos(radians);
	rt_matrix.m4[1][2] = -sin(radians);
	rt_matrix.m4[2][1] = sin(radians);
	rt_matrix.m4[2][2] = cos(radians);
	return rt_matrix;
}

t_matrix4 rotation_y(double radians)
{
	t_matrix4 rt_matrix;
	
	rt_matrix = identity_m4();
	rt_matrix.m4[0][0] = cos(radians);
	rt_matrix.m4[0][2] = sin(radians);
	rt_matrix.m4[2][0] = -sin(radians);
	rt_matrix.m4[2][2] = cos(radians);
	return rt_matrix;
}

t_matrix4 rotation_z(double radians)
{
	t_matrix4 rt_matrix;
	
	rt_matrix = identity_m4();
	rt_matrix.m4[0][0] = cos(radians);
	rt_matrix.m4[0][1] = -sin(radians);
	rt_matrix.m4[1][0] = sin(radians);
	rt_matrix.m4[1][1] = cos(radians);
	return rt_matrix;
}

t_ray	transform_ray(t_ray r, t_matrix4 mat)
{
	t_ray	new_r;

	new_r.origin = matXtuple(mat, r.origin);
	new_r.direction = matXtuple(mat, r.direction);

	return new_r;
}

int main(void)
{
	t_matrix4 	a;
	t_ray 		r1;
	t_ray 		r2;
	// t_matrix4 	inverted_a;
	// double 		m4_deter;

	r1.direction= (t_tuple){0, 1, 0, 0};
	r1.origin= (t_tuple){1, 2, 3, 1};
	a = translation(3, 4, 5);
	r2 = transform_ray(r1, a);
	printf("r2.origin(%f, %f, %f, %f)\n",
       		r2.origin.x,
       		r2.origin.y,
       		r2.origin.z,
       		r2.origin.w);
	return 0;	
}