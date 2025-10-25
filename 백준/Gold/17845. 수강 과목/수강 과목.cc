#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solution(int n, int k, vector<int>& max_importance, const vector<pair<int, int>>& info) {
	for(int i = 0; i < k; i++) {	// 모든 과목 순회
		int impo = info[i].first;
		int time = info[i].second;

		for(int j = n; j >= time; j--) {
			max_importance[j] = max(max_importance[j], max_importance[j - time] + impo);
		}
	}

	cout << max_importance[n] << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	vector<int> max_importance(n + 1, 0);	// 최대 공부시간이 j일 때 최대 중요도
	vector<pair<int, int>> info(k); 		// {중요도, 필요한 공부시간}
	
	for(int i = 0; i < k; i++) {
		int impo, time;
		cin >> impo >> time;

		info[i].first = impo;	//중요도
		info[i].second = time;	// 필요한 공부시간
	}

	solution(n, k, max_importance, info);

	return 0;
}