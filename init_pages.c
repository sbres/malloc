/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pages.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbres <sbres@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/18 16:03:14 by sbres             #+#    #+#             */
/*   Updated: 2014/04/20 19:36:34 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include <unistd.h>
#include <sys/mman.h>

static void		define_zones(int *tiny_page, int *medium_page)
{
	int		page_size;

	page_size = getpagesize();
	*tiny_page = page_size * 2;
	*medium_page = page_size * 8;
}

void			init_pages(void)
{
	void		*tiny_ptr;
	void		*medium_ptr;

	define_zones(&pages.tiny_page_size, &pages.medium_page_size);
	tiny_ptr = mmap(NULL, pages.tiny_page_size, PROT_READ | PROT_WRITE,
						MAP_PRIVATE | MAP_ANON, -1, 0);
	medium_ptr = mmap(NULL, pages.medium_page_size, PROT_READ | PROT_WRITE,
						MAP_PRIVATE | MAP_ANON, -1, 0);
	pages.tiny = NULL;
	pages.medium = NULL;
	pages.big = NULL;
	new_block(pages.tiny_page_size, tiny_ptr, 1, &pages.tiny);
	new_block(pages.medium_page_size, medium_ptr, 1, &pages.medium);
}
