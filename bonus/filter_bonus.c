/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 15:37:03 by nclabaux          #+#    #+#             */
/*   Updated: 2020/08/05 16:38:50 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt_bonus.h"

t_color	ft_filter_colors(t_color c, t_filter f)
{
	double	average;
	
	if (f.type == 0)
		return (ft_multiply_colors(c, f.color));
	average = c.r + c.g + c.b;
	average /= 3;
	c = (t_color) {average, average, average};
	average /= 255;
	return (ft_add_colors(c, ft_weight_color(f.color, 1 - average)));
}
