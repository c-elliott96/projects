// Name: Christian Elliott
// File: source.cpp

#include <iostream>
#include <iomanip>

//Constants
const char VERS[] = "0.1";
const int BOARD_SIZE = 8;
const int BLACK = 0;
const int WHITE = 1;
const char BLACK_PIECE = '@';
const char WHITE_PIECE = 'O';


//Typedefs
typedef char Board[BOARD_SIZE][BOARD_SIZE];


//Prototypes
void help();
void play();
void init(Board board);
void draw(Board board);
int get_row(char[]);
int get_col(char[]);
bool invalid_input(Board board, char[]);
void get_valid_positions(bool turn, Board board,
	int valid_row[], int valid_col[], int& valid_len);
bool is_valid_position_at(int turn, Board board, int row, int col);
bool is_valid_position_in_NORTH_direction(int turn, Board board,
	int row, int col);
bool is_valid_position_in_SOUTH_direction(int turn, Board board,
	int row, int col);
bool is_valid_position_in_WEST_direction(int turn, Board board,
	int row, int col);
bool is_valid_position_in_EAST_direction(int turn, Board board,
	int row, int col);
bool is_valid_position_in_NORTHEAST_direction(int turn, Board board,
	int row, int col);
bool is_valid_position_in_SOUTHEAST_direction(int turn, Board board,
	int row, int col);
bool is_valid_position_in_NORTHWEST_direction(int turn, Board board,
	int row, int col);
bool is_valid_position_in_SOUTHWEST_direction(int turn, Board board,
	int row, int col);
void swap(int turn, Board board, int row, int col);
bool check_ended(Board board);
void find_winner(Board board);

//--------------------------------------------------------------------
// main
//--------------------------------------------------------------------
int main()
{
	//test_draw();

	bool quit = false;
	while (!quit)
	{
		std::cout << "Welcome to Super Othello Version 0.1\n"
			<< "by John Doe\n\n"
			<< "[?]   Help\n"
			<< "[P/p] Play a new game\n"
			<< "[L/l] Load a previous game\n"
			<< "[S/s] Setup the board\n"
			<< "[Q/q] Quit\n"
			<< "Enter option: ";

		char x;
		std::cin >> x;
		std::cout << std::endl;

		switch (x)
		{
		case '?': help(); break;

		case 'P':
		case 'p': play(); break;

		case 'L':
		case 'l':
			std::cout << "\n*** L/l: TO BE IMPLEMENTED ***\n\n";
			break;

		case 'S':
		case 's':
			std::cout << "\n*** S/s: TO BE IMPLEMENTED ***\n\n";
			break;

		case 'Q':
		case 'q':
			quit = true;
			std::cout << "\nThanks for playing Super Othello Version 0.1\n";
			break;
		}
	}

	return 0;
}

//===================================================================
//functions
//===================================================================
void help()
{
	std::cout << "\nThe official rules can be found at"
		<< "\nhttp://en.wikipedia.org/wiki/Reversi"
		<< "\n\nThe Othello board is set up in the following manner"
		<< "\n\n  ABCDEFGH"
		<< "\n +--------+"
		<< "\n1|        |1"
		<< "\n2|        |2"
		<< "\n3|        |3"
		<< "\n4|   O@   |4"
		<< "\n5|   @O   |5"
		<< "\n6|        |6"
		<< "\n7|        |7"
		<< "\n8|        |8"
		<< "\n +--------+"
		<< "\n  ABCDEFGH"
		<< "\n\nBLACK plays @ and WHITE plays O. Players take turn in entering"
		<< "\nmoves. The first player to enter a move is BLACK. to place a @"
		<< "\nat row 6 and column E, BLACK enters 6E. The result of the move"
		<< "\nis"
		<< "\n\n  ABCDEFGH"
		<< "\n +--------+"
		<< "\n1|        |1"
		<< "\n2|        |2"
		<< "\n3|        |3"
		<< "\n4|   O@   |4"
		<< "\n5|   @@   |5"
		<< "\n6|    @   |6"
		<< "\n7|        |7"
		<< "\n8|        |8"
		<< "\n +--------+"
		<< "\n  ABCDEFGH"
		<< "\n\nNote that the WHITE piece at E5 is now a BLACK piece.\n"
		<< std::endl;
}


