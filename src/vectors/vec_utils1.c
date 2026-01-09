/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_utils1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyvan-de <lyvan-de@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 18:00:15 by lyvan-de          #+#    #+#             */
/*   Updated: 2026/01/07 18:30:04 by lyvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/vector.h"

t_tuple	new_tuple(double x, double y, double z, double w)
{
	return ((t_tuple){x, y, z, w});
}

t_tuple	tuple_add(t_tuple a, t_tuple b)
{
	return ((t_tuple){a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w});
}

t_tuple	tuple_sub(t_tuple a, t_tuple b)
{
	return ((t_tuple){a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w});
}

t_tuple	tuple_mult(t_tuple v, double s)
{
	return ((t_tuple){v.x * s, v.y * s, v.z * s, v.w * s});
}

t_tuple	tuple_div(t_tuple v, double s)
{
	return ((t_tuple){v.x / s, v.y / s, v.z / s, v.w / s});
}
