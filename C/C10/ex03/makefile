all : main

main : main.o output.o file_size_and_operations.o string_memory_manipulation.o
	cc -Wall -Wextra -Werror main.o output.o file_size_and_operations.o string_memory_manipulation.o -o ft_hexdump

main.o : main.c
	cc -Wall -Wextra -Werror -c main.c

output.o : output.c
	cc -Wall -Wextra -Werror -c output.c

file_size_and_operations.o : file_size_and_operations.c
	cc -Wall -Wextra -Werror -c file_size_and_operations.c

string_memory_manipulation.o : string_memory_manipulation.c
	cc -Wall -Wextra -Werror -c string_memory_manipulation.c

clean :
	rm -f main.o output.o file_size_and_operations.o string_memory_manipulation.o

fclean : clean
	rm -f ft_hexdump

re : fclean all
