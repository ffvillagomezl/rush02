/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: favillag <favillag@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 20:44:22 by favillag          #+#    #+#             */
/*   Updated: 2026/08/30 22:28:17 by favillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADERS_H
# define HEADERS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

char	*dict_iterator(char *dict);
int		ft_strlen(char *str);
int		ft_zero_check(char *num, char *buf);
void	ft_divide_in_groups(char *buf, char *num, char *dict);
int		get_group_len(int num_len);
int		is_not_empty_group(char *str);
void	ft_build_suffix(char *buf, int remaining_groups);
void	ft_parse_suffixes(char *buf, char **groups, int num_of_groups);
char	*ft_alloc_group(char *num, int num_len, int i, int *curr);
void	ft_write_num(char *buf, char *digit);
int		match_line(char *buf, int i, char *digits, int digit_len);
void	print_word(char *buf, int i);
void	ft_eval_hundreds(char *buf, char digit);
int		ft_eval_tens(char *buf, char *num, int i);
void	ft_evaluate_numbers(char *buf, char *num);
int		ft_is_numeric(char *str);
int		ft_parse_args(int argc, char *argv[], char **dict, char **num);

#endif