void play()
{
	Board board;
	init(board);
	bool turn = WHITE;
	bool invalid = false;
	bool gameover = false;
	
	// while loop to take in players' inputs
	while (1)
	{
		if (!invalid)
		{
			draw(board);
			turn = (turn ? BLACK : WHITE);
		}
		invalid = false;

		int valid_row[100];
		int valid_col[100];
		int valid_len = 0;
		get_valid_positions(turn, board, valid_row, valid_col, valid_len);

		if (valid_len == 0)
		{
			gameover = check_ended(board);

			if (!gameover)
			{
				std::cout << (turn ? "WHITE " : "BLACK ") << "has no available moves"
					<< ", their turn is skipped\n";
				continue;
			}
			find_winner(board);
			break;
		}

		std::cout << (turn ? "WHITE's " : "BLACK's ")
			<< "turn: ";
		char input[100] = { ' ' };
		std::cin >> input;
		if (input[0] == 'q' && input[1] == '\0')
		{
			std::cout << '\n';
			break;
		}

		if (invalid_input(board, input))
		{
			std::cout << "Invalid position\n";
			invalid = true;
			continue;
		}

		// determine if move is good
		for (int i = 0; i < valid_len; ++i)
		{
			if (get_row(input) == valid_row[i] && get_col(input) == valid_col[i])
			{
				invalid = false;
				swap(turn, board, get_row(input), get_col(input));
				board[get_row(input)][get_col(input)] = (turn ? WHITE_PIECE : BLACK_PIECE);

				break;
			}
			else
				invalid = true;
		}

		if (invalid)
		{
			std::cout << "Invalid position\n";
			continue;
		}
	}
}

// initialize board to ' ';
void init(Board board)
{
	for (int row = 0; row < BOARD_SIZE; ++row)
	{
		for (int col = 0; col < BOARD_SIZE; ++col)
		{
			board[row][col] = ' ';
		}
	}
	board[BOARD_SIZE / 2 - 1][BOARD_SIZE / 2 - 1] = WHITE_PIECE;
	board[BOARD_SIZE / 2 - 1][BOARD_SIZE / 2] = BLACK_PIECE;
	board[BOARD_SIZE / 2][BOARD_SIZE / 2 - 1] = BLACK_PIECE;
	board[BOARD_SIZE / 2][BOARD_SIZE / 2] = WHITE_PIECE;
}


//print board
void draw(Board board)
{
	std::cout << "\n" << (BOARD_SIZE > 9 ? "   " : "  ");
	for (int letter = 0; letter < BOARD_SIZE; ++letter)
		std::cout << char(letter + 'A');
	std::cout << "  \n" << (BOARD_SIZE > 9 ? "  +" : " +");
	for (int dash = 0; dash < BOARD_SIZE; ++dash)
		std::cout << '-';
	std::cout << "+ \n";

	for (int row = 0; row < BOARD_SIZE; ++row)
	{
		if (BOARD_SIZE > 9 && row < 9) std::cout << ' ';
		std::cout << (row + 1) << '|';
		for (int col = 0; col < BOARD_SIZE; ++col)
		{
			std::cout << board[row][col];
		}
		std::cout << '|' << (row + 1) << '\n';
	}

	std::cout << (BOARD_SIZE > 9 ? "  " : " ") << "+";
	for (int dash = 0; dash < BOARD_SIZE; ++dash)
		std::cout << '-';
	std::cout << "+ \n" << (BOARD_SIZE > 9 ? "   " : "  ");
	for (int letter = 0; letter < BOARD_SIZE; ++letter)
		std::cout << char(letter + 'A');
	std::cout << "  \n\n";
}

// put row into variable from input
int get_row(char input[])
{
	return (input[1] - '1');
}

// put col into variable from input
int get_col(char input[])
{
	return (input[0] - 'A');
}

// check if input is good
bool invalid_input(Board board, char input[])
{
	return (input[0] > char((BOARD_SIZE - 1) + 'A')
		|| (input[1] < '1' || input[1] > char(BOARD_SIZE + '1'))
		|| board[get_row(input)][get_col(input)] != ' ');
}

