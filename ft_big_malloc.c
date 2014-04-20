/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_malloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbres <sbres@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/18 18:56:01 by sbres             #+#    #+#             */
/*   Updated: 2014/04/19 09:45:24 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include <stdlib.h>
#include <sys/mman.h>//mmap

/*
** On fait un gros malloc de porc
** Apres on mets le dans un tableau de structures.
*/

void	*ft_big_malloc(size_t size)
{
	void	*tmp;

	tmp = mmap(NULL, size, PROT_READ | PROT_WRITE,
						MAP_PRIVATE|MAP_ANON, -1, 0);
	new_block(size, tmp, 0, &pages.big);
	return (tmp);
}