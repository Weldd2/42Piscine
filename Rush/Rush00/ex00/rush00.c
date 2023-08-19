#include <unistd.h>

void print(char c)
{
	write(1, &c, 1);
}

void	rush(int largeur, int longueur)
{
	int	i;
	int	j;

	i = 1;
	while (i <= longueur)
	{
		j = 1;
		while (j <= largeur)
		{
			if ( ( (i == 1 && j == 1) || (i == longueur && j == largeur) ) && (i != longueur && i != 1) )
			{
				print('A');
			}
			else if ( (i == 1 || i == longueur) && j == 1)
			{
				print('C');
			}
			else if (i == 1 || i == longueur || j == 1 || j == largeur)
			{
				print('B');
			}
			else
			{
				print(' ');
			}
			j++;
		}
		print('\n');
		i++;
	}
}

int	main(void)
{
	rush(1, 3);
}
