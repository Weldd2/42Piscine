#include <stdio.h>
#include <stdlib.h>

enum e_Direction {
    RIGHT,
    TOP,
    LEFT,
    BOTTOM
};

int	is_line_empty(int board[6][6], int coord, enum e_Direction d)
{
	for (int i = 1; i <= 4; i++)
	{
		if (d == RIGHT || d == LEFT)
			if (board[coord][i] == 0)
				return (1);
		if (d == TOP || d == BOTTOM)
			if (board[i][coord] == 0)
				return (1);
		
	}
}

void 	createBoard(int board[6][6]) {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			board[i][j] = 0;
		}
	}
}

int*	get_params(char *str) {
	if (!str) {
		return NULL;
	}

	int count = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] >= '1' && str[i] <= '4') {
		count++;
		}
	}

	int *result = (int *)malloc(count * sizeof(int));
	if (!result) {
		return NULL; // Si l'allocation de mémoire échoue
	}

	int j = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] >= '1' && str[i] <= '4') {
		result[j++] = str[i] - '0'; // Convertit le caractère en entier
		}
	}

	return result;
}

void	print_board_with_indices(int board[6][6]) {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			printf("%d ", board[i][j]);
		}
    		printf("\n");
  	}
}

void	print_board(int board[6][6]) {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			if (!(i == 0 || j == 0 || i == 5 || j == 5))
				printf("%d", board[i][j]);
			if (i != 0 && i != 5 && j < 4 && j != 0)
				printf(" ");
		}
		if (i != 0 && i != 5)
    			printf("\n");
  	}
}

void	initBoard(int board[6][6], int *params) {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (i == 0 && j > 0 && j < 5) board[i][j] = params[i + j - 1];
            else if (i == 5 && j > 0 && j < 5) board[i][j] = params[3 + j];
            else if (j == 0 && i > 0 && i < 5) board[i][j] = params[7 + i];
            else if (j == 5 && i > 0 && i < 5) board[i][j] = params[11 + i];
            else board[i][j] = 0;
        }
    }
}

int	get_building_indice(int board[6][6], int coord, enum e_Direction d)
{
	if (d == LEFT)
		return (board[coord][0]);
	if (d == RIGHT)
		return (board[coord][5]);
	if (d == TOP)
		return (board[0][coord]);
	if (d == BOTTOM)
		return (board[5][coord]);
}

int	is_column_valid_indice_top(int board[6][6], int x)
{
	int	compteur;
	int	max;

	max = board[1][x];
	compteur = 1;
	if (is_line_empty(board, x, TOP))
		return (1);
	//check les indices haut en bas
	for (int y = 1; y < 4; y++)
		// check les indices
		if ( max <  board[y + 1][x])
		{
			max = board[y + 1][x];
			compteur++;
		}
	if (compteur != get_building_indice(board, x, TOP))
		return (0);
	return (1);
}

int	is_column_valid_indice_bottom(int board[6][6], int x)
{
	int	compteur;
	int	max;

	compteur = 1;
	max = board[4][x];
	if (is_line_empty(board, x, BOTTOM))
		return (1);
	//check les indices bas en haut
	for (int y = 4; y > 1; y--)
		// check les indices
		if ( max <  board[y - 1][x])
		{
			max = board[y - 1][x];
			compteur++;
		}
	if (compteur != get_building_indice(board, x, BOTTOM))
		return (0);
	return (1);
}

int	is_line_valid_indice_right(int board[6][6], int y)
{
	int	compteur;
	int	max;

	compteur = 1;
	if (is_line_empty(board, y, RIGHT))
		return (1);
	max = board[y][4];
	//check les indices haut en bas
	for (int x = 4; x > 1; x--)
		// check les indices
		if ( max <  board[y][x - 1])
		{
			max = board[y][x - 1];
			compteur++;
		}
	if (compteur != get_building_indice(board, y, RIGHT))
		return (0);
	return (1);
}

int	is_line_valid_indice_left(int board[6][6], int y)
{
	int	compteur;
	int	max;

	compteur = 1;
	max = board[y][1];
	if (is_line_empty(board, y, LEFT))
		return (1);
	//check les indices haut en bas
	for (int x = 1; x < 4; x++)
	{
		// check les indices
		if ( max <  board[y][x + 1])
		{
			max = board[y][x + 1];
			compteur++;
		}
	}
	if (compteur != get_building_indice(board, y, LEFT))
		return (0);
	return (1);
}

