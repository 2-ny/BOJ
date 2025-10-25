#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int max_hp = 99;	// 최대 사용 가능한 체력

void solution(int n, const vector<int>& lose_hp, const vector<int>& gain_delight) {
	vector<int> max_delight(max_hp + 1, 0);	// max_delight[j]: 최대 j만큼 체력 잃을 때 얻을 수 있는 최대 기쁨

	for(int i = 0; i < n; i++) {
		for(int j = max_hp; j >= lose_hp[i]; j--) {
			max_delight[j] = max(max_delight[j], max_delight[j - lose_hp[i]] + gain_delight[i]);
		}
	}

	cout << max_delight[max_hp] << "\n";
}

int main() {
	int n; 
	cin >> n;

	vector<int> lose_hp(n);	// 잃는 체력 저장
	vector<int> gain_delight(n);	// 얻는 기쁨 저장

	for(int i = 0; i < n; i++) {
		int hp;
		cin >> hp;
		lose_hp[i] = hp;
	}

	for(int i = 0; i < n; i++) {
		int delight;
		cin >> delight;
		gain_delight[i] = delight;
	}

	solution(n, lose_hp, gain_delight);
}