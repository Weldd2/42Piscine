/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 16:22:42 by amura             #+#    #+#             */
/*   Updated: 2023/08/20 20:52:41 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		main(int argc, char **argv);

void	ft_fill_array_with_digits(int *result, char *str);

int		ft_count_valid_digits(char *str);

int		*ft_get_params(char *str);

int		ft_is_finished(int board[6][6]);