int	has_a_doublon(int board[6][6], int coord, enum e_Direction d)
{
	for (int x = 1; x <= 4; x++)
	{
		for (int z = x + 1; z < 4; z++)	
		{
			if (d == RIGHT || d == LEFT)
				if (board[coord][x] != 0)
					if ((board[coord][x] == board[coord][z]) && board[coord][z] != 0)
						return (0);
				else
					break;
			if (d == TOP || d == BOTTOM)
				if (board[x][coord] != 0)
					if ((board[x][coord] == board[z][coord]) && board[z][coord] != 0)
						return (0);
				else
					break;
		}
	}
	return (1);
}

int	is_column_valid(int board[6][6], int x)
{
	if (!has_a_doublon(board, x, TOP))
		return (0);
	if (!is_column_valid_indice_top(board, x))
		return (0);
	if (!is_column_valid_indice_bottom(board, x))
		return (0);
	return (1);
}

int	is_line_valid(int board[6][6], int y)
{
	if (!has_a_doublon(board, y, RIGHT))
		return (0);
	if (!is_line_valid_indice_left(board, y))
		return (0);
	if (!is_line_valid_indice_right(board, y))
		return (0);
	return (1);
}

int	is_board_finished(int board[6][6])
{
	for (int y = 1; y <= 4; y++) {
		if (!is_line_valid(board, y))
			return (0);
		for (int x = 1; x <= 4; x++)
		{
			if (!is_column_valid(board, x))
				return (0);
		}
	}
	return (1);
}

int	fill_board(int board[6][6], int starting_coord, enum e_Direction d)
{
	if (d == RIGHT)
		for (int i = 1; i <= 4; i++)
			board[starting_coord][i] = 5 - i;
	if (d == LEFT)
		for (int i = 1; i <= 4; i++)
			board[starting_coord][i] = i;
	if (d == TOP)
		for (int i = 1; i <= 4; i++)
			board[i][starting_coord] = i;
	if (d == BOTTOM)
		for (int i = 1; i <= 4; i++)
			board[i][starting_coord] = 5 - i;
}

int	optimizer(int board[6][6])
{
	for (int i = 1; i <= 4; i++)
	{
		if (get_building_indice(board, i, RIGHT) == 4)
			fill_board(board, i, RIGHT);
		if (get_building_indice(board, i, LEFT) == 4)
			fill_board(board, i, LEFT);
		if (get_building_indice(board, i, TOP) == 4)
			fill_board(board, i, TOP);
		if (get_building_indice(board, i, BOTTOM) == 4)
			fill_board(board, i, BOTTOM);
		if (get_building_indice(board, i, RIGHT) == 1)
			board[i][4] = 4;
		if (get_building_indice(board, i, LEFT) == 1)
			board[i][1] = 4;
		if (get_building_indice(board, i, TOP) == 1)
			board[1][i] = 4;
		if (get_building_indice(board, i, BOTTOM) == 1)
			board[4][i] = 4;
	}
}

int main(int argc, char **argv) {

	if (argc != 2)
		return (0);
	int board[6][6];
	createBoard(board);
	int *arg_tab = get_params(argv[1]);
	initBoard(board, arg_tab);
	free(arg_tab);
	board[1][1] = 1;
	board[1][2] = 2;
	board[1][3] = 4;
	board[1][4] = 3;
	board[2][1] = 4;
	board[2][2] = 3;
	board[2][3] = 1;
	board[2][4] = 2;
	board[3][1] = 2;
	board[3][2] = 4;
	board[3][3] = 3;
	board[3][4] = 1;
	board[4][1] = 3;
	board[4][2] = 1;
	board[4][3] = 2;
	board[4][4] = 4;
	optimizer(board);
	print_board_with_indices(board);
	// print_board(board);

	printf("\n%d\n", is_board_finished(board));

	return 0;
}



/*
void initBoard(int board[6][6], int *params) {
	int	top = 0;
	int	left = 8;
	int	bottom = 4;
	int	right = 12;
	
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			if (i == 0 && (j < 5 && j > 0))
			{
				board[i][j] = params[top];
				top++;
			}
			else if (i == 5 && (j < 5 && j > 0))
			{
				board[i][j] = params[bottom];
				bottom++;
			}
			else if (j == 5 && (i < 5 && i > 0))
			{
				board[i][j] = params[right];
				right++;
			}
			else if (j == 0 && (i < 5 && i > 0))
			{
				board[i][j] = params[left];
				left++;
			}
			else
				board[i][j] = 0;
		}
	}
}
*/