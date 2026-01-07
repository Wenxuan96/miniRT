/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyvan-de <lyvan-de@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 17:52:30 by lyvan-de          #+#    #+#             */
/*   Updated: 2024/10/17 16:30:17 by lyvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[0] == '\0')
		return ((char *)&big[i]);
	if (len == 0)
		return (NULL);
	while (big[i] && (i) <= len -1)
	{
		j = 0;
		while (big[i + j] == little[j] && little[j] && (i + j) <= len -1)
		{
			j++;
			if (little[j] == '\0')
				return ((char *)&big[i]);
		}
		i ++;
	}
	return (NULL);
}

//#include <bsd/string.h>
//#include <stdio.h>

//int	main(void)
//{
//	char	big[] = "abcdefg";
//	char	little[] = "defg";

//	printf("%p\n", ft_strnstr(big, little, 0));
//	printf("%p\n", strnstr(big, little, 0));
//	//printf("%c\n", *ft_strnstr);
//	return(0);
//}