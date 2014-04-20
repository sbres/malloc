/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realoc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbres <sbres@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/20 01:07:35 by sbres             #+#    #+#             */
/*   Updated: 2014/04/20 04:15:54 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include <stdlib.h>
/*
** Decoupe le block de memoire seulmetn si le block est plus petit
** Sinon un fait un realoc bien vieux
*/

static t_data		*memory_size(void *ptr)
{
	t_data		*tmp;

	tmp = pages.tiny;
	while (tmp != NULL)
	{
		if (tmp->ptr == ptr)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = pages.medium;
	while (tmp != NULL)
	{
		if (tmp->ptr == ptr)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = pages.big;
	while (tmp != NULL)
	{
		if (tmp->ptr == ptr)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

static void			*ft_brutus(void	*ptr, int size, int new_size)
{
	void	*tmp;
	void	*save;
	void	*save2;
	int		counter;

	counter = 0;
	save = ptr;
	tmp = malloc(new_size);
	save2 = tmp;
	while (size > counter)
	{
		tmp = ptr;
		tmp++;
		ptr++;
		counter++;
	}
	free(save);
	return (save2);
}

void				*realloc(void *ptr, size_t size)
{
	t_data	*tmp;

	tmp = memory_size(ptr);
	if (tmp == NULL)
		return (NULL);
	if (tmp->size >= size)
	{
		if (tmp->size <= TINY_MAX)
			new_block(tmp->size - size, ptr + size, 1, &pages.tiny);
		else if (tmp->size <= MEDIUM_MAX)
			new_block(tmp->size - size, ptr + size, 1, &pages.medium);
		else
			return (ft_brutus(ptr, tmp->size, size));
		tmp->size = size;
		return (tmp->ptr);
	}
	else
		return (ft_brutus(ptr, tmp->size, size));
}