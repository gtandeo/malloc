/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtandeo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 05:24:17 by gtandeo           #+#    #+#             */
/*   Updated: 2016/01/22 02:25:28 by gtandeo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_malloc.h"

void	*tiny_allocation(void *ret, size_t size)
{
	if (mmap(ret, size, PROT_NONE, MAP_PRIVATE, 2, ft_abs(size / getpagesize()) + 1) == MAP_FAILED)
		return (NULL);
	return (ret);
}

void	*small_allocation(void *ret, size_t size)
{
	if (mmap(ret, size, PROT_NONE, MAP_PRIVATE, 2, ft_abs(size / getpagesize()) + 1) == MAP_FAILED)
		return (NULL);
	return (ret);
}

void	*ft_malloc(size_t size)
{
	if (size <= TINY_BLOCK)
		return (add_tiny(size));
	else if (size <= SMALL_BLOCK)
		return (add_small(size));
	else
		return (add_large(size));
	return (NULL);
}
