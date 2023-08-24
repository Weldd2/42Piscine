/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_size_and_operations.h                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 16:27:20 by amura             #+#    #+#             */
/*   Updated: 2023/08/24 18:26:45 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <libgen.h>
#include "output.h"
#include "string_memory_manipulation.h"

int		get_file_size(char *file_name, int *error);
int		get_total_size(char **argv, int argc, int opt_index);
int		get_option(char **argv, char char_to_detect, int *index);
int		fill_tab_loop_end(int bytes_read, int i, int *file);
char	*fill_tab(int argc, char **argv, char *tab);
