/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 21:36:00 by amura             #+#    #+#             */
/*   Updated: 2023/08/22 22:12:36 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <libgen.h>

int		get_option(char **argv, char char_to_detect, int argc, int *arg_index);
int		ft_get_nbr(char *str, int result);
int		ft_print_eof_c(char **file_path, int argc, int bytes_read, int arg_i);
void	print_x_last_bytes(int file, int file_size, int bytes_read);