// 1, 2, 3 더하기
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;

    vector<int> dp(12, 0);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    dp[4] = 7;

    for (int i = 5; i < 11; i++) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }

    while (T--) {
        int n;
        cin >> n;
        cout << dp[n] << '\n';
    }

    return 0;
}