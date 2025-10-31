#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int num_divide = 1000000000;

int count_sn(int length, int last_num, int mask, vector<vector<vector<int>>>& sn) {

	// base case
	if(length == 1) {
		int first_mask = 1 << last_num;
		if(last_num > 0 && mask == first_mask) {
			return 1;
		}
		else {
			return 0;
		}
	}

	// memoization
	if(sn[length][last_num][mask] != - 1) {
		return sn[length][last_num][mask];
	}

	if(!(mask & (1 << last_num))) {
		return 0;
	}

	sn[length][last_num][mask] = 0;
	int pre_mask = mask & ~(1 << last_num);
	long long pre_num = 0;
	if(last_num > 0) {
		// last_num 등장 전 이전 계단 수
		pre_num += count_sn(length - 1, last_num - 1, pre_mask, sn);
		// last_num 등장 한 이전 계단 수
		pre_num += count_sn(length - 1, last_num - 1, mask, sn);
	}

	if(last_num < 9) {
		// last_num 등장 전 이전 계단 수
		pre_num += count_sn(length - 1, last_num + 1, pre_mask, sn);
		// last_num 등장 한 이전 계단 수
		pre_num += count_sn(length - 1, last_num + 1, mask, sn);
	}

	sn[length][last_num][mask] = pre_num % num_divide;

	return sn[length][last_num][mask];
}

int main() {
	int n;
	cin >> n;

	int mask_num = 10;
	int init_mask = 1 << mask_num;

	// sn[i][j][mask]: 길이가 i, 마지막 숫자가 j인 계단 수(stairs number)의 개수(mask: 0 - 9까지 사용한 수 저장)
	vector<vector<vector<int>>> sn(n + 1, vector<vector<int>>(10, vector<int>(init_mask, -1)));

	long long total_sn = 0;
	int mask = (1 << mask_num) - 1;	// 0 - 9까지 모두 사용한 경우
	for(int j = 0; j <= 9; j++) {
		total_sn += count_sn(n, j, mask, sn);
	}
	cout << total_sn % num_divide << "\n";

	return 0;
}