/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pages.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbres <sbres@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/18 16:03:14 by sbres             #+#    #+#             */
/*   Updated: 2014/04/19 10:16:44 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include <stdlib.h>//maloc ?
#include <unistd.h>
#include <stdio.h>//printf
#include <sys/mman.h>//mmap
/*
** On definis la taille des zonnes tiny et medium par rapport a la taille
** des pages. 
*/

static void		define_zones(int *tiny_page, int *medium_page)
{
	int		page_size;

	page_size = getpagesize();
	*tiny_page = page_size * 2;
	*medium_page = page_size * 8;
}

/*
** Tiny termine a donc de 1-63
** Medium termine a 255 donc 64-255
** Big comence a 256
*/

void			init_pages()
{
	void		*tiny_ptr;
	void		*medium_ptr;

	define_zones(&pages.tiny_page_size, &pages.medium_page_size);
	// printf("tiny va jussca %d\nmeduin va jussca %d\n", TINY_MAX , MEDIUM_MAX);
	// printf("table petite est de %d bytes\n", pages.tiny_page_size );
	// printf("table moyenne est de %d bytes\n", pages.medium_page_size );
	tiny_ptr = mmap(NULL, pages.tiny_page_size, PROT_READ | PROT_WRITE,
						MAP_PRIVATE|MAP_ANON, -1, 0);
	medium_ptr = mmap(NULL, pages.medium_page_size, PROT_READ | PROT_WRITE,
						MAP_PRIVATE|MAP_ANON, -1, 0);
	pages.tiny = NULL;
	pages.medium = NULL;
	pages.big = NULL;
	new_block(pages.tiny_page_size, tiny_ptr, 1, &pages.tiny);
	//printf("%p\n", pages.tiny);
	new_block(pages.medium_page_size, medium_ptr, 1, &pages.medium);
	//printf("%p\n", pages.tiny);
}
