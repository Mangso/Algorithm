// N과 M(1)

#include <algorithm>
#include <iostream>
#include <numeric>
#include <set>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> v(n);
    iota(v.begin(), v.end(), 1);

    // nPr 구하기
    do {
        for (int i = 0; i < m; i++) {
            cout << v[i] << " ";
        }
        cout << '\n';

        reverse(v.begin() + m, v.end());
    } while (next_permutation(v.begin(), v.end()));

    return 0;
}