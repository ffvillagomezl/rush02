/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_evaluate_numbers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: favillag <favillag@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 21:50:56 by favillag          #+#    #+#             */
/*   Updated: 2026/08/30 21:58:22 by favillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

void	ft_eval_hundreds(char *buf, char digit);
int		ft_eval_tens(char *buf, char *num, int i);
void	ft_evaluate_numbers(char *buf, char *num);

void	ft_eval_hundreds(char *buf, char digit)
{
	char	n[2];

	n[0] = digit;
	n[1] = '\0';
	ft_write_num(buf, n);
	ft_write_num(buf, "100");
}

int	ft_eval_tens(char *buf, char *num, int i)
{
	char	n[3];

	if (num[i] == '1')
	{
		ft_write_num(buf, num + i);
		return (1);
	}
	n[0] = num[i];
	n[1] = '0';
	n[2] = '\0';
	ft_write_num(buf, n);
	return (0);
}

void	ft_evaluate_numbers(char *buf, char *num)
{
	int		num_len;
	int		i;
	char	n[2];

	num_len = ft_strlen(num);
	i = 0;
	while (i < num_len)
	{
		if ((num_len - i) == 3 && num[i] != '0')
			ft_eval_hundreds(buf, num[i]);
		else if ((num_len - i) == 2 && num[i] != '0')
		{
			if (ft_eval_tens(buf, num, i) == 1)
				break ;
		}
		else if ((num_len - i) == 1 && num[i] != '0')
		{
			n[0] = num[i];
			n[1] = '\0';
			ft_write_num(buf, n);
		}
		i++;
	}
}
