/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 18:27:02 by amura             #+#    #+#             */
/*   Updated: 2023/08/20 20:52:14 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_try_next_position(int board[6][6], int row, int col);
int		ft_solve(int board[6][6], int row, int col);
void	ft_optimizer(int board[6][6]);
