// 다음 순열

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    if (next_permutation(v.begin(), v.end())) {
        for (auto& ele : v) {
            cout << ele << " ";
        }
        cout << '\n';
    } else
        cout << -1 << '\n';

    return 0;
}