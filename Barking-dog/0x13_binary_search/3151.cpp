// 합이 0
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

    vector<int> V(N);
    for (int i = 0; i < N; i++) {
        cin >> V[i];
    }
    sort(V.begin(), V.end());

    long long cnt = 0;
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            auto ub = upper_bound(V.begin() + j + 1, V.end(), -V[i] - V[j]);
            auto lb = lower_bound(V.begin() + j + 1, V.end(), -V[i] - V[j]);
            cnt += ub - lb;
        }
    }

    cout << cnt;
    return 0;
}
