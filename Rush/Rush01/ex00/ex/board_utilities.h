/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_utilities.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 16:22:26 by amura             #+#    #+#             */
/*   Updated: 2023/08/20 18:30:19 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		create_board(int board[6][6]);
void		print_board_with_indices(int board[6][6]);
void		print_board(int board[6][6]);
void		init_board(int board[6][6], int *params);
int			is_line_empty(int board[6][6], int coord, enum e_Direction d);
int			get_building_indice(int board[6][6], int coord, enum e_Direction d);
int			has_a_doublon(int board[6][6], int coord, enum e_Direction d);
int			is_indice_valid(int board[6][6], int coord, enum e_Direction d);
int			is_column_valid(int board[6][6], int x);
int			is_line_valid(int board[6][6], int y);
int			is_board_valid(int board[6][6]);
int			fill_board(int board[6][6], int starting_coord, enum e_Direction d);
