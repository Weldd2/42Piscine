/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do-op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 12:26:14 by amura             #+#    #+#             */
/*   Updated: 2023/08/30 13:34:36 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	addition(int a, int b);
int	soustraction(int nb1, int nb2);
int	multiplication(int nb1, int nb2);
int	division(int nb1, int nb2);
int	modulo(int nb1, int nb2);

char	get_ope(char *ope)
{
	int	len;

	len = 0;
	while (ope[len])
		len++;
	if (len != 1)
		return ('\0');
	return (ope[0]);
}

int	is_valid_nb(char *nb, int *n)
{
	int	s;
	int	r;
	int	i;

	i = -1;
	s = 1;
	r = 0;
	if (nb[i + 1] == '-')
	{
		s = -s;
		i++;
	}
	while (nb[++i])
	{
		if (!(nb[i] <= '9' && nb[i] >= '0'))
			return (0);
		r *= 10;
		r += (nb[i] - '0');
	}
	*n = r * s;
	return (1);
}

int main(int argc, char *argv[])
{
	char	ope;
	int		nb1;
	int		nb2;

	if (argc != 4)
		return (0);
	ope = get_ope(argv[2]);
	if (is_valid_nb(argv[1], &nb1) && is_valid_nb(argv[3], &nb2))
	{
		if (ope == '+')
			return (addition(nb1, nb2));
		if (ope == '-')
			return (soustraction(nb1, nb2));
		if (ope == '*')
			return (multiplication(nb1, nb2));
		if (ope == '/')
			return (division(nb1, nb2));
		if (ope == '%')
			return (modulo(nb1, nb2));
	}
	return 0;
}
