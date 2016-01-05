/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtandeo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 05:19:03 by gtandeo           #+#    #+#             */
/*   Updated: 2016/01/05 03:58:53 by gtandeo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ALLOC_H
# define FT_ALLOC_H

# include <stdio.h>

# include <stdlib.h>
# include <unistd.h>
# include <sys/mman.h>

# define TINY 16384
# define SMALL 65536
# define N 4096
# define M 32768

void	free(void *ptr);
void	*ft_malloc(size_t size);
void	*realloc(void *ptr, size_t size);

#endif
