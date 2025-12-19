/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_utils1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxi <wxi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 18:00:15 by lyvan-de          #+#    #+#             */
/*   Updated: 2025/12/19 19:43:38 by wxi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/vector.h"

t_vec4	vec4(double x, double y, double z, double w)
{
	return ((t_vec4){x, y, z, w});
}

t_vec4	vec4_add(t_vec4 a, t_vec4 b)
{
	return ((t_vec4){a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w});
}

t_vec4	vec4_sub(t_vec4 a, t_vec4 b)
{
	return ((t_vec4){a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w});
}

t_vec4	vec4_mult(t_vec4 v, double s)
{
	return ((t_vec4){v.x * s, v.y * s, v.z * s, v.w * s});
}

t_vec4	vec4_div(t_vec4 v, double s)
{
	return ((t_vec4){v.x / s, v.y / s, v.z / s, v.w / s});
}
