// N과 M(3)
#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> V;
vector<int> answer;

void func(int depth) {
    if (depth == M) {
        for (int i = 0; i < M; i++) {
            cout << answer[i] << " ";
        }
        cout << '\n';
        return;
    }

    for (int i = 0; i < N; i++) {
        answer[depth] = V[i];
        func(depth + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    V.resize(N);
    answer.resize(M);
    for (int i = 0; i < N; i++) {
        V[i] = i + 1;
    }
    func(0);

    return 0;
}