#include <stdio.h>
#include <stdlib.h>

enum e_Direction {
    RIGHT,
    TOP,
    LEFT,
    BOTTOM
};

int solve_compteur = 0;

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
	return (0);
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

int	has_a_doublon(int board[6][6], int coord, enum e_Direction d)
{
	for (int x = 1; x <= 4; x++)
	{
		for (int z = x + 1; z <= 4; z++)	
		{
			if (d == RIGHT || d == LEFT)
			{
				if (board[coord][x] == board[coord][z])
					return (0);
				
			}
			else if (d == TOP || d == BOTTOM)
			{
				if (board[x][coord] == board[z][coord])
					return (0);
			}
		}
	}
	return (1);
}

int	is_indice_valid(int board[6][6], int coord, enum e_Direction d)
{
	int	compteur;
	int	max;

	compteur = 1;
	if (d == LEFT)
		max = board[coord][1];
	if (d == RIGHT)
		max = board[coord][4];
	if (d == TOP)
		max = board[1][coord];
	if (d == BOTTOM)
		max = board[4][coord];
	for (int x = 1; x < 4; x++)
	{
		if ( d == LEFT && (max <  board[coord][x + 1]))
		{
			max = board[coord][x + 1];
			compteur++;
		}
		else if ( d == RIGHT && (max < board[coord][4 - x]))
		{
			max = board[coord][4 - x];
			compteur++;
		}
		else if ( d == BOTTOM && (max < board[4 - x][coord]))
		{
			max = board[4 - x][coord];
			compteur++;
		}
		else if ( d == TOP && (max < board[x + 1][coord]))
		{
			max = board[x + 1][coord];
			compteur++;
		}
	}
	if (compteur != get_building_indice(board, coord, d))
		return (0);
	return (1);
}

int	is_column_valid(int board[6][6], int x)
{
	if (!is_line_empty(board, x, TOP))
	{
		if (!has_a_doublon(board, x, TOP))
			return (0);
		if (!is_indice_valid(board, x, TOP))
			return (0);
		if (!is_indice_valid(board, x, BOTTOM))
			return (0);
	}
	return (1);
}

int	is_line_valid(int board[6][6], int y)
{
	if (!is_line_empty(board, y, LEFT))
	{
		if (!has_a_doublon(board, y, LEFT))
			return (0);
		if (!is_indice_valid(board, y, LEFT))
			return (0);
		if (!is_indice_valid(board, y, RIGHT))
			return (0);
	}
	return (1);
}

int	is_board_valid(int board[6][6])
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

int	solve(int board[6][6], int row, int col) {
    
	if (row == 5) // If we have finished the last row
		return is_board_valid(board);

	if (board[row][col] != 0) { // If the cell is pre-filled, move to the next cell
		if (col == 4) { // If it's the last column, move to the next row
		if (solve(board, row + 1, 1))
			return 1;
		} else { // Move to the next column
		if (solve(board, row, col + 1))
			return 1;
		}
		return 0;
	}

	for (int num = 1; num <= 4; num++) {
		board[row][col] = num;
		if (is_board_valid(board)) { // If the current board state is valid
			if (col == 4) { // If it's the last column, move to the next row
				if (solve(board, row + 1, 1))
					return 1;
			} else { // Move to the next column
				if (solve(board, row, col + 1))
				return 1;
			}
		}
		solve_compteur++;
		board[row][col] = 0; // Backtrack
	}

	return 0; // No valid number can be placed in this cell
}

int main(int argc, char **argv) {

	if (argc != 2)
		return (0);
	int board[6][6];
	createBoard(board);
	int *arg_tab = get_params(argv[1]);
	initBoard(board, arg_tab);
	free(arg_tab);
	// board[1][1] = 1;
	// board[1][2] = 2;
	// board[1][3] = 4;
	// board[1][4] = 3;
	// board[2][1] = 4;
	// board[2][2] = 3;
	// board[2][3] = 1;
	// board[2][4] = 2;
	// board[3][1] = 2;
	// board[3][2] = 4;
	// board[3][3] = 3;
	// board[3][4] = 1;
	// board[4][1] = 3;
	// board[4][2] = 1;
	// board[4][3] = 2;
	// board[4][4] = 4;
	optimizer(board);
	solve(board, 1, 1);
	print_board_with_indices(board);
	printf("%d\n", solve_compteur);
	// print_board(board);

	// printf("\n%d\n", is_line_empty(board, 2, TOP));
	// printf("\n%d\n", is_board_finished(board));

	return (0);
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