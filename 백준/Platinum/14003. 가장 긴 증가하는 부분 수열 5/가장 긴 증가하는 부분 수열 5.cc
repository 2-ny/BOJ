#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

void solution(int n, const vector<int>& sequence) {
	// lis_vec[k]: 길이가 k+1인 증가하는 수열의 마지막 원소 중 가장 작은 값
	vector<int> lis_vec;

	// lis_length[k]: sequence[k]가 마지막 원소인 증가하는 수열의 길이(1-based)
	vector<int> lis_length(n);

	for(int i = 0; i < n; i++) {
		int element = sequence[i];

		if(lis_vec.empty() || lis_vec.back() < element) {
			lis_vec.push_back(element);
			lis_length[i] = lis_vec.size();
		}
		else {
			auto it = lower_bound(lis_vec.begin(), lis_vec.end(), element);
			*it = element;
			lis_length[i] = (it - lis_vec.begin()) + 1;
		}
	}

	int max_length = lis_vec.size();
	cout << max_length << "\n";

	stack<int> lis_sequence;
	int current_length = max_length;

	for(int i = n - 1; i >= 0; i--) {
		if(lis_length[i] == current_length) {
			lis_sequence.push(sequence[i]);
			current_length--;
		}
		if(current_length == 0) {
			break;
		}
	}

	while(!lis_sequence.empty()) {
		cout << lis_sequence.top() << " ";
		lis_sequence.pop();
	}

	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<int> sequence(n);

	for(int i = 0; i < n; i++) {
		cin >> sequence[i];
	}

	solution(n, sequence);

	return 0;
}