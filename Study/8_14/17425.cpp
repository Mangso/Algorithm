// 약수의 합
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

vector<long long> dp;
vector<long long> f;

void make_f(int N) {
    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j += i) {
            f[j] += i;
        }
    }
}

void make_dp(int N) {
    dp[1] = 1;

    for (int i = 2; i <= N; i++) {
        dp[i] = dp[i - 1] + f[i];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;

    int max_N = -1;
    vector<int> V;
    while (T--) {
        int N;
        cin >> N;
        V.push_back(N);
        max_N = max(N, max_N);
    }

    f.resize(max_N + 1);
    dp.resize(max_N + 1);

    make_f(max_N);
    make_dp(max_N);

    for (auto& ele : V) {
        cout << dp[ele] << '\n';
    }

    return 0;
}