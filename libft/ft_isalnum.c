/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyvan-de <lyvan-de@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:33:07 by lyvan-de          #+#    #+#             */
/*   Updated: 2024/10/08 16:46:32 by lyvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}

//#include    <ctype.h>
//#include    <stdio.h>
//int main(void)
//{
//    char    c = 'H';
//    printf("ft_isalnum returns: %d\n", ft_isalnum(c));
//    printf("isalnum returns:%d\n", isalnum(c));
//    return(0);
//}