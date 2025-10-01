/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyvan-de <lyvan-de@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:39:39 by lyvan-de          #+#    #+#             */
/*   Updated: 2024/10/19 14:35:01 by lyvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s1[i] == s2[i] && i < n -1)
		i++;
	return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}

//#include <stdio.h>
//#include <string.h>
//int	main(void)
//{
//	const char	str1[] = "abcdef";
//	const char	str2[] = "abc\375xx";
//	size_t		n = 5;

//	printf("the difference is %d\n", ft_strncmp(str1, str2, n));
//	printf("the difference is %d\n", strncmp(str1, str2, n));
//	return(0);
//}