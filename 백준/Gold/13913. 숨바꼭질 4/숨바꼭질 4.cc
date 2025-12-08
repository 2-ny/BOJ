#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX = 100001;

void bfs(int n, int k, vector<int>& time, vector<int>& parent) {
	queue<int> q;
	q.push(n);

	time[n] = 0;

	while(!q.empty()) {
		int current = q.front();
		q.pop();

		if(current == k) {
			return;
		}

		for(int next: {current - 1, current + 1, current * 2}) {
			if(next < 0 || next >= MAX) {
				continue;
			}

			if(time[next] == 0 && next != n) {
				time[next] = time[current] + 1;
				parent[next] = current;
				q.push(next);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	if(n == k) {
		cout << 0 << "\n";
		cout << n << "\n";
		return 0;
	}

	vector<int> time(MAX, 0);
	vector<int> parent(MAX);	// parent[next] = current

	bfs(n, k, time, parent);

	cout << time[k] << "\n";

	vector<int> path;
	int index = k;	// k -> n

	while(index != n) {
		path.push_back(index);
		index = parent[index];
	}
	path.push_back(n);	// 시작점 추가

	reverse(path.begin(), path.end());

	for(int p: path) {
		cout << p << " ";
	}
	cout << "\n";

	return 0;
}