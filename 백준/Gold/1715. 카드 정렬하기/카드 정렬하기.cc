#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	priority_queue<int, vector<int>, greater<int>> pq;
	for(int i = 0; i < n; i++) {
		int bundle_size;
		cin >> bundle_size;

		pq.push(bundle_size);
	}

	if(n == 1) {
		cout << 0 << "\n";
		return 0;
	}

	int count = 0;

	while(pq.size() > 1) {
		int min_size_1 = pq.top();
		pq.pop();
		
		int min_size_2 = pq.top();
		pq.pop();

		count += min_size_1 + min_size_2;

		pq.push(min_size_1 + min_size_2);
	}

	cout << count << "\n";
	return 0;
	
}

