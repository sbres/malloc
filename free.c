/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbres <sbres@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/19 10:40:33 by sbres             #+#    #+#             */
/*   Updated: 2014/04/20 19:29:26 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include <stdlib.h>
#include <sys/mman.h>

void	ft_free_2(void *ptr)
{
	t_data		*tmp;

	tmp = pages.big;
	while (tmp != NULL)
	{
		if (tmp->ptr == ptr)
		{
			tmp->is_free = 1;
			munmap(ptr, tmp->size);
			return ;
		}
		tmp = tmp->next;
	}
}

void	free(void *ptr)
{
	t_data		*tmp;

	tmp = pages.tiny;
	while (tmp != NULL)
	{
		if (tmp->ptr == ptr)
		{
			tmp->is_free = 1;
			return ;
		}
		tmp = tmp->next;
	}
	tmp = pages.medium;
	while (tmp != NULL)
	{
		if (tmp->ptr == ptr)
		{
			tmp->is_free = 1;
			return ;
		}
		tmp = tmp->next;
	}
	ft_free_2(ptr);
}
