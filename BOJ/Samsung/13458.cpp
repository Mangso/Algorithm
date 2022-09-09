// 시험 감독
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<int> V(N);
    for (int i = 0; i < N; i++) {
        cin >> V[i];
    }

    int B, C;
    cin >> B >> C;

    long long answer = N;
    for (auto ele : V) {
        int tmp = ele - B;
        if (tmp > 0) {
            if (tmp % C == 0) {
                answer += (tmp / C);
            } else {
                answer += (tmp / C) + 1;
            }
        }
    }

    cout << answer;

    return 0;
}