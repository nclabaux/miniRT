/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclabaux <nclabaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 17:00:33 by nclabaux          #+#    #+#             */
/*   Updated: 2020/08/05 15:58:33 by nclabaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt_bonus.h"

int			main(int argc, char **argv)
{
	t_scene		scene;

	ft_init_scene(&scene);
	ft_printf("\033[01;37m\nHello and welcome in this mini Ray Tracer!\n");
	ft_arguments_check(&scene, argc, argv);
	ft_printf("\033[01;34m\nReading file...\n");
	ft_read_file(argv[1], &scene);
	scene.mlx = mlx_init();
	ft_scene_verif(&scene, argc);
	ft_printf("\033[01;32mFile read and compliant!\n");
	ft_printf("\033[22;37m\nRendering images... Please wait\n");
	if (scene.cam_nbr > 1)
		ft_printf("(images are rendered from last to first camera)\n");
	ft_gen_img(&scene);
	ft_printf("\n");
	if (argc == 2)
		ft_put_images_to_window(&scene);
	ft_save_images_to_bmp(&scene, argv[1]);
	ft_kill(&scene);
	return (0);
}

void		ft_arguments_check(t_scene *as, int argc, char **argv)
{
	if (argc < 2)
		ft_errors(as, 1000, "");
	if (argc > 3)
		ft_errors(as, 1025, "");
	if (argc == 3 && ft_strncmp(argv[2], "-save", 5)
		&& ft_strncmp(argv[2], "--save", 6))
		ft_errors(as, 1001, argv[2]);
	if (ft_check_extension(argv[1], "rt"))
		ft_errors(as, 1026, "");
}

void		ft_init_scene(t_scene *ascene)
{
	ascene->res.x = 0;
	ascene->res.y = 0;
	ascene->al.intensity = 0;
	ascene->al.color.r = 0;
	ascene->al.color.g = 0;
	ascene->al.color.b = 0;
	ascene->cam_list = NULL;
	ascene->cam_nbr = 0;
	ascene->light_list = NULL;
	ascene->object_list = NULL;
	ascene->img_list = NULL;
	ascene->mlx = NULL;
	ascene->filter.type = 0;
	ascene->filter.color = (t_color) {255, 255, 255};
}

void		ft_put_images_to_window(t_scene *as)
{
	void	*p[3];
	void	*win_ptr;
	int		current;
	char	*name;

	ft_printf("\033[22;37m\nYou can use ");
	if (as->cam_nbr > 1)
	{
		ft_printf("the\033[01;36m right/left arrow key ");
		ft_printf("\033[22;37mto display the next/previous image and ");
	}
	ft_printf("\033[01;31mesc \033[22;37mto quit.\n");
	name = ft_strdup("miniRT");
	win_ptr = mlx_new_window(as->mlx, as->res.x, as->res.y, name);
	free(name);
	current = 1;
	mlx_put_image_to_window(as->mlx, win_ptr, as->img_list->ip, 0, 0);
	p[0] = win_ptr;
	p[1] = as;
	p[2] = &current;
	mlx_key_hook(win_ptr, ft_key, p);
	mlx_hook(win_ptr, DestroyNotify, StructureNotifyMask, ft_kill, as);
	mlx_hook(win_ptr, FocusIn, FocusChangeMask, ft_disp_curr_img, p);
	mlx_loop(as->mlx);
}

void		ft_save_images_to_bmp(t_scene *as, char *rt_file)
{
	t_img_link	*il;

	il = as->img_list;
	while (il)
	{
		ft_save_img(il, as, rt_file);
		il = il->next;
	}
	ft_printf("\n\033[22;32mThe image");
	if (as->cam_nbr == 1)
		ft_printf(" has ");
	else
		ft_printf("s have ");
	ft_printf("succesfully been saved in ");
	ft_printf("\033[01;36msaves/ \033[22;32mdirectory\n\033[22;37m");
}
