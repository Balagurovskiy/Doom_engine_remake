/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obalagur <obalagur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 12:09:11 by obalagur          #+#    #+#             */
/*   Updated: 2019/06/02 12:46:19 by obalagur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defines.h"
#include "doom.h"
#include "libft.h"

void	free_level(t_level *level)
{
	int	i;

	if (!level || level->sectors_size == -1)
	{
		ft_putstr("EXCEPTION > input > invalid argument\n");
		return ;
	}
	i = 0;
	free_texture_set(&(level->texture));
	if (level->sector)
	{
		while (i < level->sectors_size)
		{
			ft_memdel((void **)&(level->sector[i]).vertex);
			ft_memdel((void **)&(level->sector[i]).neighbors);
			i++;
		}
		ft_memdel((void **)&(level->sector));
	}
	i = 3;
	while (--i >= 0)
		ft_memdel((void **)&(level->next_level[i]));
}

void	safe_sdlfree(SDL_Surface *s)
{
	if (s)
		SDL_FreeSurface(s);
}

void	free_texture_set(t_texture_set *t)
{
	int	i;

	if (t)
	{
		safe_sdlfree(t->ceiltexture);
		safe_sdlfree(t->floortexture);
		safe_sdlfree(t->uppertextures);
		safe_sdlfree(t->lowertextures);
		safe_sdlfree(t->sky);
		safe_sdlfree(t->door);
		i = 5;
		while (--i >= 0)
			safe_sdlfree(t->dec[i]);
		i = 7;
		while (--i >= 0)
			safe_sdlfree(t->key[i]);
	}
}
