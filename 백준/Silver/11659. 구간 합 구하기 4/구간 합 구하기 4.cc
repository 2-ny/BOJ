#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<long long> s(n + 1, 0);	// 1-based, 누적합 저장

	for(int i = 1; i <= n; i++) {
		int num;
		cin >> num;

		s[i] = s[i - 1] + num;
	}

	for(int i = 0; i < m; i++) {
		int start, end;
		cin >> start >> end;

		cout << s[end] - s[start - 1] << "\n";
	}

	return 0;
}