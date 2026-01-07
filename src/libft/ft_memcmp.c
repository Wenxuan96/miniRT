/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyvan-de <lyvan-de@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:14:59 by lyvan-de          #+#    #+#             */
/*   Updated: 2024/10/19 14:42:08 by lyvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*str1;
	const unsigned char	*str2;
	size_t				i;

	str1 = s1;
	str2 = s2;
	i = 0;
	if (n == 0)
		return (0);
	while (str1[i] == str2[i] && i < n -1)
		i++;
	return (str1[i] - str2[i]);
}

//#include <stdio.h>
//#include <string.h>
//int	main(void)
//{
//	const char	str1[] = "ABCDGF";
//	const char	str2[] = "ABCDEF";
//	size_t		n = 0;

//	printf("the difference is %d\n", ft_memcmp(str1, str2, n));
//	printf("the difference is %d\n", memcmp(str1, str2, n));
//	return(0);
//}