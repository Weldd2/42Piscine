/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_funcs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 21:35:47 by amura             #+#    #+#             */
/*   Updated: 2023/08/23 16:22:48 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <libgen.h>

int		get_file_size(int file);
int		get_option(char **argv, char char_to_detect, int argc, int *index);
int		ft_get_nbr(char *str, int result);
void	ft_putstr(const char *str, int sortie);
