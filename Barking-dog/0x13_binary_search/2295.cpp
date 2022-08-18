// 세수의 합
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<long long> v;
    for (int i = 0; i < N; i++) {
        long long u;
        cin >> u;
        v.push_back(u);
    }

    vector<long long> sum;
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            sum.push_back(v[i] + v[j]);
        }
    }

    sort(v.begin(), v.end());
    sort(sum.begin(), sum.end());

    bool flag = false;
    for (int i = N - 1; i >= 0; i--) {
        for (int j = i; j >= 0; j--) {
            auto exist = binary_search(sum.begin(), sum.end(), v[i] - v[j]);
            if (exist && !flag) {
                cout << v[i];
                flag = true;
                break;
            }
        }
    }

    return 0;
}