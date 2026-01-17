/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxi <wxi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2026/01/17 16:38:44 by wxi              ###   ########.fr       */
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

t_matrix4 mat_scaling(double x, double y, double z)
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
    t_ray new_r;

    // Ensure origin is a point and direction is a vector
    r.origin.w = 1;
    r.direction.w = 0;

    // Transform both by the matrix
    new_r.origin = matXtuple(mat, r.origin);
    new_r.direction = matXtuple(mat, r.direction);

    // Reset w components to be safe
    new_r.origin.w = 1;
    new_r.direction.w = 0;

    // Normalize direction to avoid scaling effects
    new_r.direction = tuple_norm(new_r.direction);
	
	return new_r;
}

