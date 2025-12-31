/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyvan-de <lyvan-de@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:53:48 by lyvan-de          #+#    #+#             */
/*   Updated: 2024/10/16 11:10:19 by lyvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int	begin;
	int	end;

	begin = 0;
	end = ft_strlen(s1);
	while (ft_strchr(set, s1[begin]))
		begin ++;
	while (ft_strchr(set, s1[end]))
		end --;
	return (ft_substr(s1, begin, (end - begin) + 1));
}

//#include <stdio.h>

//int	main(void)
//{
//	char	str1[] = "-*-**-*-*-abc-*def*-*-*-*-";
//	char	str3[] = "*-";
//	char	*str2;

//	printf("str1: %s\n", str1);
//	str2 = ft_strtrim(str1,str3);
//	printf("str2: %s\n", str2);
//	return(0);
//}