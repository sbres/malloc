/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbres <sbres@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/17 11:31:51 by sbres             #+#    #+#             */
/*   Updated: 2014/04/20 19:26:19 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include <stdlib.h>

/*
** Au debut de malloc on va pre_alouer les tables
** Apres on va rajouter la taille du header pour definir une categorie
*/

void	*malloc(size_t size)
{
	static int		is_init = 0;
	void			*memory_zone;

	if (size <= 0)
		return (NULL);
	if (is_init == 0)
	{
		init_pages();
		is_init = 1;
	}
	if (size <= TINY_MAX)
	{
		memory_zone = ft_tiny_malloc(size);
	}
	else if (size <= MEDIUM_MAX)
	{
		memory_zone = ft_medium_malloc(size);
	}
	else
	{
		memory_zone = ft_big_malloc(size);
	}
	return (memory_zone);
}
