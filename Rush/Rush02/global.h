/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 00:00:00 by amura             #+#    #+#             */
/*   Updated: 2023/08/27 00:01:42 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_H
# define GLOBAL_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_couple
{
	long long	val;
	char		*str_val;
}				t_couple;

long long		ft_atoi(char *str, long long result);
int				ft_strlen(char *str);
char			*ft_strjoin(char *s1, char *s2);
void			parse_line(char *line, t_couple *couple);
t_couple		*read_dict(char *file_name);
void			ft_putstr(char *str);
void			print_from_dict(long long num, t_couple *couple_array);
void			print_unit(long long num, t_couple *couple_array);
void			print_tens(long long num, t_couple *couple_array);
void			print_hundreds(long long num, t_couple *couple_array);
void			print_number(long long num, t_couple *couple_array);
char			**ft_split(char *str, char sep);

#endif
