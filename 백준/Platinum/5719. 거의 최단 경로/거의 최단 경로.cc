#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9;

struct State {
	int v, dist;

	State(int v, int dist) : v(v), dist(dist) {}
};

struct CompareState {
	bool operator() (const State& a, const State& b) {
		return a.dist > b.dist; 	// dist 기준 min-heap
	}
};

void remove_edges(int dest, int n, vector<vector<int>>& path, vector<vector<bool>>& is_removed) {
	queue<int> q;
	vector<bool> visited(n, false);

	q.push(dest);
	visited[dest] = true;

	while(!q.empty()) {
		int current = q.front();
		q.pop();

		for(auto prev : path[current]) {
			is_removed[prev][current] = true;
			
			if(!visited[prev]) {
				visited[prev] = true;
				q.push(prev);
			}
		}
	}
}

void find_shortest_path(int n, int m, int s, int d, const vector<vector<State>>& adj, vector<int>& distance, vector<vector<int>>& path, vector<vector<bool>>& is_removed) {

	priority_queue<State, vector<State>, CompareState> pq;

	distance[s] = 0;
	pq.push(State(s, 0));

	// 최단 경로 찾기
	while(!pq.empty()) {
		State current_state = pq.top();
		pq.pop();

		if(distance[current_state.v] < current_state.dist) {
			continue;
		}

		for(auto [next_v, next_dist] : adj[current_state.v]) {
			if(is_removed[current_state.v][next_v]) {
				continue;
			}

			int new_dist = distance[current_state.v] + next_dist;

			if(distance[next_v] > new_dist) {
				distance[next_v] = new_dist;
				pq.push(State(next_v, new_dist));
				path[next_v].clear();
				path[next_v].push_back(current_state.v);
			}
			else if(distance[next_v] == new_dist) {
				path[next_v].push_back(current_state.v);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while(true) {
		int n, m;
		cin >> n >> m;

		if(n == 0 && m == 0) {
			break;
		}

		int s, d;
		cin >> s >> d;

		vector<vector<State>> adj(n);

		for(int i = 0; i < m; i++) {
			int u, v, dist;
			cin >> u >> v >> dist;

			adj[u].push_back(State(v, dist));
		}

		vector<int> distance(n, INF);
		vector<vector<int>> path(n); 	// 최단 경로 저장
		vector<vector<bool>> is_removed(n, vector<bool>(n, false));

		find_shortest_path(n, m, s, d, adj, distance, path, is_removed);
			
		remove_edges(d, n, path, is_removed);

		fill(distance.begin(), distance.end(), INF); 	// INF로 초기화

		// 최단 경로 제외 후 최단 경로 찾기
		find_shortest_path(n, m, s, d, adj, distance, path, is_removed);

		if(distance[d] == INF) {
			// 거의 최단 경로 없는 경우
			cout << - 1 << "\n";
		}
		else {
			cout << distance[d] << "\n";
		}
	}

	return 0;
}