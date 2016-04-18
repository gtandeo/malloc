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

	if ((test = (char*)malloc(sizeof(char) * 5)) == NULL)
		write(1, "error\n", 6);
	if ((test2 = (char*)malloc(sizeof(char) * 3)) == NULL)
		write(1, "error\n", 6);
	test[0] = 't';
	test[1] = 'e';
	test[2] = 's';
	test[3] = 't';
	test[4] = '\0';
	printf("%s\n", test);
<<<<<<< HEAD
	//free(test);
=======
	free(test);
>>>>>>> 338fbd5d505c2c6449b05ca01eebd47cbb3f3d93
	test2[0] = 't';
	test2[1] = 'e';
	test2[2] = '\0';
	printf("%s\n", test2);
<<<<<<< HEAD
	//free(test2);
	show_alloc_mem();
=======
	free(test2);
>>>>>>> 338fbd5d505c2c6449b05ca01eebd47cbb3f3d93
	return (0);
}
