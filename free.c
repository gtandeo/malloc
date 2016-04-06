/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtandeo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 05:24:11 by gtandeo           #+#    #+#             */
/*   Updated: 2016/01/06 10:32:25 by gtandeo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_malloc.h>

static void		check_all_is_free(t_block *zone, int size)
{
	t_block		*tmp;

	tmp = zone;
	while (tmp && tmp->next)
	{
		if (!tmp->is_free)
			return ;
		tmp = tmp->next;
	}
	munmap(zone, size);
	return ;
}

static int		free_large(void *ptr)
{
	t_block		*tmp;

	tmp = g_malloc.large;
	while (tmp && tmp->next)
	{
		if (&(tmp->ptr) == &ptr)
		{
			munmap(tmp, tmp->size);
			return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}

static int		set_free(t_block *zone, void *ptr)
{
	t_block		*tmp;

	tmp = zone;
	while (tmp && tmp->next)
	{
		if (&(tmp->ptr) == &ptr)
		{
			tmp->is_free = 1;
			return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}

void			free(void *ptr)
{
	if (set_free(g_malloc.tiny, ptr) && set_free(g_malloc.small, ptr)
		&& free_large(ptr))
	{
		write(2, "free error\n", 11);
		exit(0);
	}
	check_all_is_free(g_malloc.tiny, TINY_ZONE);
	check_all_is_free(g_malloc.small, SMALL_ZONE);
	return ;
}
