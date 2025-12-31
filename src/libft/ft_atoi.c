/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyvan-de <lyvan-de@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 12:27:55 by lyvan-de          #+#    #+#             */
/*   Updated: 2024/10/16 12:49:03 by lyvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	result;
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	result = 0;
	while ((nptr[i] >= '\t' && nptr[i] <= '\r') || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}

//#include <stdlib.h>
//#include <stdio.h>

//int	main(void)
//{
//	char	str1[] = "9223372036854775807";
//	char	str2[] = "---1235";
//	char	str3[] = "123";
//	char	str4[] = "+342 hallo3";
//	char	str5[] = "hoi123";
//	char	str6[] = "-342";

//	printf("str 1 %d | %d\n", atoi(str1), ft_atoi(str1));
//	printf("str 2 %d | %d\n", atoi(str2), ft_atoi(str2));
//	printf("str 3 %d | %d\n", atoi(str3), ft_atoi(str3));
//	printf("str 4 %d | %d\n", atoi(str4), ft_atoi(str4));
//	printf("str 5 %d | %d\n", atoi(str5), ft_atoi(str5));
//	printf("str 6 %d | %d\n", atoi(str6), ft_atoi(str6));
//	return(0);
//}