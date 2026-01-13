#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
	int weight, score;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<Item> items;

	for(int i = 0; i < n; i++) {
		int v, c, k;
		cin >> v >> c >> k;

		for(int j = 1; k > 0; j <<= 1) {
			int num = min(j, k);
			items.push_back({v * num, c * num});

			k -= num;
		}
	}

	vector<long long> max_score(m + 1, 0);

	for(auto item : items) {
		for(int i = m; i >= item.weight; i--) {
			max_score[i] = max(max_score[i], max_score[i - item.weight] + item.score);
		}
	}

	cout << max_score[m] << "\n";

	return 0;
}