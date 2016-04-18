/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sgt_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtandeo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 07:47:23 by gtandeo           #+#    #+#             */
/*   Updated: 2016/04/06 07:47:24 by gtandeo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_malloc.h>

int		tiny_remaining_size(int block_size)
{
	static int		total_size = 0;
	unsigned int	tmp;

	tmp = total_size + (sizeof(t_block) + block_size);
	if (tmp > (unsigned int)TINY_ZONE)
		return (0);
	else
	{
		total_size += (sizeof(t_block) + block_size);
		return (1);
	}
}

int		small_remaining_size(int block_size)
{
	static int		total_size = 0;
	unsigned int	tmp;

	tmp = total_size + (sizeof(t_block) + block_size);
	if (tmp > (unsigned int)SMALL_ZONE)
		return (0);
	else
	{
		total_size += (sizeof(t_block) + block_size);
		return (1);
	}
}
