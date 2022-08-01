// 좌표 정렬하기 2
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool Compare(const pair<int, int>& a, const pair<int, int>& b) {
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

    vector<pair<int, int>> coord;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;

        coord.push_back({x, y});
    }

    sort(coord.begin(), coord.end(), Compare);

    for (const auto& ele : coord) {
        cout << ele.first << " " << ele.second << '\n';
    }

    return 0;
}