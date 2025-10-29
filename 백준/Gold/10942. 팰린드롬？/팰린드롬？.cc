#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void find_answers(int n, const vector<int>& numbers, const vector<pair<int, int>>& questions) {
	vector<vector<bool>> isP(n + 1, vector<bool>(n + 1, false));

	// base case
	for(int i = 1; i <= n; i++) {
		isP[i][i] = true;	// L = 1

		if(i < n && numbers[i] == numbers[i + 1]) {	// L = 2
			isP[i][i + 1] = true;
		}
	}

	// L >= 3
	for(int L = 3; L <= n; L++) {
		for(int i = 1; i <= n - L + 1; i++) {
			int j = i + L - 1;

			if(numbers[i] == numbers[j] && isP[i + 1][j - 1]) {
				isP[i][j] = true;
			}
		}
	}

	for(auto [start, end]: questions) {
		if(isP[start][end] == true) {
			cout << 1 << "\n";
		}
		else {
			cout << 0 << "\n";
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> numbers(n + 1);	// 1-based

	for(int i = 1; i <= n; i++) {
		cin >> numbers[i];
	}

	int m;
	cin >> m;

	vector<pair<int, int>> questions(m);

	for(int i = 0; i < m; i++) {
		int s, e;
		cin >> s >> e;

		questions[i] = {s, e};
	}

	find_answers(n, numbers, questions);

	return 0;
}