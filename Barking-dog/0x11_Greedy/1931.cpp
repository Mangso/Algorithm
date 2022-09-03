// 회의실 배정
#include <bits/stdc++.h>

using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<int, int>> V(N);
    for (int i = 0; i < N; i++) {
        cin >> V[i].first >> V[i].second;
    }

    sort(V.begin(), V.end(), compare);

    int end = 0;
    int cnt = 0;
    for (int i = 0; i < V.size(); i++) {
        if (V[i].first >= end) {
            end = V[i].second;
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}