// find what positions on board are available
void get_valid_positions(bool turn, Board board,
	int valid_row[], int valid_col[], int& valid_len)
{
	for (int row = 0; row < BOARD_SIZE; ++row)
	{
		for (int col = 0; col < BOARD_SIZE; ++col)
		{
			if (is_valid_position_at(turn, board, row, col))
			{
				valid_row[valid_len] = row;
				valid_col[valid_len] = col;
				++valid_len;
			}
		}
	}
}

// determine what row or diag has a playable space, if any
bool is_valid_position_at(int turn, Board board, int row, int col)
{
	if (is_valid_position_in_NORTH_direction(turn, board, row, col) ||
		is_valid_position_in_SOUTH_direction(turn, board, row, col) ||
		is_valid_position_in_WEST_direction(turn, board, row, col) ||
		is_valid_position_in_EAST_direction(turn, board, row, col) ||
		is_valid_position_in_NORTHEAST_direction(turn, board, row, col) ||
		is_valid_position_in_SOUTHEAST_direction(turn, board, row, col) ||
		is_valid_position_in_NORTHWEST_direction(turn, board, row, col) ||
		is_valid_position_in_SOUTHWEST_direction(turn, board, row, col))
	{
		return true;
	}
	return false;
}

//====================================================================
// the functions check the individual directions (NSEW and NE, NW, 
// SW and SE
//====================================================================
bool is_valid_position_in_SOUTH_direction(int turn, Board board,
	int row, int col)
{
	if (turn == WHITE && board[row + 1][col] == BLACK_PIECE &&
		board[row][col] == ' ')
	{
		for (int i = row + 1; i <= BOARD_SIZE; ++i)
		{
			if (board[i][col] == WHITE_PIECE && board[i - 1][col] != ' ')
			{
				return true;
			}
		}
		return false;
	}
	else if (turn == BLACK && board[row + 1][col] == WHITE_PIECE &&
		board[row][col] == ' ')
	{
		for (int i = row + 1; i <= BOARD_SIZE; ++i)
		{

			if (board[i][col] == BLACK_PIECE && board[i - 1][col] != ' ')
			{
				return true;
			}
		}
		return false;
	}
	return false;
}


bool is_valid_position_in_NORTH_direction(int turn, Board board,
	int row, int col)
{
	if (turn == WHITE && board[row - 1][col] == BLACK_PIECE &&
		board[row][col] == ' ')
	{
		for (int i = row - 1; i >= 0; --i)
		{
			if (board[i][col] == WHITE_PIECE && board[i + 1][col] != ' ')
			{
				return true;
			}
		}
		return false;
	}
	else if (turn == BLACK && board[row - 1][col] == WHITE_PIECE &&
		board[row][col] == ' ')
	{
		for (int i = row - 1; i >= 0; --i)
		{
			if (board[i][col] == BLACK_PIECE && board[i + 1][col] != ' ')
			{
				return true;
			}
		}
		return false;
	}
	return false;
}


bool is_valid_position_in_WEST_direction(int turn, Board board,
	int row, int col)
{
	if (turn == WHITE && board[row][col - 1] == BLACK_PIECE &&
		board[row][col] == ' ')
	{
		for (int i = col - 1; i >= 0; --i)
		{
			if (board[row][i] == WHITE_PIECE && board[row][i + 1] != ' ')
			{
				return true;
			}
		}
		return false;
	}
	else if (turn == BLACK && board[row][col - 1] == WHITE_PIECE &&
		board[row][col] == ' ')
	{
		for (int i = col - 1; i >= 0; --i)
		{
			if (board[row][i] == BLACK_PIECE && board[row][i + 1] != ' ')
			{
				return true;
			}
		}
		return false;
	}
	return false;
}


bool is_valid_position_in_EAST_direction(int turn, Board board,
	int row, int col)
{
	if (turn == WHITE && board[row][col + 1] == BLACK_PIECE &&
		board[row][col] == ' ')
	{
		for (int i = col + 1; i <= BOARD_SIZE; ++i)
		{
			if (board[row][i] == WHITE_PIECE && board[row][i - 1] != ' ')
			{
				return true;
			}
		}
		return false;
	}
	else if (turn == BLACK && board[row][col + 1] == WHITE_PIECE &&
		board[row][col] == ' ')
	{
		for (int i = col + 1; i <= BOARD_SIZE; ++i)
		{
			if (board[row][i] == BLACK_PIECE && board[row][i - 1] != ' ')
			{
				return true;
			}
		}
		return false;
	}
	return false;
}


