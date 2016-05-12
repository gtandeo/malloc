/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtandeo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 13:36:22 by gtandeo           #+#    #+#             */
/*   Updated: 2016/05/12 13:36:22 by gtandeo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_malloc.h>

void	init_block(t_block **block, t_block *tmp, size_t size)
{
	*block = tmp->next;
	(*block)->size = size;
	(*block)->prev = tmp;
	(*block)->next = NULL;
	(*block)->is_free = 0;
}

int		init_large_block(t_block **block, t_block **tmp, size_t size)
{
	if (((*block) = mmap(NULL, size, PROT_READ | PROT_WRITE,
		MAP_ANON | MAP_PRIVATE, -1, 0))
			== MAP_FAILED)
		return (1);
	(*block)->size = size;
	(*block)->prev = *tmp;
	(*block)->next = NULL;
	(*block)->is_free = 0;
	(*tmp)->next = *block;
	return (0);
}
