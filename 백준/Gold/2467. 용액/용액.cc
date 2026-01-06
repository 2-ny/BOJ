#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const long long INF = 1e18;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  vector<long long> solutions(n);

  for(int i = 0; i < n; i++) {
    cin >> solutions[i];
  }

  if(solutions[n - 1] <= 0) {
    cout << solutions[n - 2] << " " << solutions[n - 1] << "\n";
    return 0;
  }
  else if(solutions[0] >= 0) {
    cout << solutions[0] << " " << solutions[1] << "\n";
    return 0;
  }

  long long left = 0;
  long long right = n - 1;

  long long min_sum = INF;
  long long result_left, result_right;
  
  while(left < right) {
    long long current_sum = solutions[left] + solutions[right];

    if(abs(current_sum) < abs(min_sum)) {
      min_sum = current_sum;
      result_left = left;
      result_right = right;
    }

    if(current_sum > 0) {
      right--;
    }
    else {
      left++;
    }
  }

  cout << solutions[result_left] << " " << solutions[result_right] << "\n";

  return 0;
  
}