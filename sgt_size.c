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

int		tiny_size(int nbr)
{
	static int	rest = TINY_ZONE;

	rest += nbr;
	return (rest);
}

int		small_size(int nbr)
{
	static int	rest = SMALL_ZONE;

	rest += nbr;
	return (rest);
}
