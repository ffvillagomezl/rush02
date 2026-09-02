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

/* Traduce las centenas. Ej: para '9', imprime "nine" y luego "hundred". */
void	ft_eval_hundreds(char *buf, char digit)
{
	char	n[2];

	n[0] = digit;
	n[1] = '\0';
	ft_write_num(buf, n);      // Imprime unidad
	ft_write_num(buf, "100");  // Imprime cien
}

/* Evalúa las decenas. Retorna 1 si es un número del 10 al 19 para saltar
 * las unidades (ej: "eleven" en vez de "ten one").
 */
int	ft_eval_tens(char *buf, char *num, int i)
{
	char	n[3];

	if (num[i] == '1')
	{
		ft_write_num(buf, num + i); // Imprime directo "10", "11", "12", etc.
		return (1);
	}
	n[0] = num[i];
	n[1] = '0';
	n[2] = '\0';
	ft_write_num(buf, n); // Imprime "20", "30", etc.
	return (0);
}

/* Analiza la posición de cada dígito en el grupo para saber 
 * si tratarlo como centena, decena o unidad.
 */
void	ft_evaluate_numbers(char *buf, char *num)
{
	int		num_len = ft_strlen(num);
	int		i = 0;
	char	n[2];

	while (i < num_len)
	{
		// Distancia 3 = Centenas
		if ((num_len - i) == 3 && num[i] != '0')
			ft_eval_hundreds(buf, num[i]);
		// Distancia 2 = Decenas
		else if ((num_len - i) == 2 && num[i] != '0')
		{
			// Si es del 10 al 19, consumimos decenas y unidades y salimos
			if (ft_eval_tens(buf, num, i) == 1)
				break ;
		}
		// Distancia 1 = Unidades
		else if ((num_len - i) == 1 && num[i] != '0')
		{
			n[0] = num[i];
			n[1] = '\0';
			ft_write_num(buf, n);
		}
		i++;
	}
}