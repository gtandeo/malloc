/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtandeo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 05:19:03 by gtandeo           #+#    #+#             */
/*   Updated: 2016/01/22 02:39:56 by gtandeo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ALLOC_H
# define FT_ALLOC_H

# include <stdio.h>

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <sys/mman.h>
# include <sys/time.h>
# include <sys/resource.h>

# define TINY_BLOCK 128
# define SMALL_BLOCK 1024
# define TINY_ZONE (4 * getpagesize())
# define SMALL_ZONE (16 * getpagesize())

struct s_block {
	size_t			size;
	struct s_block	*next;
	struct s_block	*prev;
	int				free;
	void			*ptr;
	char			data[1];
};

void				free(void *ptr);
void				*ft_malloc(size_t size);
void				*realloc(void *ptr, size_t size);
void				show_alloc_mem();

#endif
