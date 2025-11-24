#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	// min-heap
	priority_queue<long long, vector<long long>, greater<long long>> pq;

	for(int i = 0; i < n; i++) {
		long long temp;
		cin >> temp;

		pq.push(temp);
	}

	int count = 0;

	while(count < m) {
		long long a = pq.top();
		pq.pop();

		long long b = pq.top();
		pq.pop();
		
		long long sum = a + b;

		pq.push(sum);	// push a
		pq.push(sum);	// push b

		count++;
	}

	long long total_sum = 0;

	while(!pq.empty()) {
		total_sum += pq.top();
		pq.pop();
	}

	cout << total_sum << "\n";

	return 0;
}