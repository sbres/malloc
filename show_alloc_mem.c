/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbres <sbres@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/19 09:54:14 by sbres             #+#    #+#             */
/*   Updated: 2014/04/20 06:09:24 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include <stdio.h> //printf
#include <unistd.h> //write

static void		print_memory(int start, int end, int size)
{
	ft_putnbr(start);
	ft_putchar(' ');
	ft_putchar('-');
	ft_putchar(' ');
	ft_putnbr(end);
	write(1, " : ", 3);
	ft_putnbr(size);
	write(1, " bytes\n", 7);
}

static void		print_tiny()
{
	t_data	*tmp;
	int		find;

	find = 0;
	tmp = pages.tiny;
	while (tmp != NULL)
	{
		if (find == 0 && tmp->is_free == 0)
		{
			write(1, "TINY:\n", 7);
			find = 1;
		}
		if (tmp->is_free == 0)
			print_memory((intptr_t)tmp->ptr, (intptr_t)tmp->ptr + tmp->size - 1, tmp->size);
		tmp = tmp->next;
	}
}

static void		print_medium()
{
	t_data	*tmp;
	int		find;

	find = 0;
	tmp = pages.medium;
	while (tmp != NULL)
	{
		if (find == 0 && tmp->is_free == 0)
		{

			write(1, "MEDIUM:\n", 8);
			find = 1;
		}
		if (tmp->is_free == 0)
			print_memory((intptr_t)tmp->ptr, (intptr_t)tmp->ptr + tmp->size - 1, tmp->size);
		tmp = tmp->next;
	}
}

static void		print_big()
{
	t_data	*tmp;
	int		find;

	find = 0;
	tmp = pages.big;
	while (tmp != NULL)
	{
		if (find == 0 && tmp->is_free == 0)
		{
			write(1,"BIG:\n", 5);
			find = 1;
		}
		if (tmp->is_free == 0)
			print_memory((intptr_t)tmp->ptr, (intptr_t)tmp->ptr + tmp->size - 1, tmp->size);
		tmp = tmp->next;
	}
}

void			show_alloc_mem()
{
	print_tiny();
	print_medium();
	print_big();
}
