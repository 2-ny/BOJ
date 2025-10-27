#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void solution(const string& str1, const string& str2, const string& str3) {
	int size1 = str1.length();
	int size2 = str2.length();
	int size3 = str3.length();

	vector<vector<vector<int>>> lcs_length(size1 + 1, vector<vector<int>>(size2 + 1, vector<int>(size3 + 1, 0)));

	for(int i = 1; i <= size1; i++) {
		for(int j = 1; j <= size2; j++) {
			for(int k = 1; k <= size3; k++) {
				if(str1[i - 1] == str2[j - 1] && str2[j - 1] == str3[k - 1]) {
					lcs_length[i][j][k] = lcs_length[i - 1][j - 1][k - 1] + 1;
				}
				else {
					lcs_length[i][j][k] = max({lcs_length[i - 1][j][k], lcs_length[i][j - 1][k], lcs_length[i][j][k - 1]});
				}
			}
		}
	}

	cout << lcs_length[size1][size2][size3] << "\n";
}

int main() {
	string str1, str2, str3;

	cin >> str1 >> str2 >> str3;

	solution(str1, str2, str3);

	return 0;
}