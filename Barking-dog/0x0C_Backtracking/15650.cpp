// N과 M (2)
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

    vector<int> V(N, 1);
    for (int i = 0; i < M; i++) {
        V[i] = 0;
    }

    do {
        for (int i = 0; i < N; i++) {
            if (!V[i])
                cout << i + 1 << " ";
        }
        cout << '\n';

    } while (next_permutation(V.begin(), V.end()));

    return 0;
}