/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtandeo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 10:28:30 by gtandeo           #+#    #+#             */
/*   Updated: 2016/04/18 10:28:31 by gtandeo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_malloc.h>

static void				ft_putnbr(unsigned long addr)
{
	int		n;

	if (addr < 10)
	{
		n = addr + 48;
		write(1, &n, 1);
	}
	if (addr > 9)
	{
		ft_putnbr(addr / 10);
		ft_putnbr(addr % 10);
	}
}

static void				print_addr(unsigned long addr)
{
	char	hex[16];
	int		i;

	i = 0;
	while (i < 10)
	{
		hex[i] = i + 48;
		i++;
	}
	while (i < 16)
	{
		hex[i] = i + 55;
		i++;
	}
	if (addr < 16)
		write(1, &hex[addr], 1);
	if (addr > 15)
	{
		print_addr(addr / 16);
		print_addr(addr % 16);
	}
}

static void				print_zone_addr(t_block *zone)
{
	t_block			*tmp;

	tmp = zone;
	while (tmp)
	{
		if (tmp->is_free == 0)
		{
			write(1, "0x", 2);
			print_addr((unsigned long)&(tmp->ptr));
			write(1, " - 0x", 5);
			print_addr((unsigned long)&(tmp->ptr) + tmp->size);
			write(1, " : ", 3);
			ft_putnbr(tmp->size);
			write(1, " octets\n", 8);
		}
		tmp = tmp->next;
	}
}

static unsigned long	get_zone_size(t_block *zone)
{
	t_block			*tmp;
	unsigned long	size;

	tmp = zone;
	size = 0;
	while (tmp)
	{
		size += tmp->size;
		tmp = tmp->next;
	}
	return (size);
}

void					show_alloc_mem(void)
{
	if (g_malloc.tiny)
	{
		write(1, "TINY : 0x", 9);
		print_addr((unsigned long)g_malloc.tiny);
		write(1, "\n", 1);
		print_zone_addr(g_malloc.tiny);
	}
	if (g_malloc.small)
	{
		write(1, "SMALL : 0x", 10);
		print_addr((unsigned long)g_malloc.small);
		write(1, "\n", 1);
		print_zone_addr(g_malloc.small);
	}
	if (g_malloc.large)
	{
		write(1, "LARGE : 0x", 10);
		print_addr((unsigned long)g_malloc.large);
		write(1, "\n", 1);
		print_zone_addr(g_malloc.large);
	}
	write(1, "Total : ", 8);
	ft_putnbr(get_zone_size(g_malloc.tiny) + get_zone_size(g_malloc.small)\
		+ get_zone_size(g_malloc.large));
	write(1, " octets\n", 8);
}
