/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyvan-de <lyvan-de@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:40:03 by lyvan-de          #+#    #+#             */
/*   Updated: 2024/10/08 17:48:56 by lyvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = s;
	while (i < n)
	{
		ptr[i] = '\0';
		i++;
	}
}

//#include    <stdio.h>
//int	main(void)
//{
//	char	buffer[] = "this is the string";
//	size_t	n;

//	n = sizeof buffer;

//	printf("the og string is: %s \n", buffer);
//	ft_bzero(buffer, n);
//	printf("the string is now:%s", buffer);
//	return (0);
//}