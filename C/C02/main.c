#include <stdio.h>
char	*ft_strcpy(char *dest, char *src);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
int	ft_str_is_alpha(char *str);
int	ft_str_is_numeric(char *str);
int	ft_str_is_lowercase(char *str);
int	ft_str_is_uppercase(char *str);
int	ft_str_is_printable(char *str);
char	*ft_strupcase(char *str);
char	*ft_strlowcase(char *str);
char	*ft_strcapitalize(char *str);
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
void ft_putstr_non_printable(char *str);

int	main() {
	// Ajoutez des tests ici si nécessaire
	char	str[50] = "Coucou\ntu vas bien ?";

	ft_putstr_non_printable(str);
	printf("%s\n", str);
	return 0;
}
