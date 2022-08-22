// 좋다
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool Check(vector<long long>& v) {
    for (auto ele : v) {
        if (ele != 0) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<long long> v;
    for (int i = 0; i < N; i++) {
        long long n;
        cin >> n;
        v.push_back(n);
    }

    if (Check(v)) {
        cout << N;
        return 0;
    }

    sort(v.begin(), v.end());

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            auto it = lower_bound(v.begin(), v.end(), v[i] - v[j]) - v.begin();

            if (it == i || it == j) continue;

            if (v[it] + v[j] == v[i]) {
                cnt++;
                break;
            }
        }
    }
    cout << cnt;

    return 0;
}