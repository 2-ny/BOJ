#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool CanGo(int x, int y, int r, int c, const vector<vector<bool>>& visited, const vector<string>& map) {
	return x >= 0 && x < r && y >= 0 && y < c && !visited[x][y] && map[x][y] == '.';
}

bool solution(int x, int y, int r, int c, vector<string>& map, int& count, vector<vector<bool>>& visited) {
	visited[x][y] = true;
	
	if(y == c - 1) {	// 파이프 완성한 경우
		count++;
		return true;
	}

	if(CanGo(x - 1, y + 1, r, c, visited, map)) {
		if(solution(x - 1, y + 1, r, c, map, count, visited)) {
			return true;
		}
	}

	if(CanGo(x, y + 1, r, c, visited, map)) {
		if(solution(x, y + 1, r, c, map, count, visited)) {
			return true;
		}		
	}

	if(CanGo(x + 1, y + 1, r, c, visited, map)) {
		if(solution(x + 1, y + 1, r, c, map, count, visited)) {
			return true;
		}
	}

	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int r, c;
	cin >> r >> c;

	vector<string> map(r);

	for(int i = 0; i < r; i++) {
		cin >> map[i];
	}

	vector<vector<bool>> visited(r, vector<bool>(c, false));
	int count = 0;

	for(int i = 0; i < r; i++) {
		solution(i, 0, r, c, map, count, visited);
	}

	cout << count << "\n";

	return 0;
}