#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

void solution(int n, int s, vector<int>& sequence) {
	int start = 0, end = 0;
	int sum = 0;
	int min_length = INF;

	while(true) {
		if(sum >= s) {
			min_length = min(min_length, end - start);
			sum -= sequence[start++];
		}
		else if(end == n) {
			// sum < s && 더 이상 뒤로 갈 곳 없음 -> 종료
			break;
		}
		else {
			// sum < s
			sum += sequence[end++];
		}
	}

	if(min_length == INF) {
		cout << 0 << "\n";
		return;
	}
	
	cout << min_length << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, s;
	cin >> n >> s;

	vector<int> sequence(n);

	for(int i = 0; i < n; i++) {
		cin >> sequence[i];
	}

	solution(n, s, sequence);

	return 0;
}