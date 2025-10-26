#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solution(int n, const vector<int>& sequence) {
	// lis_vec[k]: 길이가 k+1인 증가하는 부분 수열의 마지막 원소 중 가장 작은 값
	vector<int> lis_vec;

	for(auto element: sequence) {
		if(lis_vec.empty() || lis_vec.back() < element) {
			lis_vec.push_back(element);
		}
		else {
			auto it = lower_bound(lis_vec.begin(), lis_vec.end(), element);
			*it = element;
		}
	}

	cout << lis_vec.size() << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;

	while(cin >> n) {
		vector<int> sequence(n);

		for(int i = 0; i < n; i++) {
			cin >> sequence[i];
		}

		solution(n, sequence);
	}

	return 0;
}