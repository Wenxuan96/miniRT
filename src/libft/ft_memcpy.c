/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyvan-de <lyvan-de@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 09:52:47 by lyvan-de          #+#    #+#             */
/*   Updated: 2024/10/19 15:53:59 by lyvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	i = 0;
	d = dest;
	s = src;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

//#include    <stdio.h>
//#include	<string.h>

//int	main(void)
//{
//	char	src[] = "this is the source";
//	char	dest[2];
//	size_t	n;

//	n = sizeof dest;
//	printf("the src string is: %s \n", src);
//	printf("the dest string is: %s \n", dest);
//	printf("n is %zu\n", n);
//	ft_memcpy(dest, src, n);
//	printf("the dest string is now:%s", dest);
//	return (0);
//}