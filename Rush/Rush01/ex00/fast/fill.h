/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 18:48:00 by amura             #+#    #+#             */
/*   Updated: 2023/08/20 21:55:23 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "globals.h"

void	ft_fill_h(int board[6][6], int coord, int start_value, int step);
void	ft_fill_vertical(int board[6][6], int coord, int start_value, int step);
int		ft_fill_board(int board[6][6], int starting_coord, enum e_Direction d);
void	ft_fill_board_if_condition(int board[6][6], int i, int direction);
