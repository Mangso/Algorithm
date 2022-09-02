// N과 M(11)
#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> V(10);
vector<int> answer(10);
vector<bool> isused(10, false);

void func(int depth) {
    if (depth == M) {
        for (int i = 0; i < M; i++) {
            cout << answer[i] << " ";
        }
        cout << '\n';
        return;
    }

    int prev = 0;
    for (int i = 0; i < N; i++) {
        if (prev != V[i]) {
            answer[depth] = V[i];
            prev = V[i];
            func(depth + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> V[i];
    }

    sort(V.begin(), V.begin() + N);
    func(0);

    return 0;
}