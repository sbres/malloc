/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_header.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbres <sbres@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/18 19:25:16 by sbres             #+#    #+#             */
/*   Updated: 2014/04/20 19:32:56 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include <stdlib.h>
#include <sys/mman.h>

void		new_block(int size, void *ptr, int state, t_data **list)
{
	t_data		*new_blockk;
	t_data		*tmp;

	tmp = *list;
	new_blockk = (t_data *)mmap(NULL, sizeof(t_data *), PROT_READ | PROT_WRITE,
						MAP_PRIVATE | MAP_ANON, -1, 0);
	new_blockk->size = size;
	new_blockk->ptr = ptr;
	new_blockk->is_free = state;
	new_blockk->next = NULL;
	if (tmp == NULL)
	{
		*list = new_blockk;
	}
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_blockk;
	}
}
