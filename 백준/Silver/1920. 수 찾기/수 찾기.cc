#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	unordered_map<int, bool> map;

	for(int i = 0; i < n; i++) {
		int term;
		cin >> term;

		map[term] = 1;
	}

	int m;
	cin >> m;

	for(int i = 0; i < m; i++) {
		int number;
		cin >> number;

		if(map[number] == 1) {
			cout << 1 <<"\n";
		}
		else {
			cout << 0 << "\n";
		}
	}

	return 0;
}