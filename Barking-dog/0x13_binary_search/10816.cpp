// 숫자 카드 2
#include <algorithm>
#include <iostream>
#include <numeric>
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
        long long num;
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());
    int M;
    cin >> M;

    for (int i = 0; i < M; i++) {
        long long num;
        cin >> num;

        cout << upper_bound(v.begin(), v.end(), num) - lower_bound(v.begin(), v.end(), num) << ' ';
    }

    return 0;
}