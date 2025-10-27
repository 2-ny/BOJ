#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void solution(const string& s1, const string& s2) {
	int size1 = s1.length();
	int size2 = s2.length();

	// lcs[p][q]: s1의 p번째, s2의 q번째 문자까지의 lcs(1-based)
	vector<vector<int>> lcs(size1 + 1, vector<int>(size2 + 1, 0));

	for(int i = 1; i <= size1; i++) {
		for(int j = 1; j <= size2; j++) {
			if(s1[i - 1] == s2[j - 1]) {
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
			}
			else {
				lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
			}
		}
	}

	cout << lcs[size1][size2] << "\n";
}

int main() {
	string s1, s2;
	cin >> s1;
	cin >> s2;

	solution(s1, s2);

	return 0;
}