/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyvan-de <lyvan-de@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:20:31 by lyvan-de          #+#    #+#             */
/*   Updated: 2024/10/08 12:43:52 by lyvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

//#include    <stdio.h>
//#include    <string.h>
//int main(void)
//{
//    char    str[] = "hallo";

//    printf("using ft_strlen the lenght is: %lu\n", ft_strlen(str));
//    printf("using strlen the lenght is:%lu\n", strlen(str));
//    return(0);
//}