// 랜선 자르기

#include <iostream>
#include <vector>

using namespace std;
int K, N;

using ll = long long;

bool Check(long long mid, const vector<int>& v) {
    long long cnt = 0;
    for (const auto& ele : v) {
        cnt += ele / mid;
    }
    return cnt >= N;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> K >> N;

    vector<int> v(K);
    for (int i = 0; i < K; i++) {
        cin >> v[i];
    }

    long long lo = 1;
    long long hi = ll(1e10) + 7;
    while (lo + 1 < hi) {
        long long mid = (lo + hi) / 2;
        if (Check(mid, v))
            lo = mid;
        else
            hi = mid;
    }

    cout << lo << '\n';
    return 0;
}