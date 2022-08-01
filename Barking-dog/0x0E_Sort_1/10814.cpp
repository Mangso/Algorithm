#include <algorithm>
#include <iostream>
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

    vector<pair<int, string>> v;
    for (int i = 0; i < N; i++) {
        int age;
        string name;
        cin >> age >> name;

        v.push_back({age, name});
    }

    // 가입한 순으로 한 줄에 한명씩 이므로 stable_sort 써야함.
    stable_sort(v.begin(), v.end(), Compare);
    for (const auto& ele : v) {
        cout << ele.first << " " << ele.second << '\n';
    }

    return 0;
}
