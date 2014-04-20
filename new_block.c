/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_block.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbres <sbres@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/19 09:51:58 by sbres             #+#    #+#             */
/*   Updated: 2014/04/19 09:52:11 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/mman.h>//mmap

void		new_block(int size, void *ptr, int state, t_data **list)
{
	t_data		*new_blockk;
	t_data		*tmp;

	tmp = *list;
	new_blockk = (t_data *)mmap(NULL, sizeof(t_data *), PROT_READ | PROT_WRITE,
						MAP_PRIVATE|MAP_ANON, -1, 0);
	new_blockk->size = size;
	new_blockk->ptr = ptr;
	new_blockk->is_free = state;
	new_blockk->next = NULL;
	if (tmp == NULL)
	{
	//	write(1, "INIT", 4);
	//	printf("%p\n", new_blockk );
		*list = new_blockk;
	//	printf("%p\n", *list );
	}
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_blockk;
	}
}
