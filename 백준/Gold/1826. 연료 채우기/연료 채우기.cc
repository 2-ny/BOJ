#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Gas_Station {
	int distance, amount;
};

bool compare(const Gas_Station& a, const Gas_Station& b) {
	return a.distance < b.distance;
}

void solution(int n, int l, int p, vector<Gas_Station>& gas_stations) {
	sort(gas_stations.begin(), gas_stations.end(), compare);

	int current_amount = p;
	int index = 0;
	int count = 0;

	priority_queue<int> max_amount;	// 연료의 양 max-heap

	while(current_amount < l) {
		for(int i = index; i < n; i++) {
			if(gas_stations[i].distance <= current_amount) {
				max_amount.push(gas_stations[i].amount);
				index++;
			}
			else {
				break;
			}
		}

		if(max_amount.empty()) {
			// 마을 도착 불가
			cout << -1 << "\n";
			return;
		}

		current_amount += max_amount.top();
		max_amount.pop();
		
		count++;
	}

	cout << count << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<Gas_Station> gas_stations(n);

	for(int i = 0; i < n; i++) {
		cin >> gas_stations[i].distance >> gas_stations[i].amount;
	}

	int l, p;
	cin >> l >> p;

	solution(n, l, p, gas_stations);

	return 0;
}