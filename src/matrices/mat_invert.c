/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_invert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxi <wxi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 12:51:23 by a12708            #+#    #+#             */
/*   Updated: 2026/01/27 14:04:05 by wxi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/miniRT.h"

void	reduce_mat_size(double m4[4][4], double m3[3][3],
						int skip_row, int skip_col)
{
	int		i;
	int		j;
	int		r;
	int		c;

	i = 0;
	r = 0;
	while (i < 4)
	{
		j = 0;
		c = 0;
		if (i == skip_row)
		{
			i++;
			continue ;
		}
		while (j < 4)
		{
			if (j != skip_col)
				m3[r][c++] = m4[i][j];
			j++;
		}
		i++;
		r++;
	}
}

double	get_m3_deter(t_matrix4 org_mat, int row, int col)
{
	double	m3[3][3];
	double	m3_deter;
	double	cofac_2_0;
	double	cofac_2_1;
	double	cofac_2_2;

	reduce_mat_size(org_mat.m4, m3, row, col);
	cofac_2_0 = m3[0][1] * m3[1][2] - m3[1][1] * m3[0][2];
	cofac_2_1 = (m3[0][0] * m3[1][2] - m3[1][0] * m3[0][2]) * -1;
	cofac_2_2 = m3[0][0] * m3[1][1] - m3[1][0] * m3[0][1];
	m3_deter = m3[2][0] * cofac_2_0 + m3[2][1]
		* cofac_2_1 + m3[2][2] * cofac_2_2;
	return (m3_deter);
}

double	get_m4_deter(t_matrix4 *org_mat)
{
	int		i;
	double	m4_deter;
	int		sign;

	i = 0;
	sign = 1;
	m4_deter = 0;
	while (i < 4)
	{
		if ((3 + i) % 2 == 1)
			sign = -1;
		else
			sign = 1;
		m4_deter += sign * get_m3_deter(*org_mat, 3, i) * (*org_mat).m4[3][i];
		i++;
	}
	return (m4_deter);
}

t_matrix4	invert_m4(t_matrix4 src_m4)
{
	t_matrix4	inverted_m4;
	int			sign;
	int			i;
	int			j;

	inverted_m4 = assign_mat_val(0);
	src_m4.m4_deter = get_m4_deter(&src_m4);
	if (fabs(src_m4.m4_deter) < 1e-9)
		return (inverted_m4);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			sign = 1;
			if ((i + j) % 2 == 1)
				sign = -1;
			inverted_m4.m4[i][j] = sign * get_m3_deter(src_m4, i, j)
				/ src_m4.m4_deter;
			j++;
		}
		i++;
	}
	return (transpose_mat(inverted_m4));
}