bool is_valid_position_in_NORTHEAST_direction(int turn, Board board,
	int row, int col)
{
	if (turn == WHITE && board[row - 1][col + 1] == BLACK_PIECE &&
		board[row][col] == ' ')
	{
		int i = row - 1, j = col + 1;
		while (i >= 0 && j <= BOARD_SIZE)
		{
			if (board[i][j] == WHITE_PIECE && board[i + 1][j - 1] != ' ')
			{
				return true;
			}
			--i;
			++j;
		}

		return false;
	}
	else if (turn == BLACK && board[row - 1][col + 1] == WHITE_PIECE &&
		board[row][col] == ' ')
	{
		int i = row - 1, j = col + 1;
		while (i >= 0 && j <= BOARD_SIZE)
		{
			if (board[i][j] == BLACK_PIECE && board[i + 1][j - 1] != ' ')
			{
				return true;
			}
			--i;
			++j;
		}

		return false;
	}
	return false;
}


bool is_valid_position_in_SOUTHEAST_direction(int turn, Board board,
	int row, int col)
{
	if (turn == WHITE && board[row + 1][col + 1] == BLACK_PIECE &&
		board[row][col] == ' ')
	{
		int i = row + 1, j = col + 1;
		while (i <= BOARD_SIZE && j <= BOARD_SIZE)
		{
			if (board[i][j] == WHITE_PIECE && board[i - 1][j - 1] != ' ')
			{
				return true;
			}
			++i;
			++j;
		}

		return false;
	}
	else if (turn == BLACK && board[row + 1][col + 1] == WHITE_PIECE &&
		board[row][col] == ' ')
	{
		int i = row + 1, j = col + 1;
		while (i <= BOARD_SIZE && j <= BOARD_SIZE)
		{
			if (board[i][j] == BLACK_PIECE && board[i - 1][j - 1] != ' ')
			{
				return true;
			}
			++i;
			++j;
		}
		return false;
	}
	return false;
}


bool is_valid_position_in_NORTHWEST_direction(int turn, Board board,
	int row, int col)
{
	if (turn == WHITE && board[row - 1][col - 1] == BLACK_PIECE &&
		board[row][col] == ' ')
	{
		int i = row - 1, j = col - 1;
		while (i >= 0 && j >= 0)
		{
			if (board[i][j] == WHITE_PIECE && board[i + 1][j + 1] != ' ')
			{
				return true;
			}
			--i;
			--j;
		}
		return false;
	}
	else if (turn == BLACK && board[row - 1][col - 1] == WHITE_PIECE &&
		board[row][col] == ' ')
	{
		int i = row - 1, j = col - 1;
		while (i >= 0 && j >= 0)
		{
			if (board[i][j] == BLACK_PIECE && board[i + 1][j + 1] != ' ')
			{
				return true;
			}
			--i;
			--j;
		}
		return false;
	}
	return false;
}


bool is_valid_position_in_SOUTHWEST_direction(int turn, Board board,
	int row, int col)
{
	if (turn == WHITE && board[row + 1][col - 1] == BLACK_PIECE &&
		board[row][col] == ' ')
	{
		int i = row + 1, j = col - 1;
		while (i <= BOARD_SIZE && j >= 0)
		{
			if (board[i][j] == WHITE_PIECE && board[i - 1][j + 1] != ' ')
			{
				return true;
			}
			++i;
			--j;
		}

		return false;
	}
	else if (turn == BLACK && board[row + 1][col - 1] == WHITE_PIECE &&
		board[row][col] == ' ')
	{
		int i = row + 1, j = col - 1;
		while (i <= BOARD_SIZE && j >= 0)
		{
			if (board[i][j] == BLACK_PIECE && board[i - 1][j + 1] != ' ')
			{
				return true;
			}
			++i;
			--j;
		}

		return false;
	}
	return false;
}

