char *ft_strupcase(char *str)
{       
        int     i;

        i = 0;
        while (str[i])
        {
                str[i] = str[i] - 32;
                i++;
        }

	return str;
}
