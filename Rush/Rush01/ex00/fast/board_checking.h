/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_checking.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 18:58:44 by amura             #+#    #+#             */
/*   Updated: 2023/08/20 20:54:18 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check_left(int board[6][6], int coord, int max);
int	ft_check_right(int board[6][6], int coord, int max);
int	ft_check_top(int board[6][6], int coord, int max);
int	ft_check_bottom(int board[6][6], int coord, int max);