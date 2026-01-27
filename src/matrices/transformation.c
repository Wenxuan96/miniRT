/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxi <wxi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 14:18:56 by wxi               #+#    #+#             */
/*   Updated: 2026/01/27 14:22:05 by wxi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/miniRT.h"

t_matrix4	translation(double x, double y, double z)
{
	t_matrix4	rt_matrix;

	rt_matrix = identity_m4();
	rt_matrix.m4[0][3] = x;
	rt_matrix.m4[1][3] = y;
	rt_matrix.m4[2][3] = z;
	return (rt_matrix);
}

t_matrix4	mat_scaling(double x, double y, double z)
{
	t_matrix4	rt_matrix;

	rt_matrix = identity_m4();
	rt_matrix.m4[0][0] = x;
	rt_matrix.m4[1][1] = y;
	rt_matrix.m4[2][2] = z;
	return (rt_matrix);
}

t_matrix4	shearing(t_shearing sh)
{
	t_matrix4	rt_matrix;

	rt_matrix = identity_m4();
	rt_matrix.m4[0][1] = sh.x_y;
	rt_matrix.m4[0][2] = sh.x_z;
	rt_matrix.m4[1][0] = sh.y_x;
	rt_matrix.m4[1][2] = sh.y_z;
	rt_matrix.m4[2][0] = sh.z_x;
	rt_matrix.m4[2][1] = sh.z_y;
	return (rt_matrix);
}

t_matrix4	rotation(t_tuple axis, double angle)
{
	t_matrix4	r;
	double		c;
	double		s;

	r = identity_m4();
	c = cos(angle);
	s = sin(angle);
	r.m4[0][0] = (1 - c) * axis.x * axis.x + c;
	r.m4[0][1] = (1 - c) * axis.x * axis.y - s * axis.z;
	r.m4[0][2] = (1 - c) * axis.x * axis.z + s * axis.y;
	r.m4[1][0] = (1 - c) * axis.x * axis.y + s * axis.z;
	r.m4[1][1] = (1 - c) * axis.y * axis.y + c;
	r.m4[1][2] = (1 - c) * axis.y * axis.z - s * axis.x;
	r.m4[2][0] = (1 - c) * axis.x * axis.z - s * axis.y;
	r.m4[2][1] = (1 - c) * axis.y * axis.z + s * axis.x;
	r.m4[2][2] = (1 - c) * axis.z * axis.z + c;
	r.m4[0][3] = 0;
	r.m4[1][3] = 0;
	r.m4[2][3] = 0;
	r.m4[3][0] = 0;
	r.m4[3][1] = 0;
	r.m4[3][2] = 0;
	r.m4[3][3] = 1;
	return (r);
}

t_ray	transform_ray(t_ray r, t_matrix4 mat)
{
	t_ray	new_r;

	r.origin.w = 1;
	r.direction.w = 0;
	new_r.origin = matxtuple(mat, r.origin);
	new_r.direction = matxtuple(mat, r.direction);
	new_r.origin.w = 1;
	new_r.direction.w = 0;
	new_r.direction = tuple_norm(new_r.direction);
	return (new_r);
}
