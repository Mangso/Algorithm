// 좌표 압축
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

    vector<int> coordniates;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        coordniates.push_back(x);
    }

    vector<int> tmp = coordniates;
    sort(tmp.begin(), tmp.end());
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());

    for (const auto& x : coordniates) {
        auto it = lower_bound(tmp.begin(), tmp.end(), x) - tmp.begin();
        cout << it << ' ';
    }

    return 0;
}