/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_memory_manipulation.h                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 16:27:02 by amura             #+#    #+#             */
/*   Updated: 2023/08/24 18:26:26 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <libgen.h>
#include "output.h"

char	*ft_strncat(char *dest, char *src, unsigned int nb);
void	*ft_memset(void *b, int c, size_t len);
void	print_offset(int place);
void	print_ascii(char *tab, int place);
void	print_hexa(char *tab, int place, int tab_length);
