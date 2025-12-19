/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxi <wxi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 15:54:21 by lyvan-de          #+#    #+#             */
/*   Updated: 2025/12/19 19:42:54 by wxi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/vector.h"

t_vec4	vec4_norm(t_vec4 v)
{
	double	len;

	len = sqrt(vec4_dot(v, v));
	return (vec4_div(v, len));
}

double	vec4_dot(t_vec4 a, t_vec4 b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w);
}

t_vec4	vec4_cross(t_vec4 a, t_vec4 b)
{
	t_vec4	c;

	c.x = a.y * b.z - a.z * b.y;
    c.y = a.z * b.x - a.x * b.z;
    c.z = a.x * b.y - a.y * b.x;
	c.w = 0;

	return (c);
}
