/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyvan-de <lyvan-de@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:02:52 by lyvan-de          #+#    #+#             */
/*   Updated: 2024/10/19 13:50:35 by lyvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	str = (char *)s;
	i = 0;
	while (str[i])
	{
		if (str[i] == (char) c)
			return (&str[i]);
		i++;
	}
	if ((char) c == '\0')
		return (&str[i]);
	return (NULL);
}

//#include <stdio.h>
//#include <string.h>
//int	main(void)
//{
//	const char	str[] = "hallo";
//	int			c;

//	c = 1024;
//	printf ("%p\n", ft_strchr(str,c));
//	printf ("%p\n", strchr(str,c));
//	return (0);
//}