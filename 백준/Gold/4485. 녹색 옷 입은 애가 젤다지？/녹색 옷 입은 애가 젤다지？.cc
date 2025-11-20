#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9;

struct Info {
	int x, y, cost;

	bool operator>(const Info& other) const {
		return cost > other.cost;
	}
};

void find_min_lost_cost(int n, int test_num, const vector<vector<int>>& map) {
	vector<vector<int>> lost_cost(n, vector<int>(n, INF));
	lost_cost[0][0] = 0;

	priority_queue<Info, vector<Info>, greater<Info>> pq;
	pq.push({0, 0, 0});

	int dx[4] = {0, 1, 0, -1};
	int dy[4] = {1, 0, -1, 0};

	while(!pq.empty()) {
		int current_x = pq.top().x;
		int current_y = pq.top().y;
		int current_cost = pq.top().cost;

		pq.pop();

		if(current_cost > lost_cost[current_x][current_y]) {
			continue;
		}

		for(int i = 0; i < 4; i++) {
			int next_x = current_x + dx[i];
			int next_y = current_y + dy[i];

			if(next_x >= 0 && next_x < n && next_y >= 0 && next_y < n) {
				int next_cost = current_cost + map[next_x][next_y];
				if(next_cost < lost_cost[next_x][next_y]) {
					lost_cost[next_x][next_y] = next_cost;
					pq.push({next_x, next_y, next_cost});
				}
			}
		}
	}

	cout << "Problem " << test_num << ": " << lost_cost[n - 1][n - 1] + map[0][0] << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int test_num = 1;

	while(true) {
		int n;
		cin >> n;

		if(n == 0) {
			break;
		}

		vector<vector<int>> map(n, vector<int>(n));

		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				cin >> map[i][j];
			}
		}

		find_min_lost_cost(n, test_num, map);

		test_num++;
	}

	return 0;
}