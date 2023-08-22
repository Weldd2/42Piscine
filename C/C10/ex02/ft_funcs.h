/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_funcs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 21:35:47 by amura             #+#    #+#             */
/*   Updated: 2023/08/22 23:01:58 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <libgen.h>

void	ft_putstr(const char *str, int sortie);
void	ft_print_error(char *file_path);
int		get_file_size(char *file_path);
void	print_file_sep_start(char *file_path);
