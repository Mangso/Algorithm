// 빈도 정렬
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool Compare(const pair<int, int>& a, const pair<int, int>& b) {
    return a.first > b.first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, C;
    cin >> N >> C;

    vector<pair<int, int>> v;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;

        bool flag = false;
        for (auto& ele : v) {
            if (ele.second == num) {
                flag = true;
                ele.first++;
                break;
            }
        }

        if (!flag) v.push_back({1, num});
    }

    stable_sort(v.begin(), v.end(), Compare);
    for (const auto& ele : v) {
        for (int i = 0; i < ele.first; i++) {
            cout << ele.second << ' ';
        }
    }
    return 0;
}