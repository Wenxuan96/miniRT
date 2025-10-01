/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyvan-de <lyvan-de@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:26:13 by lyvan-de          #+#    #+#             */
/*   Updated: 2024/10/17 16:45:15 by lyvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	int		i;
	int		j;
	char	*str;

	len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(len + 1 * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i] = s2[j];
		i ++;
		j ++;
	}
	str[i] = '\0';
	return (str);
}

//#include <stdio.h>

//int	main(void)
//{
//	char	str1[] = "abcdef";
//	char	str2[] = "ghijkl";
//	char	*str3;

//	printf("str1: %s\n", str1);
//	printf("str2: %s\n", str2);
//	str3 = ft_strjoin(str1, str2);
//	printf("str3: %s\n", str3);
//	return(0);
//}