/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyvan-de <lyvan-de@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:26:08 by lyvan-de          #+#    #+#             */
/*   Updated: 2024/10/22 11:26:44 by lyvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	get_length(int n)
{
	int	length;

	length = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		length ++;
	while (n != 0)
	{
		n /= 10;
		length ++;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		length;
	long	long_n;

	long_n = (long)n;
	length = get_length(long_n);
	str = malloc (length + 1 * sizeof(char));
	if (str == NULL)
		return (NULL);
	if (long_n == 0)
		str[0] = '0';
	if (long_n < 0)
	{
		str[0] = '-';
		long_n = -long_n;
	}
	str[length] = '\0';
	while (long_n > 0)
	{
		str[--length] = (long_n % 10) + '0';
		long_n /= 10;
	}
	return (str);
}

//#include <stdio.h>

//int	main(void)
//{
//	char	*str;
//	int		n;

//	n = 0;
//	printf("%d \n", get_length(n));
//	str = ft_itoa(n);
//	printf("%s\n", str);
//	return (0);
//}