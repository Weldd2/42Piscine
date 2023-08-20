/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_valid.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 18:46:00 by amura             #+#    #+#             */
/*   Updated: 2023/08/20 20:56:00 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "globals.h"
#include "main.h"

int	ft_is_indice_valid(int board[6][6], int coord, enum e_Direction d);
int	ft_is_column_valid(int board[6][6], int x);
int	ft_is_line_valid(int board[6][6], int y);
int	ft_ft_is_board_valid(int board[6][6]);