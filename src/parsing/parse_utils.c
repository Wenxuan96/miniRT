/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyvan-de <lyvan-de@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 18:22:47 by lyvan-de          #+#    #+#             */
/*   Updated: 2025/12/08 17:35:01 by lyvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parsing.h"

void	free_array(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

int	check_double(char *str)
{
	int	i;
	int	dot;
	int	has_digit;

	dot = 0;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while ((ft_isdigit(str[i]) || str[i] == '.'))
	{
		if (str[i] == '.')
			dot += 1;
		else
			has_digit = 1;
		if (dot == 2)
			break ;
		i ++;
	}
	if (!has_digit || str[i] != '\0')
		return (0);
	return (1);
}

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
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		result = (result * 10) + *str++ - '0';
	if (*str == '.')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		fraction = fraction * 10 + *str++ - '0';
		devisor *= 10;
	}
	return (sign * result + (fraction / devisor));
}

int	check_rgb(char *str)
{
	char	**split;
	int		i;
	int		val;

	i = 0;
	split = ft_split(str, ',');
	if (split == NULL)
	{
		printf("Error\nMalloc error\n");
		return (0);
	}
	while (i < 3)
	{
		val = ft_atoi(split[i]);
		if (val < 0 || val > 255)
		{
			free_array(split);
			return (0);
		}
		i++;
	}
	if (split[i] != NULL)
		return (free_array(split), 0);
	free_array(split);
	return (1);
}

int	str_to_rgb(char *str, t_rgb *rgb)
{
	char	**split;

	split = ft_split(str, ',');
	if (split == NULL)
	{
		printf("Error\nMalloc error\n");
		return (0);
	}
	rgb->r = (unsigned char) ft_atoi(split[0]);
	rgb->g = (unsigned char) ft_atoi(split[1]);
	rgb->b = (unsigned char) ft_atoi(split[2]);
	free_array(split);
	return (1);
}
