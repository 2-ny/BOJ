#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9;

void find_min_dist(int start_node, int n, const vector<vector<pair<int, int>>>& adj, vector<int>& dist) {
    dist[start_node] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start_node});

    while(!pq.empty()) {
        int current_node = pq.top().second;
        int current_dist = pq.top().first;
        pq.pop();

        if(current_dist > dist[current_node]) {
            continue;
        }

        for(auto [next_dist, next_node]: adj[current_node]) {
            int new_dist = current_dist + next_dist;

            if(new_dist < dist[next_node]) {
                dist[next_node] = new_dist;
                pq.push({new_dist, next_node});
            }
        }
    }  
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, e;
    cin >> n >> e;

    // adj[u] = {{dist, v}, ...}
    vector<vector<pair<int, int>>> adj(n + 1);

    for(int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }
    
    int u, v;
    cin >> u >> v;

    vector<int> dist_from_1(n + 1, INF);
    vector<int> dist_from_u(n + 1, INF);
    vector<int> dist_from_v(n + 1, INF);

    find_min_dist(1, n, adj, dist_from_1);
    find_min_dist(u, n, adj, dist_from_u);
    find_min_dist(v, n, adj, dist_from_v);

    if(dist_from_u[v] != INF) {
        int min_dist = dist_from_u[v];

        if(dist_from_1[u] != INF && dist_from_v[n] != INF) {
            if(dist_from_1[v] != INF && dist_from_u[n] != INF) {
                min_dist += min(dist_from_1[u] + dist_from_v[n], dist_from_1[v] + dist_from_u[n]);
            }
            else {
                min_dist += dist_from_1[u] + dist_from_v[n];
            }
            
            cout << min_dist << "\n";
            return 0;
        }
        else if(dist_from_1[v] != INF && dist_from_u[n] != INF) {
            min_dist += dist_from_1[v] + dist_from_u[n];
            cout << min_dist << "\n";
            return 0;
        }
    }

    cout << - 1 << "\n";
    return 0;
}