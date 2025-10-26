#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

const int INF = 10001;

void solution(int n, int k, const unordered_set<int>& values) {
	vector<int> min_num(k + 1, INF);
	min_num[0] = 0;

	for(auto value : values) {
		for(int j = value; j <= k; j++) {
			if(min_num[j - value] != INF) {
				min_num[j] = min(min_num[j], min_num[j - value] + 1);
			}
		}
	}

	if(min_num[k] == INF) {
		cout << -1 << "\n";
		return;
	}

	cout << min_num[k] << "\n";
}

int main() {
	int n, k;
	cin >> n >> k;

	unordered_set<int> values(n);

	for(int i = 0; i < n; i++) {
		int value;
		cin >> value;

		values.insert(value);
	}

	solution(n, k, values);

	return 0;
}