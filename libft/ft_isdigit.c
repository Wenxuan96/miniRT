/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyvan-de <lyvan-de@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:30:17 by lyvan-de          #+#    #+#             */
/*   Updated: 2024/10/08 16:45:48 by lyvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

//#include    <ctype.h>
//#include    <stdio.h>
//int main(void)
//{
//    char    c = '5';
//    printf("ft_isdigit returns: %d\n", ft_isdigit(c));
//    printf("isdigit returns:%d\n", isdigit(c));
//    return(0);
//}