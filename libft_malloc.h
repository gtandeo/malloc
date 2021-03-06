/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_malloc.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtandeo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 07:54:41 by gtandeo           #+#    #+#             */
/*   Updated: 2016/05/11 09:40:28 by gtandeo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_MALLOC_H
# define LIBFT_MALLOC_H

# include <unistd.h>
# include <sys/mman.h>
# include <sys/time.h>
# include <sys/resource.h>

# include <stdio.h>

# define TINY_BLOCK 2048
# define SMALL_BLOCK 130208
# define TINY_ZONE (128 * getpagesize())
# define SMALL_ZONE (1024 * getpagesize())

typedef struct		s_block
{
	size_t			size;
	struct s_block	*next;
	struct s_block	*prev;
	int				is_free;
	void			*ptr;
	char			data[1];
}					t_block;

typedef struct		s_malloc
{
	t_block			*tiny;
	t_block			*small;
	t_block			*large;
}					t_malloc;

t_malloc			g_malloc;

void				free(void *ptr);
void				*malloc(size_t size);
void				*realloc(void *ptr, size_t size);
void				show_alloc_mem();
void				*add_tiny(int size);
void				*add_small(int size);
void				*add_large(int size);
void				init_block(t_block **block, t_block *tmp, size_t size);
int					init_large_block(t_block **block, t_block **tmp,
					size_t size);
int					tiny_remaining_size(int block_size);
int					small_remaining_size(int block_size);

#endif
