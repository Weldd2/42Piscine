/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_checking.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 18:58:44 by amura             #+#    #+#             */
/*   Updated: 2023/08/20 19:15:19 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_left(int board[6][6], int coord, int max);
int	check_right(int board[6][6], int coord, int max);
int	check_top(int board[6][6], int coord, int max);
int	check_bottom(int board[6][6], int coord, int max);