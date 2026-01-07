/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyvan-de <lyvan-de@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:21:32 by lyvan-de          #+#    #+#             */
/*   Updated: 2024/10/14 10:21:46 by lyvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	size_t	i;
	char	*ptr;

	len = ft_strlen(s) + 1;
	i = 0;
	ptr = malloc(len * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	while (i < len)
	{
		ptr[i] = s[i];
		i ++;
	}
	return (ptr);
}

//#include <bsd/string.h>
//#include <stdio.h>

//int	main(void)
//{
//	char	str1[] = "abcdef";
//	char	*str2;

//	printf("str1: %s\n", str1);
//	str2 = ft_strdup(str1);
//	printf("str2: %s\n", str2);
//	return(0);
//}