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

    vector<int> answer;
    for (int i = 0; i < N; i++) {
        if (answer.empty() || answer.back() < V[i]) {
            answer.push_back(V[i]);
        } else {
            auto idx = lower_bound(answer.begin(), answer.end(), V[i]) - answer.begin();
            answer[idx] = V[i];
        }
    }

    cout << answer.size() << '\n';
    return 0;
}