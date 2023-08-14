#include <stdio.h>
char	*ft_strcpy(char *dest, char *src);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
int	ft_str_is_alpha(char *str);
int	ft_str_is_numeric(char *str);
int	ft_str_is_lowercase(char *str);
int	ft_str_is_uppercase(char *str);
int	ft_str_is_printable(char *str);
char	*ft_strlowcase(char *str);
char	*ft_strcapitalize(char *str);
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);

int	main() {
	// Ajoutez des tests ici si nécessaire
	char	src[15] = "abcdesaddsa";
	char	dest[15] = "e";

	// ft_str_is_alpha(str);
	// ft_str_is_numeric(str);
	// ft_str_is_lowercase(str);
	// ft_str_is_uppercase(str);
	// ft_str_is_printable(str);
	// ft_strupcase(str);
	// ft_strlowcase(str);
	// ft_strcapitalize(str);
	ft_strlcpy(dest, src, 50);

	printf("%s\n", src);
	printf("%s\n", dest);
	return 0;
}
