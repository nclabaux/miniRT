/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data1_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 14:33:07 by nclabaux          #+#    #+#             */
/*   Updated: 2020/08/04 18:40:35 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt_bonus.h"

void	ft_set_cu(t_scene *as, t_cube cu)
{
	t_square	sq;

	sq.p = cu.p;
	sq.v = ft_unit_v(cu.v);
	sq.size = cu.size;
	sq.color = cu.color;
	ft_set_sq_data(&sq, as);
	sq.v = (t_td) {cu.v.y, -cu.v.x, 0};
	if (cu.v.x == 0 && cu.v.y == 0)
		sq.v = (t_td) {1,0,0};
	sq.v = ft_unit_v(sq.v);
	ft_set_sq_data(&sq, as);
	sq.v = ft_cross(cu.v, sq.v);
	if (!sq.v.x && !sq.v.y && sq.v.z == -1 && !cu.v.x)
		sq.v.z = 1;
	ft_set_sq_data(&sq, as);
}
