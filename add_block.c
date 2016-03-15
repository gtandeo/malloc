/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_sigleton.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtandeo <gtandeo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 23:55:41 by gtandeo           #+#    #+#             */
/*   Updated: 2016/01/22 02:40:09 by gtandeo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_malloc.h>

void	*add_tiny(int size)
{
	t_block			*tmp;
	t_block			*block;

	if (!g_malloc.tiny)
	{
		if ((g_malloc.tiny = mmap(NULL, TINY_ZONE, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0))
				== MAP_FAILED)
			return (NULL);
		g_malloc.tiny->size = size;
		g_malloc.tiny->prev = NULL;
		g_malloc.tiny->next = NULL;
		g_malloc.tiny->is_free = 0;
		return (&(g_malloc.tiny->ptr));
	}
	else
	{
		tmp = g_malloc.tiny;
		while (tmp && tmp->next)
			tmp = tmp->next;
		tmp->next = tmp + sizeof(t_block) - sizeof(tmp->data) + tmp->size;
		block = tmp->next;
		block->size = size;
		block->prev = tmp;
		block->next = NULL;
		block->is_free = 0;
		return (&(block->ptr));
	}
}

void	*add_small(int size)
{
	t_block			*tmp;
	t_block			*block;

	if (!g_malloc.small)
	{
		if ((g_malloc.small = mmap(NULL, SMALL_ZONE, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0))
				== MAP_FAILED)
			return (NULL);
		g_malloc.small->size = size;
		g_malloc.small->prev = NULL;
		g_malloc.small->next = NULL;
		g_malloc.small->is_free = 0;
		return (&(g_malloc.small->ptr));
	}
	else
	{
		tmp = g_malloc.small;
		while (tmp && tmp->next)
			tmp = tmp->next;
		tmp->next = tmp + sizeof(t_block) - sizeof(tmp->data) + tmp->size;
		block = tmp->next;
		block->size = size;
		block->prev = tmp;
		block->next = NULL;
		block->is_free = 0;
		return (&(block->ptr));
	}
}

void	*add_large(int size)
{
	(void)size;
	return (NULL);
}
