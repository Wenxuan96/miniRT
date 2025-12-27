/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a12708 <a12708@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 18:00:30 by lyvan-de          #+#    #+#             */
/*   Updated: 2025/12/25 20:46:22 by a12708           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H
# include <math.h>

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

typedef struct s_vec4
{
	double	x;
	double	y;
	double	z;
	double	w;
}	t_vec4;

typedef struct s_matrix4
{
	double m4[4][4];
}	t_matrix4;

t_vec4	vec4(double x, double y, double z, double w);
t_vec4	vec4_add(t_vec4 a, t_vec4 b);
t_vec4	vec4_sub(t_vec4 a, t_vec4 b);
double	vec4_dot(t_vec4 a, t_vec4 b);
t_vec4	vec4_div(t_vec4 v, double s);
t_vec4	vec4_norm(t_vec4 v);
t_vec4	vec4_mult(t_vec4 v, double s);
t_vec4	vec4_cross(t_vec4 a, t_vec4 b);
t_matrix4 create_mat(int p);
t_matrix4 multi_mat(t_matrix4 a, t_matrix4 b);
t_matrix4 transpose_mat(t_matrix4 a);
t_vec4 matXtuple(t_matrix4 a, t_vec4 tup);

// t_vec3	vec3(double x, double y, double z);
// t_vec3	vec3_add(t_vec3 a, t_vec3 b);
// t_vec3	vec3_sub(t_vec3 a, t_vec3 b);
// t_vec3	vec3_mult(t_vec3 v, double s);
// t_vec3	vec3_div(t_vec3 v, double s);
// t_vec3	vec3_norm(t_vec3 v);
// double	vec3_dot(t_vec3 a, t_vec3 b);
// t_vec3	vec3_cross(t_vec3 a, t_vec3 b);

#endif