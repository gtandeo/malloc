/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtandeo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 05:24:17 by gtandeo           #+#    #+#             */
/*   Updated: 2016/01/06 11:01:52 by gtandeo          ###   ########.fr       */
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
	void	*ret;

	ret = NULL;
	printf("%zu\n", size);
	if (size <= TINY)
		return (tiny_allocation(ret, size));
	else if (size <= SMALL)
		return (small_allocation(ret, size));
	else if (mmap(ret, size, PROT_NONE, MAP_PRIVATE, 2, ft_abs(size / getpagesize()) + 1) == MAP_FAILED)
		return (NULL);
	return (ret);
}
