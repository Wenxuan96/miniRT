/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxi <wxi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 18:00:30 by lyvan-de          #+#    #+#             */
/*   Updated: 2026/01/27 13:58:33 by wxi              ###   ########.fr       */
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

typedef struct s_shearing
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
double	tuple_length(t_tuple a);

t_matrix4	assign_mat_val(double val);
t_matrix4	multi_mat(t_matrix4 a, t_matrix4 b);
t_matrix4	transpose_mat(t_matrix4 a);
t_tuple		matxtuple(t_matrix4 a, t_tuple tup);
t_matrix4	identity_m4();
t_matrix4	invert_m4(t_matrix4 src_m4);
t_matrix4	mat_scaling(double x, double y, double z);
double		get_m4_deter(t_matrix4 *org_mat);
void		prt_mat(t_matrix4 m);
t_matrix4	rotation(t_tuple axis, double angle);

#endif
