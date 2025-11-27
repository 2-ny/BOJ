#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void find_min_classRoom(int n, vector<pair<int, int>>& classes) {
	sort(classes.begin(), classes.end());	// 시작 시간 오름차순으로 정렬

	priority_queue<int, vector<int>, greater<int>> pq;	// 끝나는 시간 저장하는 min-heap

	pq.push(classes[0].second);	// 0번째 강의 종료 시간 저장

	int count = 1;	// 0번째 강의 포함

	for(int i = 1; i < n; i++) {
		int min_end_time = pq.top();
		if(classes[i].first < min_end_time) {
			count++;
		}
		else {
			pq.pop();
		}

		pq.push(classes[i].second);
	}

	cout << count << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	// {시작 시간, 끝나는 시간} 저장
	vector<pair<int, int>> classes(n);

	for(int i = 0; i < n; i++) {
		cin >> classes[i].first >> classes[i].second;
	}

	find_min_classRoom(n, classes);

	return 0;
}