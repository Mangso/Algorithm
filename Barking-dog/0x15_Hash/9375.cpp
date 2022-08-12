// 패션왕 신해빈
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t, n;
    cin >> t;

    while (t--) {
        unordered_map<string, int> clothes;
        cin >> n;

        int cnt = 1;
        string a, b;
        for (int i = 0; i < n; i++) {
            cin >> a >> b;
            clothes[b]++;
        }

        for (auto &ele : clothes) {
            cnt *= ele.second + 1;
        }
        cout << cnt - 1 << '\n';
    }

    return 0;
}