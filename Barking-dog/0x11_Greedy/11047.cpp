// 동전 0
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<int> coins(N);
    for (int i = 0; i < N; i++) {
        cin >> coins[i];
    }

    sort(coins.begin(), coins.end(), greater<int>());

    int result = 0;
    for (auto c : coins) {
        if (K >= c) {
            int i = 1;
            for (i = 1;; i++) {
                if (c * i > K) break;
            }

            i--;
            K -= c * (i);
            result += i;
        }
    }

    cout << result;

    return 0;
}