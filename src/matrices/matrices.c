/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxi <wxi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 11:15:22 by wxi               #+#    #+#             */
/*   Updated: 2026/01/27 14:22:29 by wxi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/miniRT.h"

t_matrix4	assign_mat_val(double val)
{
	t_matrix4	m;
	int			i;
	int			j;

	j = 0;
	i = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			m.m4[i][j] = val * (float)rand() / (float)RAND_MAX;
			j++;
		}
		j = 0;
		i++;
	}
	return (m);
}

t_matrix4	identity_m4(void)
{
	t_matrix4	m;
	int			i;
	int			j;

	j = 0;
	i = 0;
	while (i < 4)
	{
		while (j < 4)
		{
			if (i == j)
				m.m4[i][j] = 1;
			else
				m.m4[i][j] = 0;
			j++;
		}
		j = 0;
		i++;
	}
	return (m);
}

t_matrix4	multi_mat(t_matrix4 a, t_matrix4 b)
{
	t_matrix4	new_m;
	int			row;
	int			col;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			new_m.m4[row][col] = a.m4[row][0] * b.m4[0][col]
				+ a.m4[row][1] * b.m4[1][col]
				+ a.m4[row][2] * b.m4[2][col]
				+ a.m4[row][3] * b.m4[3][col];
			col++;
		}
		row++;
	}
	return (new_m);
}

t_matrix4	transpose_mat(t_matrix4 a)
{
	t_matrix4	new_m;
	int			row;
	int			col;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			new_m.m4[row][col] = a.m4[col][row];
			col++;
		}
		row++;
	}
	return (new_m);
}

t_tuple	matxtuple(t_matrix4 a, t_tuple tup)
{
	t_tuple	new_tup;

	new_tup.x = a.m4[0][0] * tup.x + a.m4[0][1] * tup.y
		+ a.m4[0][2] * tup.z + a.m4[0][3] * tup.w;
	new_tup.y = a.m4[1][0] * tup.x + a.m4[1][1] * tup.y
		+ a.m4[1][2] * tup.z + a.m4[1][3] * tup.w;
	new_tup.z = a.m4[2][0] * tup.x + a.m4[2][1] * tup.y
		+ a.m4[2][2] * tup.z + a.m4[2][3] * tup.w;
	new_tup.w = a.m4[3][0] * tup.x + a.m4[3][1] * tup.y
		+ a.m4[3][2] * tup.z + a.m4[3][3] * tup.w;
	return (new_tup);
}
