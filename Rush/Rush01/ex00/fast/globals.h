/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   globals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 18:27:18 by amura             #+#    #+#             */
/*   Updated: 2023/08/20 22:21:20 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBALS_H
# define GLOBALS_H
# define PAIR_COUNT 9
# define MAX_COMBINATIONS 5
# define NUM_CELLS 4

enum	e_Direction {
	RIGHT,
	TOP,
	LEFT,
	BOTTOM
};

typedef struct s_Indices
{
	int	from;
	int	to;
}	t_Indices;

typedef struct s_Combination
{
	int	values[NUM_CELLS];
}	t_Combination;

extern int				g_solve_compteur;
extern int				g_num_combinations[PAIR_COUNT];
extern t_Indices		g_pairs[PAIR_COUNT];
extern t_Combination	g_possible_combinations[PAIR_COUNT][MAX_COMBINATIONS];

#endif