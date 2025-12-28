/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_invert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxi <wxi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 12:51:23 by a12708            #+#    #+#             */
/*   Updated: 2025/12/28 19:02:24 by wxi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/miniRT.h"

// static t_matrix4 mat3;
// static t_matrix4 mat2;
//make a function that returns the cofactor
//make a function that returns returns the determinant
//make a function that returns the submatrix
//a minor is the determinant of a submatrix
//determinant of a matix is the sum of cofactors of its minors

void	reduce_mat_size(double m4[4][4], double m3[3][3], int skip_row, int skip_col)
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
			continue;
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

double   get_m3_deter(t_matrix4 org_mat, int row, int col)
{
	double m3[3][3];
	double m3_deter;
	double cofac_2_0;
	double cofac_2_1;
	double cofac_2_2;

	reduce_mat_size(org_mat.m4, m3, row, col);
	cofac_2_0 = m3[0][1] * m3[1][2] - m3[1][1] * m3[0][2];
	cofac_2_1 = (m3[0][0] * m3[1][2] - m3[1][0] * m3[0][2]) * -1;
	cofac_2_2 = m3[0][0] * m3[1][1] - m3[1][0] * m3[0][1];
	m3_deter = m3[2][0] * cofac_2_0 + m3[2][1] * cofac_2_1 + m3[2][2] * cofac_2_2;

	return m3_deter;
}


double   get_m4_deter(t_matrix4 org_mat)
{
    int i;
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
		m4_deter += get_m3_deter(org_mat, 3, i) * sign * org_mat.m4[3][i];
		i++;
	}
	return m4_deter;
}

t_matrix4 invert_m4(t_matrix4 srcm4)
{
	t_matrix4 inverted_m4;

	return inverted_m4;
}
/*  

  4     2     2
(0,0) (0,1) (0,2)
  4     2     2
(1,0) (1,1) (1,2)
  4     2     2
(2,0) (2,1) (2,2)

cofac(m3, 2, 0) = (m3[0][1] * m3[1][2] - m3[1][1] * m3[0][2]) * m3[2][0]
cofac(m3, 2, 1) = (m3[0][0] * m3[1][2] - m3[1][0] * m3[0][2]) * -1 * m3[2][1]
cofac(m3, 2, 2) = m3[0][0] * m3[1][1] - m3[1][0] * m3[0][1] * m3[2][2]

cofac(m4, 3, 0) = -1 * (cofac(m3, 2, 0) * val(2, 0) + cofac(m3, 2, 1) * val(2, 1) + cofac(m3, 2, 2) * val(2, 2))
cofac(m4, 3, 1) = cofac(m3, 2, 0) * val(2, 0) + cofac(m3, 2, 1) * val(2, 1) + cofac(m3, 2, 2) * val(2, 2)
cofac(m4, 3, 2) = -1 * (cofac(m3, 2, 0) * val(2, 0) + cofac(m3, 2, 1) * val(2, 1) + cofac(m3, 2, 2) * val(2, 2))
cofac(m4, 3, 3) = cofac(m3, 2, 0) * val(2, 0) + cofac(m3, 2, 1) * val(2, 1) + cofac(m3, 2, 2) * val(2, 2)

det(m4) = cofac(m4, 3, 0) * val(3, 0) + cofac(m4, 3, 1) * val(3, 1) + cofac(m4, 3, 2) * val(3, 2) + cofac(m4, 3, 3) * val(3, 3)

*/

/* 
row = 0, col = 2

  1     4     2     2
(0,0) (0,1) (0,2) (0,3)
  1     4     2     2
(1,0) (1,1) (1,2) (1,3)
  1     4     2     2
(2,0) (2,1) (2,2) (2,3)
  1     4     2     2
(3,0) (3,1) (3,2) (3,3)

*/