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
	if (argc == 2)
		num = argv[1];
	else if (argc == 3)
	{
		dict = argv[1];
		num = argv[2];
	}
	else
	{
		write(2, "Error\n", 6);
		return (0);
	}
	buf = dict_iterator(dict);
	if (!buf)
		return (0);
	if (ft_zero_check(num, buf))
		return (0);
	ft_divide_in_groups(buf, num, dict);
	free(buf);
	return (0);
}
