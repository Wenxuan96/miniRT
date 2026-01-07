/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyvan-de <lyvan-de@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:08:28 by lyvan-de          #+#    #+#             */
/*   Updated: 2024/10/08 16:45:33 by lyvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

//#include    <ctype.h>
//#include    <stdio.h>
//int main(void)
//{
//    char    c = ' ';
//    printf("ft_isalpha returns: %d\n", ft_isalpha(c));
//    printf("isalpha returns:%d\n", isalpha(c));
//    return(0);
//}
