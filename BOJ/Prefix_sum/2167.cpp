// 2차원 배열의 합
#include <bits/stdc++.h>

using namespace std;

int board[310][310];
int dp[310][310];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> board[i][j];
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] + board[i][j] - dp[i - 1][j - 1];
        }
    }

    int K;
    cin >> K;

    int i, j, x, y;
    for (int t = 0; t < K; t++) {
        cin >> x >> y >> i >> j;
        cout << dp[i][j] - dp[i][y - 1] - dp[x - 1][j] + dp[x - 1][y - 1] << '\n';
    }

    return 0;
}