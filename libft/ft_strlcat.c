/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyvan-de <lyvan-de@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:58:38 by lyvan-de          #+#    #+#             */
/*   Updated: 2024/10/19 15:57:02 by lyvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;
	size_t	j;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size < dst_len)
		return (size + src_len);
	if (size == 0)
		return (src_len);
	i = dst_len;
	j = 0;
	while (src[j] && i < size -1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dst_len + src_len);
}

//#include <bsd/string.h>
//#include <stdio.h>

//int	main(void)
//{
//	char    source[] = "123";
//	char    dest1[30];
//	char    dest2[30];
//	size_t	n = 0;

//	printf("source:	%s\n", source);
//	printf("dest1:	%s\n", dest1);
//	printf("dest2:	%s\n", dest2);
//	printf("outcome ft_strlcat:	%zu\n", ft_strlcat(dest1, source, n));
//	printf("outcome strlcat    	%zu\n", strlcat(dest2, source, n));
//	printf("dest ft_srlcat:	%s\n", dest1);
//	printf("source strlcat:	%s\n", dest2);
//	return(0);
//	return(0);
//}
