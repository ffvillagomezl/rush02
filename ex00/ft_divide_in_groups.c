/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_divide_in_groups.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: favillag <favillag@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 21:43:33 by favillag          #+#    #+#             */
/*   Updated: 2026/08/30 21:45:35 by favillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

/* Calcula el tamaño del primer grupo (el que queda a la izquierda del todo).
 * Ej: Para "12345" (len=5), el módulo es 2. Retorna 2 (el grupo "12").
 */
int	get_group_len(int num_len)
{
	if (num_len % 3 != 0)
		return (num_len % 3);
	return (3);
}

/* Verifica si un grupo de 3 es solo ceros (ej. "000").
 * Si es puro cero, no se imprime su sufijo (ej. no decimos "cero miles").
 */
int	is_not_empty_group(char *str)
{
	int	i = 0;
	while (str[i])
	{
		if (str[i] != '0')
			return (1);
		i++;
	}
	return (0);
}

/* Construye la cadena dinámica del sufijo de magnitud (1000, 1000000, etc.)
 * Añade ceros en base a los grupos restantes.
 */
void	ft_build_suffix(char *buf, int remaining_groups)
{
	char	*units;
	int		j;

	units = malloc(3 * remaining_groups + 2);
	if (!units)
		return ;
	units[0] = '1';
	j = 1;
	while (j <= 3 * remaining_groups)
	{
		units[j] = '0';
		j++;
	}
	units[j] = '\0';
	ft_write_num(buf, units); // Imprime "thousand", "million", etc.
	free(units);
}

/* Itera sobre los grupos ya separados, los evalúa (traduce) 
 * y les asigna su sufijo correspondiente si no están vacíos.
 */
void	ft_parse_suffixes(char *buf, char **groups, int num_of_groups)
{
	int	i = 0;
	int	rem;

	while (i < num_of_groups)
	{
		ft_evaluate_numbers(buf, groups[i]); // Traduce las centenas, decenas, uds.
		rem = num_of_groups - 1 - i;
		if (rem > 0 && is_not_empty_group(groups[i]))
			ft_build_suffix(buf, rem);
		free(groups[i]); // Libera el string del grupo actual
		i++;
	}
	free(groups); // Libera el array de punteros
}

/* Función principal que orquesta la división de la cadena de entrada 
 * en una matriz de grupos más pequeños de hasta 3 caracteres.
 */
void	ft_divide_in_groups(char *buf, char *num, char *dict)
{
	int		num_len;
	int		num_of_groups;
	char	**groups;
	int		i;
	int		curr;

	(void)dict;
	num_len = ft_strlen(num);
	if (num_len == 0)
		return ;
		
	// Fórmula matemática para saber cuántos grupos de 3 salen. 
	num_of_groups = (num_len + 2) / 3; 
	groups = malloc(sizeof(char *) * num_of_groups);
	if (!groups)
		return ;
		
	i = -1;
	curr = 0;
	// Llenamos el array de grupos
	while (++i < num_of_groups)
	{
		groups[i] = ft_alloc_group(num, num_len, i, &curr);
		if (!groups[i])
			return ;
	}
	ft_parse_suffixes(buf, groups, num_of_groups);
}
