#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> a(n);
    vector<long long> sum(n); // 누적 합 배열
    long long total = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        total += a[i];
        if (i == 0) sum[i] = a[i];
        else sum[i] = sum[i - 1] + a[i];
    }

    long long max_honey = 0;

    // Case 1: 벌통이 맨 오른쪽 (오른쪽 고정)
    // 벌 1: 맨 왼쪽(0) 고정
    // 벌 2: i (1 ~ N-2) 이동
    for (int i = 1; i < n - 1; i++) {
        // 벌1: (전체 - 시작점 - 벌2위치)
        // 벌2: (전체 - 벌2위치까지 누적합)
        long long current = (total - a[0] - a[i]) + (total - sum[i]);
        max_honey = max(max_honey, current);
    }

    // Case 2: 벌통이 맨 왼쪽 (왼쪽 고정)
    // 벌 1: 맨 오른쪽(N-1) 고정
    // 벌 2: i (1 ~ N-2) 이동
    for (int i = 1; i < n - 1; i++) {
        // 벌1: (전체 - 시작점 - 벌2위치)
        // 벌2: (벌2위치까지 누적합 - 벌2위치)
        long long current = (total - a[n - 1] - a[i]) + (sum[i] - a[i]);
        max_honey = max(max_honey, current);
    }

    // Case 3: 벌통이 가운데 (i)
    // 벌 1: 맨 왼쪽(0) 고정
    // 벌 2: 맨 오른쪽(N-1) 고정
    for (int i = 1; i < n - 1; i++) {
        // 벌1: 0 -> i (S[i] - A[0])
        // 벌2: N-1 -> i (Total - S[i-1] - A[N-1])
        // 정리하면: Total - A[0] - A[N-1] + A[i]
        long long current = total - a[0] - a[n - 1] + a[i];
        max_honey = max(max_honey, current);
    }

    cout << max_honey << "\n";

    return 0;
}