#include <unistd.h>

void print(char c)
{
	write(1, &c, 1);
}

void	rush(int largeur, int longueur)
{
	int	i;
	int	j;

	i = 0;
	while (i < longueur)
	{
		j = 0;
		while (j < largeur)
		{
			if ( (j == 0 && i == 0)
				|| (j == 0 && i == longueur-1)
				|| (j == largeur-1 && i == 0)
				|| (j == largeur-1 && i == longueur-1)
					)
			{
				print('0');
			}
			else 
			{
				print('-');
			}
			j++;
		}
		print('\n');
		i++;
	}
}

int	main(void)
{
	rush(5, 1);
}
