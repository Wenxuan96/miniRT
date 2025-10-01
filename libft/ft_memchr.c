/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyvan-de <lyvan-de@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:27:46 by lyvan-de          #+#    #+#             */
/*   Updated: 2024/10/19 14:49:12 by lyvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*str;
	size_t		i;

	str = s;
	i = 0;
	while (i < n)
	{
		if (str[i] == (char)c)
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}

//#include <stdio.h>
//#include <string.h>
//int	main(void)
//{
//	const char	str[] = "hallo";
//	int			c;
//	size_t		n;

//	c = 'l';
//	n = 4;
//	printf ("%p\n", ft_memchr(str,c,n));
//	printf ("%p\n", memchr(str,c,n));
//	return (0);
//}