/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyvan-de <lyvan-de@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 09:19:07 by lyvan-de          #+#    #+#             */
/*   Updated: 2024/10/17 17:08:43 by lyvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		lenght;
	char	*result;

	lenght = ft_strlen(s);
	result = malloc(lenght + 1 * sizeof(char));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}

//char	function(unsigned int i, char c)
//{
//	return (c + i);
//}

//#include <stdio.h>

//int	main(void)
//{
//	char	str[] = "abcdefg";

//	printf("%s", ft_strmapi(str, function));
//	return (0);
//}