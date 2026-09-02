/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_group.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: favillag <favillag@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 21:50:40 by favillag          #+#    #+#             */
/*   Updated: 2026/08/30 21:50:44 by favillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ft_alloc_group.c */
#include "headers.h"

/* Extrae el sub-string correspondiente al grupo actual usando el índice 'curr'
 * para llevar el rastro de por dónde va leyendo el string original 'num'.
 */
char	*ft_alloc_group(char *num, int num_len, int i, int *curr)
{
	char	*group;
	int		len;
	int		j;

	// Si es el primer grupo a la izquierda, calcula su tamaño (1, 2 o 3)
	if (i == 0)
		len = get_group_len(num_len);
	else
		len = 3;
		
	group = malloc(len + 1);
	if (!group)
		return (NULL);
		
	j = 0;
	// Copia los caracteres
	while (j < len)
	{
		group[j] = num[*curr + j];
		j++;
	}
	group[j] = '\0';
	*curr += len; // Avanza el cursor para el siguiente grupo
	return (group);
}
