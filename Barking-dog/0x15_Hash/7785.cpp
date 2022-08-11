// 회사에 있는 사람
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    unordered_set<string> s;

    for (int i = 0; i < n; i++) {
        string name, log;
        cin >> name >> log;
        if (log == "enter") {
            s.insert(name);
        } else {
            s.erase(name);
        }
    }

    // unordered_set 은 sort 함수 못써서 벡터에 넣고 하기.
    vector<string> v(s.begin(), s.end());
    sort(v.begin(), v.end(), greater<string>());
    for (const auto& ele : v) {
        cout << ele << '\n';
    }

    return 0;
}