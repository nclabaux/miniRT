/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_max.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 22:21:50 by nclabaux          #+#    #+#             */
/*   Updated: 2020/01/30 22:22:13 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_min(int x, int y)
{
	if (x < y)
		return (x);
	return (y);
}

int		ft_max(int x, int y)
{
	if (x > y)
		return (x);
	return (y);
}
