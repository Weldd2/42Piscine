/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 18:27:02 by amura             #+#    #+#             */
/*   Updated: 2023/08/20 19:16:35 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		try_next_position(int board[6][6], int row, int col);
int		solve(int board[6][6], int row, int col);
void	optimizer(int board[6][6]);
