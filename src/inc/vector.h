/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyvan-de <lyvan-de@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 18:00:30 by lyvan-de          #+#    #+#             */
/*   Updated: 2026/01/14 15:03:03 by lyvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H
# include <math.h>
# include <stdio.h>

typedef struct s_tuple
{
	double	x;
	double	y;
	double	z;
	double	w;
}	t_tuple;

typedef struct s_matrix4
{
	double	m4[4][4];
	double	m4_deter;
}	t_matrix4;

typedef struct  s_shearing
{
	double	x_y;
	double	x_z;
	double	y_x;
	double	y_z;
	double	z_x;
	double	z_y;
}	t_shearing;


t_tuple	new_tuple(double x, double y, double z, double w);
t_tuple	tuple_add(t_tuple a, t_tuple b);
t_tuple	tuple_sub(t_tuple a, t_tuple b);
double	tuple_dot(t_tuple a, t_tuple b);
t_tuple	tuple_div(t_tuple v, double s);
t_tuple	tuple_norm(t_tuple v);
t_tuple	tuple_mult(t_tuple v, double s);
t_tuple	tuple_cross(t_tuple a, t_tuple b);

t_matrix4	assign_mat_val(double val);
t_matrix4	multi_mat(t_matrix4 a, t_matrix4 b);
t_matrix4	transpose_mat(t_matrix4 a);
t_tuple		matXtuple(t_matrix4 a, t_tuple tup);
t_matrix4	identity_m4();
t_matrix4	invert_m4(t_matrix4 src_m4);
double		get_m4_deter(t_matrix4 *org_mat);
void		prt_mat(t_matrix4 m);

// typedef struct s_vec3
// {
// 	double	x;
// 	double	y;
// 	double	z;
// }	t_vec3;

// t_vec3	vec3(double x, double y, double z);
// t_vec3	vec3_add(t_vec3 a, t_vec3 b);
// t_vec3	vec3_sub(t_vec3 a, t_vec3 b);
// t_vec3	vec3_mult(t_vec3 v, double s);
// t_vec3	vec3_div(t_vec3 v, double s);
// t_vec3	vec3_norm(t_vec3 v);
// double	vec3_dot(t_vec3 a, t_vec3 b);
// t_vec3	vec3_cross(t_vec3 a, t_vec3 b);

#endif