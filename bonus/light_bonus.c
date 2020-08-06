/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 15:05:42 by nclabaux          #+#    #+#             */
/*   Updated: 2020/08/06 15:31:52 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt_bonus.h"

t_color	ft_get_light(t_intersec i, t_scene sc)
{
	t_light		*light;
	t_ray		ls;
	t_intersec	s;
	t_color		res;
	double		lambert;

	res = (t_color){0, 0, 0};
	if (i.dist == -1)
		return (ft_sky(sc));
	res = ft_multiply_colors(i.color, ft_weight_color(sc.al.color, sc.al.i));
	light = sc.light_list;
	while (light)
	{
		ls.p = i.p;
		ls.v = ft_unit_v(ft_2p_to_v(i.p, light->p));
		s = ft_shot_ray(ls, sc);
		lambert = ft_dot(ls.v, i.normal);
		if (lambert > 0 && (s.dist == -1 || (s.p.x == ls.p.x && s.p.y == ls.p.y
			&& s.p.z == ls.p.z)
			|| s.dist + 0.000001 > ft_2p_dist(light->p, i.p)))
			res = ft_add_colors(res, ft_get_light2(light, i, lambert));
		light = light->next;
	}
	res = ft_filter_colors(res, sc.filter);
	return (res);
}

t_color	ft_get_light2(t_light *light, t_intersec i, double lambert)
{
	t_color	c;

	c = (t_color){0, 0, 0};
	c = ft_weight_color(light->color, light->brightness);
	c = ft_multiply_colors(c, i.color);
	c = ft_weight_color(c, lambert);
	return (c);
}

t_color	ft_sky(t_scene sc)
{
	t_color	res;

	if (fmod(random(), pow(10, 4 * (1 - sc.sky) + 2)) < 1)
		res = (t_color) {255, 255, 255};
	else
		res = (t_color) {0, 0, 0};
	res = ft_filter_colors(res, sc.filter);
	return (res);
}
