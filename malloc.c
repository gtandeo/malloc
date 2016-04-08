/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtandeo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 05:24:17 by gtandeo           #+#    #+#             */
/*   Updated: 2016/02/08 10:48:25 by gtandeo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_malloc.h>

void	*malloc(size_t size)
{
	if (tiny_remaining_size(size))
		return (add_tiny(size));
	else if (small_remaining_size(size))
		return (add_small(size));
	else
		return (add_large(size));
	return (NULL);
}
