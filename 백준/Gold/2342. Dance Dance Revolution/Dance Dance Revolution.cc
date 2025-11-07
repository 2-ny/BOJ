#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int calc_cost(int x, int y) {
	if(x == 0) {
		return 2;
	}

	else if(x == y) {
		return 1;
	}

	else if(abs(x - y) == 2) {
		return 4;
	}

	else {
		return 3;
	}
}

void find_min_strength(int num, const vector<int>& order) {
	vector<vector<vector<int>>> min_strengths(num + 1, vector<vector<int>>(5, vector<int>(5, INF)));

	min_strengths[0][0][0] = 0;

	for(int index = 0; index < num; index++) {
		int step = order[index];
		
		for(int l = 0; l < 5; l++) {
			for(int r = 0; r < 5; r++) {
				if(min_strengths[index][l][r] == INF) {
					continue;
				}

				if(r == step) {
					min_strengths[index + 1][l][step] = min(min_strengths[index + 1][l][step], (min_strengths[index][l][r] + calc_cost(r, step)));
					continue;
				}
				
				else if(l == step) {
					min_strengths[index + 1][step][r] = min(min_strengths[index + 1][step][r], (min_strengths[index][l][r] + calc_cost(l, step)));
					continue;
				}
				
				min_strengths[index + 1][l][step] = min(min_strengths[index + 1][l][step], (min_strengths[index][l][r] + calc_cost(r, step)));

				min_strengths[index + 1][step][r] = min(min_strengths[index + 1][step][r], (min_strengths[index][l][r] + calc_cost(l, step)));
			}
		}
	}

	int min_strength = INF;
	int last_step = order[num - 1];

	for(int i = 0; i < 5; i++) {
		min_strength = min({min_strength, min_strengths[num][last_step][i], min_strengths[num][i][last_step]});
	}

	cout << min_strength << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int direction;
	vector<int> order;	

	while(true) {
		cin >> direction;

		if(direction == 0) {
			break;
		}

		order.push_back(direction);
	}

	int num = order.size();

	if(num == 0) {
		cout << 0 << "\n";

		return 0;
	}

	find_min_strength(num, order);

	return 0;
}