#include <iostream>
#include <vector>

using namespace std;

struct Operation {
	int start_row, start_col, end_row, end_col;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));	// 1-based

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			int term;
			cin >> term;

			dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1] + term;
		}
	}

	vector<Operation> operations(m);	// 0-based

	for(int i = 0; i < m; i++) {
		cin >> operations[i].start_row >> operations[i].start_col >> operations[i].end_row >> operations[i].end_col;
	}

	for(int i = 0; i < m; i++) {
		int start_row = operations[i].start_row;
		int start_col = operations[i].start_col;
		int end_row = operations[i].end_row;
		int end_col = operations[i].end_col;

		int answer = dp[end_row][end_col] - dp[end_row][start_col - 1] - dp[start_row - 1][end_col] + dp[start_row - 1][start_col - 1];
		cout << answer << "\n";
	}

	return 0;
}