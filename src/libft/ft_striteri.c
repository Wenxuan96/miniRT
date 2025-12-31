/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyvan-de <lyvan-de@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 17:24:18 by lyvan-de          #+#    #+#             */
/*   Updated: 2024/10/16 18:25:48 by lyvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f) (unsigned int, char*))
{
	int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i ++;
	}
}

//void	to_lower_if_even(unsigned int i, char *c)
//{
//	if ( i % 2 == 0)
//		*c = (char) ft_tolower((int) *c);
//}

//#include <stdio.h>

//int	main(void)
//{
//	char	str[] = "ABCDEFG";

//	ft_striteri(str, to_lower_if_even);
//	printf("%s", str);
//	return (0);
//}