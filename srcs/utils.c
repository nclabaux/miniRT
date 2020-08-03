/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 20:56:07 by nclabaux          #+#    #+#             */
/*   Updated: 2020/08/03 19:08:17 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

char	*ft_cut_filename(char *filename)
{
	int		last_dir;
	int		last_point;
	int		i;
	int		j;
	char	*res;

	i = -1;
	last_dir = 0;
	last_point = ft_strlen(filename);
	while (filename[++i])
	{
		if (filename[i] == '/')
			last_dir = i;
		if (filename[i] == '.')
			last_point = i;
	}
	if (!(res = malloc(sizeof(char) * (last_point - last_dir))))
		return (NULL);
	i = last_dir + 1;
	j = 0;
	while (i < last_point)
		res[j++] = filename[i++];
	res[j] = 0;
	return (res);
}

int		ft_check_extension(char *filename, char *ext)
{
	int	i;
	int	last_point;

	i = 0;
	last_point = 0;
	while (filename[i])
	{
		if (filename[i] == '.')
			last_point = i;
		i++;
	}
	if (!last_point)
		return (1);
	return (ft_strncmp(filename + last_point + 1, ext, sizeof(ext)));
}
