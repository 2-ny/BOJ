#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, h;
	cin >> n >> h;

	vector<int> bottom(h + 1, 0);	// 석순의 개수
	vector<int> top(h + 1, 0);	// 종유석의 개수

	for(int i = 0; i < n; i++) {
		int size;
		cin >> size;

		if(i % 2 == 0) {
			bottom[size]++;
		}

		else {
			top[size]++;
		}
	}

	for(int i = h - 1; i >= 1; i--) {
		bottom[i] += bottom[i + 1];
		top[i] += top[i + 1];
	}

	int min_obstacle = INF;
	int count = 0;

	for(int i = 1; i <= h; i++) {
		int total = bottom[i] + top[h - i + 1];

		if(total < min_obstacle) {
			min_obstacle = total;
			count = 1;
		}
		else if(total == min_obstacle) {
			count++;
		}
	}
	cout << min_obstacle << " " << count << "\n";

	return 0;
}