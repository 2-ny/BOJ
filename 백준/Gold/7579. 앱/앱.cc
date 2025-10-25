#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

void solution(int n, int m, const vector<int>& memories, const vector<int>& costs) {
	int total_cost = accumulate(costs.begin(), costs.end(), 0);

	// 비용 j를 사용해서 확보할 수 있는 최대 메모리 구하기
	vector<int> max_memory(total_cost + 1, 0);	

	for(int i = 0; i < n; i++) {
		int memory = memories[i];
		int cost = costs[i];

		for(int j = total_cost; j >= cost; j--) {
			max_memory[j] = max(max_memory[j], max_memory[j - cost] + memory);
		}
	}

	for(int cost = 0; cost <= total_cost; cost++) {
		if(max_memory[cost] >= m) {
			cout << cost << "\n";
			return;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<int> memories(n);
	vector<int> costs(n);
	
	for(int i = 0; i < n; i++) {
		int memory;
		cin >> memory;

		memories[i] = memory;
	}

	for(int i = 0; i < n; i++) {
		int cost;
		cin >> cost;

		costs[i] = cost;
	}

	solution(n, m, memories, costs);

	return 0;
}