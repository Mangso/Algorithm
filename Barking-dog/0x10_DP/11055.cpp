// 가장 큰 증가 부분 수열
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<int> v;
    vector<int> dp;

    int n;
    for (int i = 0; i < N; i++) {
        cin >> n;
        v.push_back(n);
    }

    dp.assign(v.begin(), v.end());

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (v[j] < v[i]) {
                dp[i] = max(dp[i], dp[j] + v[i]);
            }
        }
    }
    cout << *max_element(dp.begin(), dp.end());

    return 0;
}