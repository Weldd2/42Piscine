#ifndef GLOBAL_H
# define GLOBAL_H

#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <libgen.h>
#include <stdio.h>

typedef struct 
{
	int	val;
	char	*str_val;
} s_couple;

#endif