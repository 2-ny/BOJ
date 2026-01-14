#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAX_WEIGHT = 15000;	// 30 * 500
const int MAX_NUM = 30;	

int n;
bool dp[MAX_NUM + 1][MAX_WEIGHT + 1];
int weight[MAX_NUM];

void solve() {
	dp[0][0] = true;

	for(int i = 0; i < n; i++) {
		int curr_weight = weight[i];

		for(int j = 0; j <= MAX_WEIGHT; j++) {
			if(dp[i][j]) {
				dp[i + 1][j] = true;

				if(j + curr_weight <= MAX_WEIGHT) {
					dp[i + 1][j + curr_weight] = true;
				}

				dp[i + 1][abs(j - curr_weight)] = true;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;

	for(int i = 0; i < n; i++) {
		cin >> weight[i];
	}

	solve();

	int marble_num;
	cin >> marble_num;

	for(int i = 0; i < marble_num; i++) {
		int marble_weight;
		cin >> marble_weight;

		if(marble_weight > MAX_WEIGHT || !dp[n][marble_weight]) {
			cout << "N" << " ";
		}
		else {
			cout << "Y" << " ";
		}
	}

	cout << "\n";

	return 0;
}