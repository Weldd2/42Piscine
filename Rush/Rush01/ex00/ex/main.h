/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 16:22:42 by amura             #+#    #+#             */
/*   Updated: 2023/08/20 18:27:29 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		solve(int board[6][6], int row, int col);

int		*get_params(char *str);

void	optimizer(int board[6][6]);

int		is_finished(int board[6][6]);

int		main(int argc, char **argv);

int	try_next_position(int board[6][6], int row, int col);
