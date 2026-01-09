/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxi <wxi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 13:41:18 by wxi               #+#    #+#             */
/*   Updated: 2026/01/06 15:48:49 by wxi              ###   ########.fr       */
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

// int main(void)
// {
// 	t_matrix4 	a;
// 	t_matrix4 	b;
// 	t_matrix4 	c;
// 	t_matrix4 	t;
// 	// t_matrix4 	inverted_a;
// 	t_tuple		tup;
// 	t_tuple		new_tup;
// 	// double 		m4_deter;
	
// 	a = rotation_x(PI / 2);
// 	b = scaling(5, 5, 5);
// 	c = translation(10, 5, 7);

// 	t = multi_mat(multi_mat(c, b), a);
// 	// printf("a:\n");
// 	// prt_mat(a);
// 	// printf("\n");
// 	// a = invert_m4(a);
// 	tup = tuple(1, 0, 1, 1);
// 	new_tup = matXtuple(t, tup);
// 	// new_tup = matXtuple(b, new_tup);
// 	// new_tup = matXtuple(c, new_tup);
// 	// m4_deter = get_m4_deter(&a);
// 	// inverted_a = invert_m4(a);

// 	// printf("m4_deter: %f\n", a.m4_deter);
// 	// printf("inverted_a:\n");
// 	// prt_mat(a);
// 	// printf("\n");
// 	// system("python3 test.py");
// 	// printf("\n");
// 	// tup = tuple(2, 2, 1, 0);
// 	// printf("tup(%f, %f, %f, %f)\n", tup.x, tup.y, tup.z, tup.w);
// 	// new_tup = matXtuple(a, tup);
// 	printf("new tup(%f, %f, %f, %f)\n", new_tup.x, new_tup.y, new_tup.z, new_tup.w);
	
// 	return 0;	
// }