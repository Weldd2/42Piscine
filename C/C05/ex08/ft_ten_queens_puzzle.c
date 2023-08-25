// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/08/24 18:24:28 by amura             #+#    #+#             */
// /*   Updated: 2023/08/24 19:13:46 by amura            ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include <unistd.h>
// #include <stdio.h>

// int	is_valid_col(int board[10][10], int col)
// {
// 	int	i;

// 	i = -1;
// 	while (++i < 10)
// 	{
// 		if (i != col)
// 		{
// 			if (board[i][col] == 1)
// 				return (0);
// 		}
// 	}
// 	return (1);
// }

// int	is_valid_row(int board[10][10], int row)
// {
// 	int	i;

// 	i = -1;
// 	while (++i < 10)
// 	{
// 		if (i != row)
// 		{
// 			if (board[row][i] == 1)
// 				return (0);
// 		}
// 	}
// 	return (1);
// }

// int	queen_puzzle_loop(int board[10][10], int row, int col)
// {
// 	if (is_valid_col(board, col) && is_valid_row(board, row) && row == 10)
// 		return (1);
// 	board[row][col] = 1;
// 	if (is_valid_row(board, row) && is_valid_col(board, col))
// 		queen_puzzle_loop(board, col, row + 1);
// 	else
// 	{
// 		board[row][col] = 0;
// 		queen_puzzle_loop(board, col + 1, row);
// 		return (0);
// 	}
// 	return (1);
// }

// void	init_board(int board[10][10])
// {
// 	int	i;
// 	int	j;

// 	i = -1;
// 	while (++i < 10)
// 	{
// 		j = -1;
// 		while (++j < 10)
// 		{
// 			board[i][j] = 0;
// 		}
// 	}
// }

// void	print_board(int board[10][10])
// {
// 	int	i;
// 	int	j;
// 	int	temp;

// 	i = -1;
// 	while (++i < 10)
// 	{
// 		j = -1;
// 		while (++j < 10)
// 		{
// 			temp = board[i][j] + '0';
// 			write(1, &temp, 1);
// 		}
// 		write(1, "\n", 1);
// 	}
// }

// int ft_ten_queens_puzzle(void)
// {
// 	int	board[10][10];

// 	init_board(board);
// 	printf("%d\n", queen_puzzle_loop(board, 0, 0));
// 	print_board(board);
// 	return (0);
// }

// int	main(void)
// {
// 	ft_ten_queens_puzzle();
// 	return (0);
// }