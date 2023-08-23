/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 21:36:00 by amura             #+#    #+#             */
/*   Updated: 2023/08/23 15:44:52 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <libgen.h>

int		tail_loop(char **argv, int argc, int opt_index, int bytes_read);
void	print_eof(char *file_name, int bytes_reads);
void	print_x_last_bytes(int file, int file_size, int bytes_read);