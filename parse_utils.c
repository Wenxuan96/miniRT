/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyvan-de <lyvan-de@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 18:22:47 by lyvan-de          #+#    #+#             */
/*   Updated: 2025/11/12 19:20:15 by lyvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/parsing.h"

double	str_to_double(char *str)
{
	int		i;
	double	sign;
	double	result;
	double	fraction;
	double	devisor;

	i = 0;
	sign = 1;
	result = 0;
	fraction = 0;
	devisor = 1;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	if (str[i] == '+')
		i++;
	while(ft_isdigit(str[i]) && str[i])
	{
		result = (result * 10) + str[i] - '0';
		i++;
	}
	if (str[i] == '.')
		i++;
	while(ft_isdigit(str[i]) && str[i])
	{
		fraction = fraction * 10 + str[i] - '0';
		devisor *= 10;
		i++;
	}
	return (sign * result+(fraction/devisor));
}
