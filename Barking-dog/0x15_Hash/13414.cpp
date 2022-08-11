// 수강신청
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

bool Compare(const pair<string, int>& a, const pair<string, int>& b) {
    return a.second < b.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int K, L;
    cin >> K >> L;

    unordered_map<string, int> um;

    for (int i = 0; i < L; i++) {
        string num;
        cin >> num;

        if (um.find(num) != um.end()) {
            um.erase(num);
            um[num] = i;
        } else
            um[num] = i;
    }

    vector<pair<string, int>> v(um.begin(), um.end());

    sort(v.begin(), v.end(), Compare);

    int size = min(K, int(v.size()));
    for (int i = 0; i < size; i++) {
        cout << v[i].first << '\n';
    }

    return 0;
}