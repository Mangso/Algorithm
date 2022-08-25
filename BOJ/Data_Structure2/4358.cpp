// 생태학
#include <iostream>
#include <map>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    map<string, int> um;
    string s;
    int total = 0;
    while (getline(cin, s)) {
        um[s]++;
        total++;
    }

    cout.setf(ios::fixed);
    cout.precision(4);
    for (auto ele : um) {
        cout << ele.first << " " << double(ele.second * 100) / double(total) << '\n';
    }

    return 0;
}