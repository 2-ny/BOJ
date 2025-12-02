#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void find_sequence_P(int n, vector<pair<int, int>>& A_with_index) {
	sort(A_with_index.begin(), A_with_index.end());	// A 원소 오름차순 정렬

	vector<int> sequence_P(n);

	for(int i = 0; i < n; i++) {
		int index = A_with_index[i].second;
		
		sequence_P[index] = i;
	}

	for(auto p: sequence_P) {
		cout << p << " ";
	}
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<pair<int, int>> A_with_index(n);	// {A 원소, 원소의 index}

	for(int i = 0; i < n; i++) {
		cin >> A_with_index[i].first;
		
		A_with_index[i].second = i;
	}

	find_sequence_P(n, A_with_index);

	return 0;
}