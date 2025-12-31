/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_utils1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxi <wxi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 18:00:15 by lyvan-de          #+#    #+#             */
/*   Updated: 2025/12/31 14:12:03 by wxi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/vector.h"

t_tuple	tuple(double x, double y, double z, double w)
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
