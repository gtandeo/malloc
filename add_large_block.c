/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_large_block.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtandeo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 07:59:36 by gtandeo           #+#    #+#             */
/*   Updated: 2016/04/06 07:59:37 by gtandeo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_malloc.h>

static void	*add_large_block(int size)
{
	t_block			*tmp;
	t_block			*block;

	tmp = g_malloc.large;
	while (tmp && tmp->next)
		tmp = tmp->next;
	if ((block = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0))
			== MAP_FAILED)
		return (NULL);
	block->size = size;
	block->prev = tmp;
	block->next = NULL;
	block->is_free = 0;
	tmp->next = block;
	return (&(block->ptr));
}

void		*add_large(int size)
{
	if (!g_malloc.small)
	{
		if ((g_malloc.large = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0))
				== MAP_FAILED)
			return (NULL);
		g_malloc.small->size = size;
		g_malloc.small->prev = NULL;
		g_malloc.small->next = NULL;
		g_malloc.small->is_free = 0;
		return (&(g_malloc.small->ptr));
	}
	else
		return (add_large_block(size));
	return (NULL);
}
