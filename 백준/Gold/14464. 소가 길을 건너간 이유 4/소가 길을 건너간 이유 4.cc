#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Cow {
	int start, end;
};

bool compare(const Cow& a, const Cow& b) {
	if(a.start == b.start) {
		return a.end < b.end;
	}
	return a.start < b.start;
}

void solution(int c, int n, vector<int>& chickens, vector<Cow>& cows) {
	sort(cows.begin(), cows.end(), compare);	// 소 시작 시간 오름차순
	sort(chickens.begin(), chickens.end());	// 닭 오름차순

	priority_queue<int, vector<int>, greater<int>> min_end;
	int cows_count = 0;
	int cows_index = 1;	// 1-based

	for(int i = 1; i <= c; i++) {
		int current_chicken = chickens[i];

		for(int j = cows_index; j <= n; j++) {
			if(cows[j].start <= current_chicken) {
				min_end.push(cows[j].end);
				cows_index++;
			}
			else {
				break;
			}
		}

		while(!min_end.empty() && min_end.top() < current_chicken) {
			min_end.pop();
		}

		if(!min_end.empty()) {
			cows_count++;
			min_end.pop();
		}
	}

	cout << cows_count << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int c, n;
	cin >> c >> n;

	vector<int> chickens(c + 1);
	vector<Cow> cows(n + 1);

	for(int i = 1; i <= c; i++) {
		cin >> chickens[i];
	}

	for(int i = 1; i <= n; i++) {
		cin >> cows[i].start >> cows[i].end;
	}

	solution(c, n, chickens, cows);

	return 0;
}