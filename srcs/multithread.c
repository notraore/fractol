/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: notraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 14:37:22 by notraore          #+#    #+#             */
/*   Updated: 2017/09/05 18:36:22 by notraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../toolbox.h"

void	ft_pthread(t_var *data, void *(*f)(void *param))
{
	t_var		tab[8];
	pthread_t	t[8];
	int			i;

	i = 0;
	while (i < 8)
	{
		ft_memcpy((void*)&tab[i], (void*)data, sizeof(t_var));
		tab[i].start = 100 * i;
		tab[i].end = 100 * (i + 1);
		i++;
	}
	i = 0;
	while (++i <= 8)
		pthread_create(&t[i - 1], NULL, f, &tab[i - 1]);
	while (i--)
		pthread_join(t[i], NULL);
	mlx_put_image_to_window(data->tl->mlx, data->tl->win, data->tl->img, 0, 0);
	if (data->hide == 0)
		display_info(data, data->argv);
}
