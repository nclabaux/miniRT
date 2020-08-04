/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distances_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 18:19:39 by nclabaux          #+#    #+#             */
/*   Updated: 2020/08/04 13:58:38 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt_bonus.h"

double	ft_2p_dist(t_td a, t_td b)
{
	return (hypot(hypot(a.x - b.x, a.y - b.y), a.z - b.z));
}

double	ft_p_line_dist(t_td p, t_td l_p, t_td l_v)
{
	return (ft_norm(ft_cross(ft_2p_to_v(p, l_p), l_v)) / ft_norm(l_v));
}
