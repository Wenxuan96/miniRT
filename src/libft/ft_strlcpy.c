/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyvan-de <lyvan-de@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:58:12 by lyvan-de          #+#    #+#             */
/*   Updated: 2024/10/10 17:47:15 by lyvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = 0;
	while (src[src_len])
		src_len ++;
	if (size > 0)
	{
		while (src[i] && i < size -1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_len);
}

//#include <bsd/string.h>
//#include <stdio.h>

//int	main(void)
//{
//	char		str1[] = "AAAAAA";
//	const char	str2[] = "ABCDEFGHIJK";
//	size_t		n = sizeof str1;

//	printf("dest: %s\n", str1);
//	printf("source: %s\n", str2);
//	printf("outcome ft_strlcpy %zu\n", ft_strlcpy(str1, str2, n));
//	printf("outcome strlcpy %zu\n", strlcpy(str1, str2, n));
//	printf("dest: %s\n", str1);
//	printf("source: %s\n", str2);
//	return(0);
//}