/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyvan-de <lyvan-de@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 11:02:51 by lyvan-de          #+#    #+#             */
/*   Updated: 2024/10/10 11:07:07 by lyvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

//#include    <ctype.h>
//#include    <stdio.h>
//int main(void)
//{
//    char    c = '9';
//    printf("ft_tolower returns: %c\n", ft_tolower(c));
//    printf("tolower returns:%c\n", tolower(c));
//    return(0);
//}