//====================================================================
// swap function to swap board values if a good move is made
//====================================================================
void swap(int turn, Board board, int row, int col)
{
	if (is_valid_position_in_NORTH_direction(turn, board, row, col))
	{
		for (int i = row - 1; i >= 0; --i)
		{
			board[i][col] = (turn ? WHITE_PIECE : BLACK_PIECE);
			if (board[i - 1][col] == (turn ? WHITE_PIECE : BLACK_PIECE)) break;
		}
	}
	if (is_valid_position_in_SOUTH_direction(turn, board, row, col))
	{
		for (int i = row + 1; i <= BOARD_SIZE; ++i)
		{
			board[i][col] = (turn ? WHITE_PIECE : BLACK_PIECE);
			if (board[i + 1][col] == (turn ? WHITE_PIECE : BLACK_PIECE)) break;
		}
	}
	if (is_valid_position_in_WEST_direction(turn, board, row, col))
	{
		for (int i = col - 1; i >= 0; --i)
		{
			board[row][i] = (turn ? WHITE_PIECE : BLACK_PIECE);
			if (board[row][i - 1] == (turn ? WHITE_PIECE : BLACK_PIECE)) break;
		}
	}
	if (is_valid_position_in_EAST_direction(turn, board, row, col))
	{
		for (int i = col + 1; i <= BOARD_SIZE; ++i)
		{
			board[row][i] = (turn ? WHITE_PIECE : BLACK_PIECE);
			if (board[row][i + 1] == (turn ? WHITE_PIECE : BLACK_PIECE)) break;
		}
	}
	if (is_valid_position_in_NORTHEAST_direction(turn, board, row, col))
	{
		int i = row - 1, j = col + 1;
		while (i >= 0 && j <= BOARD_SIZE)
		{
			board[i][j] = (turn ? WHITE_PIECE : BLACK_PIECE);
			if (board[i - 1][j + 1] == (turn ? WHITE_PIECE : BLACK_PIECE)) break;

			--i;
			++j;
		}
	}
	if (is_valid_position_in_SOUTHEAST_direction(turn, board, row, col))
	{
		int i = row + 1, j = col + 1;
		while (i <= BOARD_SIZE && j <= BOARD_SIZE)
		{
			board[i][j] = (turn ? WHITE_PIECE : BLACK_PIECE);
			if (board[i + 1][j + 1] == (turn ? WHITE_PIECE : BLACK_PIECE)) break;

			++i;
			++j;
		}
	}
	if (is_valid_position_in_NORTHWEST_direction(turn, board, row, col))
	{
		int i = row - 1, j = col - 1;
		while (i >= 0 && j >= 0)
		{
			board[i][j] = (turn ? WHITE_PIECE : BLACK_PIECE);
			if (board[i - 1][j - 1] == (turn ? WHITE_PIECE : BLACK_PIECE)) break;

			--i;
			--j;
		}
	}
	if (is_valid_position_in_SOUTHWEST_direction(turn, board, row, col))
	{
		int i = row + 1, j = col - 1;
		while (i <= BOARD_SIZE && j >= 0)
		{
			board[i][j] = (turn ? WHITE_PIECE : BLACK_PIECE);
			if (board[i + 1][j - 1] == (turn ? WHITE_PIECE : BLACK_PIECE)) break;

			++i;
			--j;
		}
	}

}

//====================================================================
// to check if the board has no playable moves left
//====================================================================
bool check_ended(Board board)
{
	int W_valid_row[100], W_valid_col[100], W_valid_len = 0;
	int B_valid_row[100], B_valid_col[100], B_valid_len = 0;
	int W = 1, B = 0;
	get_valid_positions(W, board, W_valid_row, W_valid_col, W_valid_len);
	get_valid_positions(B, board, B_valid_row, B_valid_col, B_valid_len);
	if (W_valid_len == 0 && B_valid_len == 0) return true;
	return false;
}

//===================================================================
// parse board[][] to find count to determine winner
//===================================================================
void find_winner(Board board)
{
	int BLACK_count = 0;
	int WHITE_count = 0;
	for (int row = 0; row < BOARD_SIZE; ++row)
	{
		for (int col = 0; col < BOARD_SIZE; ++col)
		{
			if (board[row][col] == WHITE_PIECE) ++WHITE_count;
			if (board[row][col] == BLACK_PIECE) ++BLACK_count;
		}
	}

	std::cout << "The game is ended."
		<< "\nBLACK - " << BLACK_count
		<< "\nWHITE - " << WHITE_count << std::endl;

	if (WHITE_count == BLACK_count) std::cout << "It's a draw.\n\n";
	else
	{
		std::cout << (BLACK_count < WHITE_count ? "WHITE" : "BLACK")
			<< " is the winner.\n\n";
	}

}