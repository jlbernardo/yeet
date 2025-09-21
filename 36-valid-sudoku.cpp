#include <algorithm>
#include <iostream>
#include <vector>
#include <set>


int main(void) {
	// valid
	std::vector<std::vector<char>> board = {
		{'5','3','.','.','7','.','.','.','.'},
		{'6','.','.','1','9','5','.','.','.'},
		{'.','9','8','.','.','.','.','6','.'},
		{'8','.','.','.','6','.','.','.','3'},
		{'4','.','.','8','.','3','.','.','1'},
		{'7','.','.','.','2','.','.','.','6'},
		{'.','6','.','.','.','.','2','8','.'},
		{'.','.','.','4','1','9','.','.','5'},
		{'.','.','.','.','8','.','.','7','9'}
	};

	// invalid square
	// std::vector<std::vector<char>> board = {
	// 	{'8','3','.','.','7','.','.','.','.'},
	// 	{'6','.','.','1','9','5','.','.','.'},
	// 	{'.','9','8','.','.','.','.','6','.'},
	// 	{'.','.','.','.','6','.','.','.','3'},
	// 	{'4','.','.','8','.','3','.','.','1'},
	// 	{'7','.','.','.','2','.','.','.','6'},
	// 	{'.','6','.','.','.','.','2','8','.'},
	// 	{'.','.','.','4','1','9','.','.','5'},
	// 	{'.','.','.','.','8','.','.','7','9'},
	// };

	// invalid row
	// std::vector<std::vector<char>> board = {
	// 	{'7','.','.','.','4','.','.','.','.'},
	// 	{'.','.','.','8','6','5','.','.','.'},
	// 	{'.','1','.','2','.','.','.','.','.'},
	// 	{'.','.','.','.','.','9','.','.','.'},
	// 	{'.','.','.','.','5','.','5','.','.'},
	// 	{'.','.','.','.','.','.','.','.','.'},
	// 	{'.','.','.','.','.','.','2','.','.'},
	// 	{'.','.','.','.','.','.','.','.','.'},
	// 	{'.','.','.','.','.','.','.','.','.'}
	// };

	// invalid column
	// std::vector<std::vector<char>> board = {
	// 	{'7','.','.','.','4','.','.','.','.'},
	// 	{'.','.','.','8','6','5','.','.','.'},
	// 	{'.','1','.','2','.','.','.','.','.'},
	// 	{'.','.','.','.','.','9','.','.','.'},
	// 	{'.','.','.','.','5','.','2','.','.'},
	// 	{'.','.','.','.','.','.','.','.','.'},
	// 	{'.','.','.','.','.','.','2','.','.'},
	// 	{'.','.','.','.','.','.','.','.','.'},
	// 	{'.','.','.','.','.','.','.','.','.'}
	// };

	int width = board[0].size();
	int height = board.size();

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (i == 0) {
				std::vector<char> column;
				for (int k = 0; k < height; k++) {
					char c = board[k][j];
					if (c != '.')
						column.push_back(c);
				}
				std::set<char> unique_elements(column.begin(), column.end());
				if (unique_elements.size() != column.size()) {
					printf("Invalid column\n");
					return 1;
				}
			}

			if (j == 0) {
				std::vector<char> row;
				for (int k = 0; k < width; k++) {
					char c = board[i][k];
					if (c != '.')
						row.push_back(c);
				}
				std::set<char> unique_elements(row.begin(), row.end());
				if (unique_elements.size() != row.size()) {
					printf("Invalid row\n");
					return 1;
				}
			}

			if (i % 3 == 0 && j % 3 == 0) {
				std::vector<int> square;
				for (int x = 0; x < 3; x++) {
					for (int y = 0; y < 3; y++) {
						char c = board[i + x][j + y];
						if (c != '.')
							square.push_back(c);
					}
				}
				std::set<char> unique_elements(square.begin(), square.end());
				if (unique_elements.size() != square.size()) {
					printf("Invalid square\n");
					return 1;
				}
			}
		}
	}

	printf("Valid\n");
}
