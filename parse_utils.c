/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyvan-de <lyvan-de@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 18:22:47 by lyvan-de          #+#    #+#             */
/*   Updated: 2025/11/12 20:22:58 by lyvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/parsing.h"

double	str_to_double(char *str)
{
	double	sign;
	double	result;
	double	fraction;
	double	devisor;

	sign = 1;
	result = 0;
	fraction = 0;
	devisor = 1;
	if (*str == '-' || *str == '+')
		if(*str == '-')
			sign *= -1;
	str++;
	while(*str >= '0' && *str <= '9')
		result = (result * 10) + *str++ - '0';
	if (*str == '.')
		str++;
	while(*str >= '0' && *str <= '9')
	{
		fraction = fraction * 10 + *str++ - '0';
		devisor *= 10;
	}
	return (sign * result+(fraction/devisor));
}

t_rgb	str_to_rgb(char *str)
{
	char	**split;
	t_rgb	ret;

	split = ft_split(str, ',');
	ret.r = (unsigned char) ft_atoi(split[0]);
	ret.g = (unsigned char) ft_atoi(split[1]);
	ret.b = (unsigned char) ft_atoi(split[2]);
	free(split);
	return (ret);
}
