#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <string>

using namespace std;

const int INF = numeric_limits<int>::max();

void solution(const string& str) {
	int length = str.length();

	// isP[i][j]: i번째부터 j번째까지 팰린드롬 여부 저장(1-based)
	vector<vector<bool>> isP(length + 1, vector<bool>(length + 1, false));

	// L = 1, 2
	for(int i = 1; i <= length; i++) {
		isP[i][i] = true;
		
		// str은 0-based
		if(i < length && str[i - 1] == str[i]) {
			isP[i][i + 1] = true;
		}
	}

	// L = 3
	for(int L = 3; L <= length; L++) {	// L: 구간 길이
		for(int i = 1; i <= length - L + 1; i++) {	// i: 시작점
			int j = i + L - 1;	// j: 끝점
			// str은 0-based
			if(str[i - 1] == str[j - 1] && isP[i + 1][j - 1]) {
				isP[i][j] = true;
			}
		}
	}

	// min_count[i]: 1번째 부터 i번째까지 최소 분할 개수
	vector<int> min_count(length + 1);
	min_count[0] = 0;	// 초기값 설정

	for(int i = 1; i <= length; i++) {
		min_count[i] = INF;
		for(int j = 1; j <= i; j++) {
			if(isP[j][i]) {
				min_count[i] = min(min_count[i], min_count[j - 1] + 1);
			}
		}
	}

	cout << min_count[length] << "\n";
}                                               

int main() {
	string str;
	cin >> str;

	solution(str);

	return 0;
}