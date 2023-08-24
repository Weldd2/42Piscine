/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 16:27:11 by amura             #+#    #+#             */
/*   Updated: 2023/08/24 18:26:38 by amura            ###   ########.fr       */
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
void	ft_print_full_error(void);
void	print_x_space(int x);
void	ft_convert_base(int nb, char *base, int base_length, int start_value);
