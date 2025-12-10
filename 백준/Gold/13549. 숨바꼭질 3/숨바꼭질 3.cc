#include <iostream>
#include <vector>
#include <deque>

using namespace std;

const int MAX = 100001;

void solution(int n, int k) {
	vector<int> time(MAX, -1);
	deque<int> dq;

	time[n] = 0;
	dq.push_back(n);	

	while(!dq.empty()) {
		int current = dq.front();
		dq.pop_front();

		if(current == k) {
			break;
		}
		
		// 순간이동 하는 경우
		int teleportation = current * 2;
		if(teleportation < MAX && time[teleportation] == -1) {
			time[teleportation] = time[current];
			dq.push_front(teleportation);
		}

		// 걷는 경우
		for(auto next: {current - 1, current + 1}) {
			if(next >= 0 && next < MAX && time[next] == -1) {
				time[next] = time[current] + 1;
				dq.push_back(next);
			}
		}
	}

	cout << time[k] << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	solution(n, k);

	return 0;
}