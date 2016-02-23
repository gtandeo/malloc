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

#include "libft_malloc.h"

void	free(void *ptr)
{
	t_block		*tmp;
	t_block		*tmp2;
	t_block		*tmp3;

	tmp = g_malloc.tiny;
	while (tmp && tmp->next)
	{
		if (tmp->ptr == ptr)
		{
			tmp->is_free = 0;
			return ;
		}
	}
	tmp2 = g_malloc.small;
	while (tmp2 && tmp2->next)
	{
		if (tmp2->ptr == ptr)
		{
			tmp2->is_free = 0;
			return ;
		}
	}
	tmp3 = g_malloc.large;
	while (tmp3 && tmp3->next)
	{
		if (tmp3->ptr == ptr)
		{
			tmp3->is_free = 0;
			return ;
		}
	}
	write(1, "free error\n", 11);
	exit(0);
	return ;
}
