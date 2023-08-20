/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 18:27:02 by amura             #+#    #+#             */
/*   Updated: 2023/08/20 22:22:18 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "globals.h"

int				ft_solve(int board[6][6], int row);
void			ft_unset_row(int board[6][6], int row);
void			ft_set_row(int board[6][6], int row, t_Combination combo);
t_Combination	*ft_get_possible_c(int from, int to, int *num_combo);