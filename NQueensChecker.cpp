#include "NQueensChecker.h"

#include <vector>
using namespace std;

static bool isValid(vector<vector<int>>& board, int x, int y) {

	// horizontal left
	for (int i = x - 1; i >= 0; i--) {
		if (board[y][i] != 0) return false;
	}

	// Up
	for (int i = y - 1; i >= 0; i--) {
		if (board[i][x] != 0) return false;
	}

	// Down
	for (int i = y + 1; i < board.size(); i++) {
		if (board[i][x] != 0) return false;
	}

	// Up-left
	for (int i = y - 1, i2 = x - 1; i >= 0 && i2 >= 0; i--, i2--) {
		if (board[i][i2] != 0) return false;
	}

	// Down-left
	for (int i = y + 1, i2 = x - 1; i < board.size() && i2 >= 0; i++, i2--) {
		if (board[i][i2] != 0) return false;
	}
	return true;
}

static void possibleHelper(vector<vector<int>>& board, int x, int y) {

	if (x >= board.size() || y >= board.size()) return;

	int yi = y;

	while (yi < board.size()) {

		// Move queen
		board[yi][x] = 1;

		
		if (isValid(board, x, yi)) {

			if (x + 1 < board.size())
				possibleHelper(board, x + 1, 0);
			else
				break;
			
		}
			

		board[yi][x] = 0;
		yi++;
	}

}

static bool possible(int n) {

	vector<vector<int>> board;
	
	// Initialize chess board
	for (int y = 0; y < n; y++) {
		board[y] = vector<int>();
		for (int x = 0; x < n; x++) {
			board[y][x] = 0;
		}
	}

	possibleHelper(board, 0, 0);

	int queensCount = 0;
	// Initialize chess board
	for (int y = 0; y < n; y++) {
		board[y] = vector<int>();
		for (int x = 0; x < n; x++) {
			if (board[y][x] != 0) queensCount++;
		}
	}

	return queensCount == n;
}