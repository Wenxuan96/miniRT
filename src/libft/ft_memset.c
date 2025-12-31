/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyvan-de <lyvan-de@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:03:33 by lyvan-de          #+#    #+#             */
/*   Updated: 2024/10/10 10:39:08 by lyvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	value;
	unsigned char	*ptr;

	i = 0;
	value = c;
	ptr = s;
	while (i < n)
	{
		ptr[i] = value;
		i ++;
	}
	return (s);
}

//#include    <stdio.h>
//int	main(void)
//{
//	char	buffer[5];
//	size_t	n;

//	n = sizeof buffer;
//	ft_memset(buffer, 'B', n);

//	printf("the buffer is now: %s", buffer);

//	return (0);
//}