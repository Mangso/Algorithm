// 나이 순 정렬
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool Compare(const pair<int, string>& a, const pair<int, string>& b) {
    return a.first < b.first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<int, string>> members;
    for (int i = 0; i < N; i++) {
        int age;
        string name;
        cin >> age >> name;
        members.push_back({age, name});
    }

    stable_sort(members.begin(), members.end(), Compare);

    for (const auto& m : members) {
        cout << m.first << " " << m.second << '\n';
    }

    return 0;
}