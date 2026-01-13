/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a12708 <a12708@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:16:19 by lyvan-de          #+#    #+#             */
/*   Updated: 2026/01/11 21:30:01 by a12708           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*str;

	i = ft_strlen(s);
	str = (char *)s;
	if ((char)c == '\0')
		return (&str[i]);
	if (i == 0)
		return (NULL);
	while (i >= 0)
	{
		if (str[i] == (char) c)
			return (&str[i]);
		i--;
		if (i == 0 && str[i] != (char) c)
			return (NULL);
	}
	return (NULL);
}

//#include <stdio.h>
//#include <string.h>
//int	main(void)
//{
//	const char	str[] = "hteste";
//	int			c;

//	c = 'h';
//	printf ("ft_strrchr: %p\n", ft_strrchr(str,c));
//	printf ("strrchr: %p\n", strrchr(str,c));
//	return (0);
//}