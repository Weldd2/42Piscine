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
;
int	main() {
	// Ajoutez des tests ici si nécessaire
	char	str[15] = "abcDde\n";

	// ft_str_is_alpha(str);
	// ft_str_is_numeric(str);
	// ft_str_is_lowercase(str);
	// ft_str_is_uppercase(str);
	// ft_str_is_printable(str);
	// ft_strupcase(str);
	// ft_strlowcase(str);

	printf("%s", str);
	return 0;
}
