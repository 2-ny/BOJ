#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Line {
	int start, end;
};

bool compare(const Line& a, const Line& b) {
	if(a.start == b.start) {
		return a.end < b.end;
	}

	return a.start < b.start;	// 시작점 오름차순으로 정렬
}

void solution(int n, vector<Line>& lines) {	
	sort(lines.begin(), lines.end(), compare);	// 시작점을 기준으로 오름차순 정렬

	// 종료점 min-heap
	priority_queue<int, vector<int>, greater<int>> min_end;

	int max_lines = 0;

	for(int i = 0; i < n; i++) {
		int start = lines[i].start;
		int end = lines[i].end;

		min_end.push(end);

		while(!min_end.empty()) {
			if(min_end.top() <= start) {
				// 현재 선분과 겹치지 않을 경우 -> pop
				min_end.pop();
			}
			else {
				break;
			}
		}

		max_lines = max(max_lines, (int)min_end.size());
	}

	cout << max_lines << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<Line> lines(n);

	for(int i = 0; i < n; i++) {
		cin >> lines[i].start >> lines[i].end;
	}

	solution(n, lines);

	return 0;
}