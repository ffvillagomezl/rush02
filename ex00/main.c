/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: favillag <favillag@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 20:39:20 by favillag          #+#    #+#             */
/*   Updated: 2026/08/29 20:40:23 by favillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int	main(int argc, char *argv[])
{
	char	*num;
	char	*dict;
	char	*buf;

	dict = "numbers.dict";
	if (argc > 3 || argc <= 1)
		write(2, "Error\n", 6);
	if (argc == 2)
		num = argv[1];
	if (argc == 3)
	{
		dict = argv[1];
		num = argv[2];
	}
	buf = dict_iterator(dict);
	write(1, buf, 691);
	//ft_write_num(buf, "0");
	free(buf);
	return (0);
}
