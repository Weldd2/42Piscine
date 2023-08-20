/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_utilities.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 16:22:26 by amura             #+#    #+#             */
/*   Updated: 2023/08/20 20:55:02 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_line_empty(int board[6][6], int coord, enum e_Direction d);
int	ft_get_building_indice(int board[6][6], int coord, enum e_Direction d);
int	ft_has_a_doublon(int board[6][6], int coord, enum e_Direction d);
