/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtandeo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 05:17:14 by gtandeo           #+#    #+#             */
/*   Updated: 2016/01/21 20:56:07 by gtandeo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_malloc.h>
#include <stdio.h>

int		main(void)
{
	char	*test;
	char	*test2;
	char	*test3;
	char	*test4;
	char	*test5;
	char	*test6;

	if ((test = (char*)malloc(sizeof(char) * 7)) == NULL)
		write(1, "malloc 1 error\n", 15);
	if ((test2 = (char*)malloc(sizeof(char) * 3)) == NULL)
		write(1, "malloc 2 error\n", 15);
	if ((test3 = (char*)malloc(sizeof(char) * 1024)) == NULL)
		write(1, "malloc 3 error\n", 15);
	if ((test4 = (char*)malloc(sizeof(char) * 984702938)) == NULL)
		write(1, "malloc 4 error\n", 15);
	if ((test5 = (char*)malloc(sizeof(char) * 984938)) == NULL)
		write(1, "malloc 5 error\n", 15);
	if ((test6 = (char*)malloc(sizeof(char) * 0)) == NULL)
		write(1, "malloc 6 error\n", 15);
	test[0] = 't';
	test[1] = 'e';
	test[2] = 's';
	test[3] = 't';
	test[4] = '\0';
	printf("%s\n", test);
	//free(test);
	test2[0] = 't';
	test2[1] = 'e';
	test2[2] = '\0';
	printf("%s\n", test2);
	//free(test2);
	realloc(test3, 14);
	show_alloc_mem();
	return (0);
}
