/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyvan-de <lyvan-de@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 10:24:10 by lyvan-de          #+#    #+#             */
/*   Updated: 2024/10/19 18:07:14 by lyvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	length;
	char	*sub_str;

	i = 0;
	length = ft_strlen(s);
	if (!s[i] || start > length || length - start < 0)
		len = 0;
	else if (start + len > length)
		len = length - start;
	sub_str = malloc(len * sizeof(char) + 1);
	if (sub_str == NULL)
		return (NULL);
	while (i < len && s[start + i])
	{
		sub_str[i] = s[start + i];
		i ++;
	}
	sub_str[i] = '\0';
	return (sub_str);
}

//#include <stdio.h>

//int	main(void)
//{
//	char	str1[] = "abcdefg";
//	char	*str2;

//	printf("str1: %s\n", str1);
//	str2 = ft_substr(str1, 6, 3);
//	printf("str2: %s\n", str2);
//	return(0);
//}