/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyvan-de <lyvan-de@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:50:54 by lyvan-de          #+#    #+#             */
/*   Updated: 2024/10/08 16:53:09 by lyvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

//#include    <ctype.h>
//#include    <stdio.h>
//int main(void)
//{
//    //char    c = 'U';
//    printf("ft_isasciireturns: %d\n", ft_isascii(398));
//    printf("isdigit returns:%d\n", isascii(398));
//    return(0);
//}