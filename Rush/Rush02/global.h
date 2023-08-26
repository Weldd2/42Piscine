#ifndef GLOBAL_H
# define GLOBAL_H

typedef struct 
{
	long long	val;
	char	*str_val;
} s_couple;

# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <errno.h>
# include <libgen.h>
# include <stdio.h>

int	ft_atoi(char *str, long long result);
s_couple	*read_dict(char *dict_name);
int	get_place(long long nb, s_couple *couple_array);
void	write_from_couple_array(long long nb, s_couple *couple_array);
long long	get_ite(long long nb);
void	read_0_to_XB(long long nb, s_couple *couple_array, long long ite);
char	**ft_split(char *str, char sep);


#endif