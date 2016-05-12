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

static void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*source;
	unsigned char	*desti;

	source = (unsigned char *)src;
	desti = (unsigned char *)dst;
	if (n > 0)
	{
		while (n--)
			*desti++ = *source++;
	}
	return (dst);
}

static void	*ptr_is_find(t_block *zone, void *ptr, size_t size)
{
	t_block		*tmp;
	void		*ret;

	tmp = zone;
	while (tmp)
	{
		if (&(tmp->ptr) == ptr)
		{
			ret = malloc(size);
			//printf("test\n");
			printf("cpy = %s", ft_memcpy(ret, ptr, size));
			return (ft_memcpy(ret, ptr, size));
		}
		tmp = tmp->next;
	}
	return (NULL);
}

void		*realloc(void *ptr, size_t size)
{
	void	*ret_0;
	void	*ret_1;
	void	*ret_2;

	if (size == 0)
	{
		free(ptr);
		return (malloc(TINY_BLOCK));
	}
	if (ptr == NULL)
		return (malloc(size));
	ret_0 = ptr_is_find(g_malloc.tiny, ptr, size);
	ret_1 = ptr_is_find(g_malloc.small, ptr, size);
	ret_2 = ptr_is_find(g_malloc.large, ptr, size);
	if (ret_0)
	{
		free(ptr);
		return (ret_0);
	}
	else if (ret_1)
	{
		free(ptr);
		return (ret_1);
	}
	else if (ret_2)
	{
		free(ptr);
		return (ret_2);
	}
	return (NULL);
}
