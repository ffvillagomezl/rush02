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

int		ft_print_condition(int count, int i, char *buf);
void	ft_write_num(char *buf, char *digit);
int		is_bk_len1(int digit_len, int count);
int		is_bk(char *buf, int i, int j, int digit_len);

int	ft_print_condition(int count, int i, char *buf)
{
	count = 1;
	i++;
	while (buf[i] == ' ' || buf[i] == ':')
		i++;
	while (buf[i] != '\n')
	{
		write(1, &buf[i], 1);
		i++;
	}
	return (count);
}

int	is_bk_len1(int digit_len, int count)
{
	return (digit_len == 1 && count == 1);
}

int	is_bk(char *buf, int i, int j, int digit_len)
{
	return (buf[i] == '\n' && j == digit_len - 1 && digit_len != 1);
}

void	ft_write_num(char *buf, char *digit)
{
	int	i;
	int	j;
	int	digit_len;
	int	count;

	i = 0;
	j = 0;
	digit_len = ft_strlen(digit);
	while (buf[i])
	{
		while (buf[i] == digit[j])
		{
			if (j == digit_len - 1 && (buf[i + 1] == ' ' || buf[i + 1] == ':'))
			{
				count = ft_print_condition(count, i, buf);
				break ;
			}
			j++;
			i++;
		}
		if (is_bk_len1(digit_len, count) || (is_bk(buf, i, j, digit_len)))
			break ;
		j = 0;
		i++;
	}
}
