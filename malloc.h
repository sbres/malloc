/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbres <sbres@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/16 23:38:04 by sbres             #+#    #+#             */
/*   Updated: 2014/04/20 15:58:50 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# define TINY_MAX 63
# define MEDIUM_MAX 255
# include <stdlib.h>

typedef struct		s_data
{
	size_t			size;
	void			*ptr;
	int				is_free;
	struct s_data	*next;
}					t_data;

typedef struct		s_pages
{
	t_data			*tiny;
	t_data			*medium;
	t_data			*big;
	int				tiny_page_size;
	int				medium_page_size;
}					t_pages;

void	init_pages();

void	*ft_tiny_malloc(size_t size);
void	*ft_medium_malloc(size_t size);
void	*ft_big_malloc(size_t size);
void	*ft_find_memory(void *page, int page_size, int size);
//void	set_header(void *start_point, int is_free, int size);

void		new_block(int size, void *ptr, int state, t_data **list);
void		*ftmalloc(size_t size);
void		*realloc(void *ptr, size_t size);
void		ftfree(void *ptr);
void		show_alloc_mem();
void		ft_putnbr(int n);
void		ft_putchar(char n);
void		show_alloc_mem();
t_pages		pages;

#endif