/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyvan-de <lyvan-de@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 18:00:30 by lyvan-de          #+#    #+#             */
/*   Updated: 2025/10/13 15:54:04 by lyvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include "objects.h"

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

t_vec3	vec3(double x, double y, double z);
t_vec3	vec3_add(t_vec3 a, t_vec3 b);
t_vec3	vec3_sub(t_vec3 a, t_vec3 b);
t_vec3	vec3_mult(t_vec3 v, double s);
t_vec3	vec3_div(t_vec3 v, double s);
t_vec3	vec3_norm(t_vec3 v);

#endif