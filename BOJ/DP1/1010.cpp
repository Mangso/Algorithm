// 다리 놓기
#include <bits/stdc++.h>

using namespace std;

int dp[31][31];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for (int i = 1; i <= 30; i++)
        dp[1][i] = i;

    for (int i = 2; i <= 30; i++) {
        for (int j = i; j <= 30; j++) {
            for (int k = j - 1; k >= 1; k--) {
                dp[i][j] += dp[i - 1][k];
            }
        }
    }

    int T;
    cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M;
        cout << dp[N][M] << '\n';
    }

    return 0;
}