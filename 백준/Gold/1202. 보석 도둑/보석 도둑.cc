#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Jewel {
	int weight, value;
};

// 보석 무게 오름차순으로 정렬
bool compare(const Jewel& a, const Jewel& b) {
	return a.weight < b.weight;
}

void find_max_value(int n, int k, vector<Jewel>& jewels, vector<int>& bag_weight) {
	sort(jewels.begin(), jewels.end(), compare);
	sort(bag_weight.begin(), bag_weight.end());

	priority_queue<int> jewels_value;
	int jewels_num = 0;
	long long total_value = 0;

	for(int i = 0; i < k; i++) {
		for(int j = jewels_num; j < n; j++) {
			if(jewels[j].weight <= bag_weight[i]) {
				jewels_value.push(jewels[j].value);
				jewels_num++;
			}
			else {
				break;
			}
		}
		if(!jewels_value.empty()) {
			total_value += (long long) jewels_value.top();
			jewels_value.pop();
		}
	}

	cout << total_value << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	vector<Jewel> jewels(n);

	for(int i = 0; i < n; i++) {
		cin >> jewels[i].weight >> jewels[i].value;
	}

	vector<int> bag_weight(k);

	for(int i = 0; i < k; i++) {
		cin >> bag_weight[i];
	}

	find_max_value(n, k, jewels, bag_weight);

	return 0;
}