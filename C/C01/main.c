#include <stdio.h>

void	ft_ultimate_ft(int *********nbr);
void	ft_swap(int *a, int *b);
void	ft_div_mod(int a, int b, int *div, int *mod);
void	ft_ft(int *nbr);
void	ft_ultimate_div_mod(int *a, int *b);
void	ft_putstr(char *str);
int	ft_strlen(char *str);
void	ft_rev_int_tab(int *tab, int size);
void	ft_sort_int_tab(int *tab, int size);

int	main(void) {
	// Ajoutez des tests ici si nécessaire
	int	str[5] = {1, 5, 3, 9, 4};

	// ft_rev_int_tab(str, 5);
	ft_sort_int_tab(str, 3);

	int	i;
	
	i = 0;
	while (i < str[i])
	{
		printf("%d ", str[i]);
		i++;
	}
	return 0;
}
