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

static void	*add_block(size_t size, t_block *list)
{
	t_block		*tmp;
	t_block		*block;

	tmp = list;
	if (tmp && size <= tmp->size && tmp->is_free == 1)
	{
		tmp->size = size;
		tmp->is_free = 0;
		return (&(tmp->ptr));
	}
	while (tmp && tmp->next)
	{
		if (size <= tmp->size && tmp->is_free == 1)
		{
			tmp->size = size;
			tmp->is_free = 0;
			return (&(tmp->ptr));
		}
		tmp = tmp->next;
	}
	tmp->next = tmp + sizeof(t_block) - sizeof(tmp->data) + tmp->size;
	init_block(&block, tmp, size);
	/*block = tmp->next;
	block->size = size;
	block->prev = tmp;
	block->next = NULL;
	block->is_free = 0;*/
	return (&(block->ptr));
}

static void	*add_large_block(size_t size)
{
	t_block			*tmp;
	t_block			*block;

	tmp = g_malloc.large;
	if (tmp && size <= tmp->size && tmp->is_free == 1)
	{
		tmp->size = size;
		tmp->is_free = 0;
		return (&(tmp->ptr));
	}
	while (tmp && tmp->next)
	{
		if (size <= tmp->size && tmp->is_free == 1)
		{
			tmp->size = size;
			tmp->is_free = 0;
			return (&(tmp->ptr));
		}
		tmp = tmp->next;
	}
	if (init_large_block(&block, &tmp, size))
		return (NULL);
	/*if ((block = mmap(NULL, size, PROT_READ | PROT_WRITE,
		MAP_ANON | MAP_PRIVATE, -1, 0))
			== MAP_FAILED)
		return (NULL);
	block->size = size;
	block->prev = tmp;
	block->next = NULL;
	block->is_free = 0;
	tmp->next = block;*/
	return (&(block->ptr));
}

void		*add_tiny(int size)
{
	if (!g_malloc.tiny)
	{
		if ((g_malloc.tiny = mmap(NULL, TINY_ZONE, PROT_READ | PROT_WRITE,
			MAP_ANON | MAP_PRIVATE, -1, 0))
				== MAP_FAILED)
			return (NULL);
		g_malloc.tiny->size = size;
		g_malloc.tiny->prev = NULL;
		g_malloc.tiny->next = NULL;
		g_malloc.tiny->is_free = 0;
		return (&(g_malloc.tiny->ptr));
	}
	else
		return (add_block(size, g_malloc.tiny));
}

void		*add_small(int size)
{
	if (!g_malloc.small)
	{
		if ((g_malloc.small = mmap(NULL, SMALL_ZONE, PROT_READ | PROT_WRITE,
			MAP_ANON | MAP_PRIVATE, -1, 0))
				== MAP_FAILED)
			return (NULL);
		g_malloc.small->size = size;
		g_malloc.small->prev = NULL;
		g_malloc.small->next = NULL;
		g_malloc.small->is_free = 0;
		return (&(g_malloc.small->ptr));
	}
	else
		return (add_block(size, g_malloc.small));
}

void		*add_large(int size)
{
	if (!g_malloc.large)
	{
		if ((g_malloc.large = mmap(NULL, size, PROT_READ | PROT_WRITE,
			MAP_ANON | MAP_PRIVATE, -1, 0))
				== MAP_FAILED)
			return (NULL);
		g_malloc.large->size = size;
		g_malloc.large->prev = NULL;
		g_malloc.large->next = NULL;
		g_malloc.large->is_free = 0;
		return (&(g_malloc.large->ptr));
	}
	else
		return (add_large_block(size));
}
