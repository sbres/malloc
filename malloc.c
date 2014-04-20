/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbres <sbres@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/17 11:31:51 by sbres             #+#    #+#             */
/*   Updated: 2014/04/20 05:02:10 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include <stdlib.h>
#include <unistd.h>

/*
** Au debut de malloc on va pre_alouer les tables
** Apres on va rajouter la taille du header pour definir une categorie
*/

void	*malloc(size_t size)
{
	static int		is_init = 0;
	void			*memory_zone;
	write(1, "my malloc bitch\n", 16);

	if (size <= 0)
		return (NULL);
	if (is_init == 0)
	{
		init_pages();
		is_init = 1;
	}
	if (size <= TINY_MAX)
		memory_zone = ft_tiny_malloc(size);
	else if (size <= MEDIUM_MAX)
		memory_zone = ft_medium_malloc(size);
	else
		memory_zone = ft_big_malloc(size);
	return (memory_zone);
}
/*
int main(void)
{
	char	*toto;

	toto = (char*)ft_malloc(300);
	printf("\n\n");
	ft_show_alloc_mem();
	printf("toto = %p\n", toto );
	toto = ft_realloc(toto, 310);
	printf("toto = %p\n", NULL );
	printf("\n\n");
	ft_show_alloc_mem();
	ft_free(toto);
	printf("\n\n");
	ft_show_alloc_mem();*/

	//printf("%zu\n", sizeof(char));
	//return 0;
//}
