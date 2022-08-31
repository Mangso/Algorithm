// 로또
#include <bits/stdc++.h>

using namespace std;

vector<int> answer(6);
vector<int> lotto(14);
int K;

void func(int start, int depth) {
    if (depth == 6) {
        for (int i = 0; i < 6; i++) {
            cout << answer[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = start; i < K; i++) {
        answer[depth] = lotto[i];
        func(i + 1, depth + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    while (true) {
        cin >> K;
        if (K == 0) break;

        for (int i = 0; i < K; i++) {
            cin >> lotto[i];
        }

        func(0, 0);
        cout << '\n';
    }

    return 0;
}