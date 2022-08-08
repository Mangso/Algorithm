// N과 M(1)
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> V(N);

    iota(V.begin(), V.end(), 1);

    do {
        for (int i = 0; i < M; i++) {
            cout << V[i] << " ";
        }
        cout << '\n';

        reverse(V.begin() + M, V.end());

    } while (next_permutation(V.begin(), V.end()));

    return 0;
}