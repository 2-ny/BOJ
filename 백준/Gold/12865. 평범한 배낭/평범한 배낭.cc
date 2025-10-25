#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solution(int n, int k, vector<int>& max_value, vector<pair<int, int>>& info) {
	for(int i = 0; i < n; i++) {	// 모든 물건 순회
		int w = info[i].first;
		int v = info[i].second;

		for(int j = k; j >= w; j--) {
			max_value[j] = max(max_value[j], max_value[j - w] + v);
		}
	}

	cout << max_value[k] << "\n";
}

int main() {
	int n, k;
	cin >> n >> k;

	vector<int> max_value(k + 1, 0);	// max_value[j]: 무게 한도 j일 때 최대 가치
	vector<pair<int, int>> info(n); // {무게, 가치}

	for(int i = 0; i < n; i++) {
		int w, v;
		cin >> w >> v;

		info[i].first = w;
		info[i].second = v;
	}

	solution(n, k, max_value, info);

	return 0;
}