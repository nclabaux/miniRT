/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reading3_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 15:16:50 by nclabaux          #+#    #+#             */
/*   Updated: 2020/08/05 16:54:34 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt_bonus.h"

void	ft_cy_rd(char **s, t_scene *as)
{
	int			i;
	t_obj_link	*new_ol;

	if (!(new_ol = malloc(sizeof(t_obj_link))))
		ft_errors(as, 1011, "");
	if (!(new_ol->object = malloc(sizeof(t_object))))
		ft_errors(as, 1011, "");
	new_ol->type = 4;
	i = 2;
	while (ft_isspace((*s)[i]))
		i++;
	if (!(ft_isdigit((*s)[i]) || (*s)[i] == '-'))
		ft_errors(as, 1017, "");
	i += ft_read_td(as, *s + i, &(new_ol->object->cy.p));
	while (ft_isspace((*s)[i]))
		i++;
	if (!(ft_isdigit((*s)[i]) || (*s)[i] == '-'))
		ft_errors(as, 1017, "");
	i += ft_read_td(as, *s + i, &(new_ol->object->cy.v));
	while (ft_isspace((*s)[i]))
		i++;
	if (!(ft_isdigit((*s)[i])))
		ft_errors(as, 1017, "");
	new_ol->object->cy.d = ft_atod(*s + i);
	ft_cy_rd2(s, as, new_ol, i);
}

void	ft_cy_rd2(char **s, t_scene *as, t_obj_link *new_ol, int i)
{
	while (ft_isdigit((*s)[i]) || (*s)[i] == '.')
		i++;
	while (ft_isspace((*s)[i]))
		i++;
	if (!(ft_isdigit((*s)[i])))
		ft_errors(as, 1017, "");
	new_ol->object->cy.h = ft_atod(*s + i);
	while (ft_isdigit((*s)[i]) || (*s)[i] == '.')
		i++;
	while (ft_isspace((*s)[i]))
		i++;
	if (!(ft_isdigit((*s)[i])))
		ft_errors(as, 1017, "");
	ft_read_color(as, *s + i, &(new_ol->object->cy.color));
	new_ol->object->cy.v = ft_unit_v(new_ol->object->cy.v);
	ft_add_object(as, new_ol);
}

void	ft_cu_rd(char **s, t_scene *as)
{
	int	i;
	t_cube	cu;

	i = 2;
	while (ft_isspace((*s)[i]))
		i++;
	if (!(ft_isdigit((*s)[i]) || (*s)[i] == '-'))
		ft_errors(as, 1027, "");
	i += ft_read_td(as, *s + i, &(cu.p));
	while (ft_isspace((*s)[i]))
		i++;
	if (!(ft_isdigit((*s)[i]) || (*s)[i] == '-'))
		ft_errors(as, 1027, "");
	i += ft_read_td(as, *s + i, &(cu.v));
	while (ft_isspace((*s)[i]))
		i++;
	if (!(ft_isdigit((*s)[i]) || (*s)[i] == '-'))
		ft_errors(as, 1027, "");
	cu.size = ft_atod(*s + i);
	while (ft_isdigit((*s)[i]) || (*s)[i] == '.')
		i++;
	while (ft_isspace((*s)[i]))
		i++;
	if (!(ft_isdigit((*s)[i])))
		ft_errors(as, 1027, "");
	ft_read_color(as, *s + i, &(cu.color));
	ft_set_cu(as, cu);
}

void	ft_filter_rd(char **s, t_scene *as)
{
	int	i;

	i = 2;
	if (as->filter.color.r != 255 || as->filter.color.g != 255
		|| as->filter.color.b != 255 || as->filter.type)
		ft_errors(as, 1028, "");
	while (ft_isspace((*s)[i]))
		i++;
	if (ft_isdigit((*s)[i]))
		ft_read_color(as, *s + i, &(as->filter.color));
	else if ((*s)[i] == 'c')
	{
		as->filter.type = 1;
		i++;
		while (ft_isspace((*s)[i]))
			i++;
		if (!ft_isdigit((*s)[i]))
			ft_errors(as, 1029, "");
		ft_read_color(as, *s + i, &(as->filter.color));
	}
	else if ((*s)[i] == 's')
	{
		as->filter.type = 1;
		as->filter.color = (t_color) {63, 34, 4};
	}
	else if ((*s)[i] == 'g')
	{
		as->filter.type = 1;
		as->filter.color = (t_color) {0, 0, 0};
	}
	else
		ft_errors(as, 1029, "");
}
