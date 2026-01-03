#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

int main() {
	int v, e;
	cin >> v >> e;

	int start_node;
	cin >> start_node;

	// adj[u]: 노드 u의 인접 리스트
	// pair<int, int> = {비용, 도착점}
	vector<pair<int, int>> adj[v + 1];
	for(int i = 0; i < e; i++) {
		int u, v, w;			// u에서 v로 가는 가중치 w인 간선
		cin >> u >> v >> w;	
		adj[u].push_back({w, v});
	}

	// dist[u]: start_node -> u 경로 저장
	vector<int> dist(v + 1, INF);
	dist[start_node] = 0;

	// pair<int, int> = {-비용, 노드}
	priority_queue<pair<int, int>> pq;
	pq.push({0, start_node});

	while(!pq.empty()) {
		int current_dist = -pq.top().first;
		int current_node = pq.top().second;
		pq.pop();

		if(current_dist > dist[current_node]) {
			continue;
		}

		for(auto& edge : adj[current_node]) {
			int cost = edge.first;
			int next_node = edge.second;

			if(current_dist + cost < dist[next_node]) {
				dist[next_node] = current_dist + cost;
				pq.push({-dist[next_node], next_node});
			}
		}
	}

	for(int i = 1; i <= v; i++) {
		if(dist[i] == INF) {
			cout << "INF" << "\n";
		}
		else {
			cout << dist[i] << "\n";
		}
	}
	return 0;
}