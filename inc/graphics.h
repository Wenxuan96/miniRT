/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wxi <wxi@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:00:37 by lyvan-de          #+#    #+#             */
/*   Updated: 2025/12/10 15:01:06 by wxi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H
# include "../MLX42/include/MLX42/MLX42.h"

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

int		get_rgba(unsigned char r, unsigned char g, unsigned char b, unsigned char a);
void	put_image(void *param);

#endif