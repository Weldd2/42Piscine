#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <libgen.h>
#include <stdio.h>
#include "split.h"

typedef struct 
{
	char	*val;
	char	*str_val;
} s_couple;
