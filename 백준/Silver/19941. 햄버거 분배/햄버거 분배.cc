#include <iostream>
#include <string>

using namespace std;

void solution(int n, int k, string& table) {
	int max_people = 0;
	
	for(int i = 0; i < n; i++) {
		if(table[i] == 'P') {
			for(int j = i - k; j <= i + k; j++) {
				if(j < 0 || j >= n) {
					continue;
				}

				if(table[j] == 'H') {
					table[j] = 'X';	// 햄버거 먹음 처리
					max_people++;
					break;
				}
			}
		}
	}

	cout << max_people << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	string table;
	cin >> table;

	solution(n, k, table);

	return 0;
}