#include <iostream>
#include <string>
#include <vector>

using namespace std;

int board[9][9] = {};
bool rowCheck[9][10] = {};
bool colCheck[9][10] = {};
bool squareCheck[3][3][10] = {};

struct Point {
	int x, y;

	Point(int x, int y) : x(x), y(y) {};
};

void solve(int index, vector<Point>& blanks) {
	if(index == blanks.size()) {
		for(int i = 0; i < 9; i++) {
			for(int j = 0; j < 9; j++) {
				cout << board[i][j];
			}
			cout << "\n";
		}

		exit(0);
	}

	int r = blanks[index].x;
	int c = blanks[index].y;

	for(int num = 1; num <= 9; num++) {
		if(!rowCheck[r][num] && !colCheck[c][num] && !squareCheck[r / 3][c / 3][num]) {
			rowCheck[r][num] = true;
			colCheck[c][num] = true;
			squareCheck[r / 3][c / 3][num] = true;
			board[r][c] = num;

			solve(index + 1, blanks);

			rowCheck[r][num] = false;
			colCheck[c][num] = false;
			squareCheck[r / 3][c / 3][num] = false;
			board[r][c] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<Point> blanks;

	for(int i = 0; i < 9; i++) {
		string str;
		cin >> str;

		for(int j = 0; j < 9; j++) {
			int num = str[j] - '0';

			if(num != 0) {
				rowCheck[i][num] = true;
				colCheck[j][num] = true;
				squareCheck[i / 3][j / 3][num] = true;
				board[i][j] = num;
			}
			else {
				blanks.push_back(Point(i, j));
			}
		}
	}

	solve(0, blanks);

	return 0;
}