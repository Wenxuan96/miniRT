/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyvan-de <lyvan-de@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 10:44:54 by lyvan-de          #+#    #+#             */
/*   Updated: 2024/10/10 11:04:55 by lyvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if ((c >= 'a' && c <= 'z'))
		c -= 32;
	return (c);
}

//#include    <ctype.h>
//#include    <stdio.h>
//int main(void)
//{
//    char    c = 'z';
//    printf("ft_isalpha returns: %c\n", ft_toupper(c));
//    printf("isalpha returns:%c\n", toupper(c));
//    return(0);
//}