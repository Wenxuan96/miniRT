/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyvan-de <lyvan-de@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:50:39 by lyvan-de          #+#    #+#             */
/*   Updated: 2024/10/08 17:01:45 by lyvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}

//#include    <ctype.h>
//#include    <stdio.h>
//int main(void)
//{
//    char    c = '\n';
//    printf("ft_isasciireturns: %d\n", ft_isprint(c));
//    printf("isdigit returns:%d\n", isprint(c));
//    return(0);
//}