/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 16:22:42 by amura             #+#    #+#             */
/*   Updated: 2023/08/20 19:03:22 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		main(int argc, char **argv);

void	fill_array_with_digits(int *result, char *str);

int		count_valid_digits(char *str);

int		*get_params(char *str);

int		is_finished(int board[6][6]);