/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyvan-de <lyvan-de@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:44:03 by lyvan-de          #+#    #+#             */
/*   Updated: 2024/10/19 15:48:45 by lyvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	d = (char *) dest;
	s = (char *) src;
	if (!dest && !src)
		return (NULL);
	if (s < d)
	{
		while (n > 0)
		{
			d[n - 1] = s[n - 1];
			n--;
		}
	}
	else
		dest = ft_memcpy(dest, src, n);
	return (dest);
}

//#include    <stdio.h>
//#include	<string.h>

//int	main(void)
//{
//	char	src[] = "this is the source";
//	char	dest[10];
//	size_t	n;

//	n = sizeof dest;
//	printf("the src string is: %s \n", src);
//	printf("the dest string is: %s \n", dest);
//	printf("n is %zu\n", n);
//	ft_memmove(dest, src, n);
//	printf("the dest string is now:%s", dest);
//	return (0);
//}
