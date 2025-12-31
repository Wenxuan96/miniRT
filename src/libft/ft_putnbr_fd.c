/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyvan-de <lyvan-de@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:10:18 by lyvan-de          #+#    #+#             */
/*   Updated: 2024/10/16 23:01:30 by lyvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	char	c;
	long	long_n;

	long_n = (long)n;
	if (long_n < 0)
	{
		write(fd, &"-", 1);
		long_n *= -1;
	}
	if (long_n >= 10)
	{
		ft_putnbr_fd((long_n / 10), fd);
	}
	c = (long_n % 10) + '0';
	write(fd, &c, 1);
}

// int	main(void)
// {
// 	ft_putnbr_fd(-2147483648, 1);
// 	return(0);
// }