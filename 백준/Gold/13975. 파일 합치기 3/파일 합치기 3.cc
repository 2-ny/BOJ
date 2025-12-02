#include <iostream>
#include <queue>

using namespace std;

long long find_min_cost(int k, priority_queue<long long, vector<long long>, greater<long long>>& chapters) {
	long long min_cost = 0;

	while(chapters.size() > 1) {
		long long min1 = chapters.top();
		chapters.pop();

		long long min2 = chapters.top();
		chapters.pop();

		min_cost += (min1 + min2);

		chapters.push(min1 + min2);
	}

	return min_cost;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int test_case;
	cin >> test_case;

	while(test_case > 0) {
		int k;
		cin >> k;

		priority_queue<long long, vector<long long>, greater<long long>> chapters;	// chapter 크기 min-heap

		for(int i = 0; i < k; i++) {
			long long size;
			cin >> size;

			chapters.push(size);
		}

		long long min_cost = find_min_cost(k, chapters);

		cout << min_cost << "\n";

		test_case--;
	}
}