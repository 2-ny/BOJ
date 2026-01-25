#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void bfs(int x, int y, int n, int h, vector<vector<int>>& map, vector<vector<bool>>& visited) {
  queue<pair<int, int>> q;
  q.push({x, y});
  visited[x][y] = true;

  while(!q.empty()) {
    int curr_x = q.front().first;
    int curr_y = q.front().second;
    q.pop();

    for(int i = 0; i < 4; i++) {
      int next_x = curr_x + dx[i];
      int next_y = curr_y + dy[i];

      if(next_x >= 0 && next_x < n && next_y >= 0 && next_y < n) {
        if(!visited[next_x][next_y] && map[next_x][next_y] > h) {
          visited[next_x][next_y] = true;
          q.push({next_x, next_y});
        }
      }
    }
  }
}

int count_region(int h, int n, vector<vector<int>>& map) {
  int count = 0;
  vector<vector<bool>> visited(n, vector<bool>(n, false));

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(!visited[i][j] && map[i][j] > h) {
        bfs(i, j, n, h, map, visited);
        count++;
      }
    }
  }

  return count;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  vector<vector<int>> map(n, vector<int>(n));
  int max_h = 0;
  
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> map[i][j];
      max_h = max(max_h, map[i][j]);
    }
  }

  int answer = 1;
  
  for(int i = 0; i < max_h; i++) {
    int curr = count_region(i, n, map);
    answer = max(answer, curr);
  }

  cout << answer << "\n";

  return 0;
}