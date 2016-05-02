/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtandeo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 05:24:22 by gtandeo           #+#    #+#             */
/*   Updated: 2016/01/06 10:32:15 by gtandeo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_malloc.h>

void	*realloc(void *ptr, size_t size)
{
	(void)ptr;
	if (!size)
		free(ptr);
	return (NULL);
}
