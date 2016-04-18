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

static void	ft_putnbr(unsigned int addr)
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

static void	print_addr(unsigned int addr)
{
	char	hex[] = "0123456789ABCDEF";

	if (addr < 16)
		write(1, &hex[addr], 1);
	if (addr > 15)
	{
		print_addr(addr / 16);
		print_addr(addr % 16);
	}
}

static int	print_zone_addr(t_block *zone)
{
	t_block			*tmp;
	unsigned int	zone_size;

	tmp = zone;
	zone_size = 0;
	while (tmp)
	{
		if (tmp->is_free == 0)
		{
			write(1, "0x", 2);
			print_addr((unsigned int)&(tmp->ptr));
			write(1, " - 0x", 5);
			print_addr((unsigned int)&(tmp->ptr) + tmp->size);
			write(1, " : ", 3);
			ft_putnbr(tmp->size);
			write(1, " octets\n", 8);
			zone_size += tmp->size;
		}
		tmp = tmp->next;
	}
	return (zone_size);
}

void		show_alloc_mem(void)
{
	unsigned int	total_size;

	total_size = 0;
	write(1, "TINY : 0x", 9);
	print_addr((unsigned int)&(g_malloc.tiny));
	write(1, "\n", 1);
	total_size += print_zone_addr(g_malloc.tiny);
	write(1, "SMALL : 0x", 10);
	print_addr((unsigned int)&(g_malloc.small));
	write(1, "\n", 1);
	total_size += print_zone_addr(g_malloc.small);
	write(1, "LARGE : 0x", 10);
	print_addr((unsigned int)&(g_malloc.large));
	write(1, "\n", 1);
	total_size += print_zone_addr(g_malloc.large);
	write(1, "Total : ", 8);
	ft_putnbr(total_size);
	write(1, " octets\n", 8);
}
