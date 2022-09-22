// 구간 합 구하기 4
#include <bits/stdc++.h>

using namespace std;

long long dp[100005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<int> nums(N);
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    dp[1] = nums[0];

    for (int i = 1; i <= N; i++) {
        dp[i] = nums[i - 1] + dp[i - 1];
    }

    while (M--) {
        int i, j;
        cin >> i >> j;

        cout << dp[j] - dp[i - 1] << '\n';
    }

    // M 도 100000만 이니까 accumulate 쓰면 100000 * 100000 O(N^2) 네.

    // while (M--) {
    //     int i, j;
    //     cin >> i >> j;
    //     cout << accumulate(nums.begin() + i - 1, nums.begin() + j, 0) << '\n';
    // }

    return 0;
}