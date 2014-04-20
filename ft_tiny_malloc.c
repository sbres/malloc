/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tiny_malloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbres <sbres@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/18 18:55:49 by sbres             #+#    #+#             */
/*   Updated: 2014/04/20 19:35:22 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include <stdlib.h>

void	*ft_tiny_malloc(size_t size)
{
	t_data	*tmp;
	void	*new_area;

	tmp = pages.tiny;
	while ((tmp->is_free == 0 || tmp->size < size) && tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	if (tmp->size < size || tmp->is_free == 0)
	{
		return (NULL);
	}
	if (tmp->size == size)
	{
		tmp->is_free = 0;
		return (tmp->ptr);
	}
	new_area = tmp->ptr;
	new_area += size + 1;
	new_block(tmp->size - size, new_area, 1, &pages.tiny);
	tmp->is_free = 0;
	tmp->size = size + 1;
	return (tmp->ptr);
}
