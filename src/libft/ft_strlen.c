/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxi <wxi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:20:31 by lyvan-de          #+#    #+#             */
/*   Updated: 2026/01/25 17:20:55 by wxi              ###   ########.fr       */
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

//    printf("using ft_strlen the length is: %lu\n", ft_strlen(str));
//    printf("using strlen the length is:%lu\n", strlen(str));
//    return(0);
//}