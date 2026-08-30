/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: favillag <favillag@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 20:41:17 by favillag          #+#    #+#             */
/*   Updated: 2026/08/29 20:43:57 by favillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int	match_line(char *buf, int i, char *digits, int digit_len)
{
	int	j;

	j = 0;
	while (j < digit_len && buf[i + j] == digits[j])
		j++;
	if (j == digit_len)
	{
		i += j;
		while (buf[i] == ' ')
			i++;
		if (buf[i] == ':')
			return (i);
	}
	return (-1);
}

void	print_word(char *buf, int i)
{
	if (buf[i] == ':')
		i++;
	while (buf[i] == ' ')
		i++;
	while (buf[i] && buf[i] != '\n')
	{
		write(1, &buf[i], 1);
		i++;
	}
	write(1, " ", 1);
}

void	ft_write_num(char *buf, char *digits)
{
	int	i;
	int	digit_len;
	int	colon_pos;

	i = 0;
	digit_len = ft_strlen(digits);
	while (buf[i])
	{
		if (i == 0 || buf[i - 1] == '\n')
		{
			colon_pos = match_line(buf, i, digits, digit_len);
			if (colon_pos != -1)
			{
				print_word(buf, colon_pos);
				return ;
			}
		}
		i++;
	}
}
